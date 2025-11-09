#include "SceneManager.h"
void SceneManager::Init(const std::string& scene_folder) 
{
	namespace fs = std::filesystem;

	for (auto& file : fs::directory_iterator(scene_folder)) // iterate through all files in the scene folder
	{
		if(file.path().extension() == ".json") 
		{
			try
			{
				std::ifstream in(file.path());
				nlohmann::json scene_json;
				in >> scene_json;

				SceneData data;
				data.id_ = scene_json["scene_info"]["id"];
				data.display_name_ = scene_json["scene_info"]["display_name"];
				data.state_ = static_cast<GameState>(scene_json["scene_info"]["state"]);

				std::shared_ptr<Scene> scene = SceneFactory::CreateScene(data, scene_json);

				AddScene(data.id_, scene);
			}
			catch(const std::exception& e) 
			{
				throw std::runtime_error("Failed to load scene from " + file.path().string() + ": " + e.what());
			}
		}
	}
	if(!scenes_.empty()) 
	{
		ChangeScene(scenes_.begin()->first);
	}
}
void SceneManager::AddScene(int id, std::shared_ptr<Scene> scene)
{
	if(scenes_.find(id) != scenes_.end())
	{
		return; // Scene with this ID already exists
	}
	scenes_[id] = scene;
}
void SceneManager::ChangeScene(int id)
{
	auto it = scenes_.find(id);
	if (it == scenes_.end()) 
	{
		return; // Scene not found
	}

	if(current_scene_.scene_) 
	{
		current_scene_.scene_->Exit();
	}

	current_scene_.scene_id_ = id;
	current_scene_.scene_ = it->second;
	if(!current_scene_.scene_) 
	{
		return;
	}
	current_scene_.scene_name_ = current_scene_.scene_->GetName(); // Add to scene class
	current_scene_.scene_->Enter();
}

void SceneManager::PushScene(std::shared_ptr<Scene> scene)
{
	if(!scene_stack_.empty()) 
	{
		scene_stack_.top()->Pause(); // Pause the current top scene
	} 
	else if(current_scene_.scene_)
	{
		current_scene_.scene_->Pause(); // Pause the current active scene
	}

	scene_stack_.push(scene); // Push new scene onto stack
	scene->Enter(); // Enter the new scene
}
void SceneManager::PopScene()
{
	if (!scene_stack_.empty())
	{
		scene_stack_.top()->Exit(); // Exit the top scene
		scene_stack_.pop();

		if(!scene_stack_.empty())
		{
			scene_stack_.top()->Resume(); // Resume the new top scene
		}
		else if(current_scene_.scene_)
		{
			current_scene_.scene_->Resume(); // Resume the active scene
		}
	}
}

// forward calls Update, Render, HandleInput calls to currently active scene
void SceneManager::HandleInput(sf::RenderWindow& window)
{
	ForActiveScene([&](Scene* scene) { scene->HandleInput(window); }); 
}
void SceneManager::Update(float delta_time)
{ 
	ForActiveScene([&](Scene* scene) { scene->Update(delta_time); });
}
void SceneManager::Render(sf::RenderWindow& window)
{
	ForActiveScene([&](Scene* scene) { scene->Render(window); });
}