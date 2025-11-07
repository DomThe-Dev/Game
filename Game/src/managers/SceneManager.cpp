#include "SceneManager.h"
void SceneManager::AddScene(GameState state, std::shared_ptr<Scene> scene)
{
	scenes_[state].push_back(scene); // Add scene to the vector for the given state
}
void SceneManager::ChangeScene(GameState new_state, size_t scene_index)
{
	auto it = scenes_.find(new_state); // Find scenes for the new state
	if(it == scenes_.end() || it->second.empty())  
	{
		return; // No scenes for this state
	}
	if(scene_index >= it->second.size())
	{
		scene_index = 0; // Default to first scene if index out of bounds
	}

	if(current_scene_.scene_)
	{
		current_scene_.scene_->Exit(); // Exit current scene
	}
	current_scene_.state_ = new_state; 
	current_scene_.scene_ = it->second[scene_index]; // Set new current scene
	current_scene_.scene_->Enter(); // Enter new scene
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