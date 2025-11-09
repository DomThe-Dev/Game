#pragma once
#include <memory>
#include <unordered_map>
#include <stack>
#include <json.hpp>
#include <filesystem>
#include <fstream>
#include "../core/SceneTypes.h"
#include "../core/SceneFactory.h"
#include "../core/Scene.h"

struct ActiveScene
{
	GameState scene_state_;
	int scene_id_ = 0;
	std::string scene_name_;
	std::shared_ptr<Scene> scene_ = nullptr;
	SceneData scene_data_;
};
class SceneManager
{
public:
	SceneManager() = default;

	void Init(const std::string& scene_folder);


	// For switching and adding scenes
	void AddScene(int id, std::shared_ptr<Scene> scene);
	void ChangeScene(int id);
	// For overlaying scenes
	void PushScene(std::shared_ptr<Scene> scene);
	void PopScene();

	void HandleInput(sf::RenderWindow& window);
	void Update(float delta_time);
	void Render(sf::RenderWindow& window);

	template<typename Func>
	void ForActiveScene(Func func) // Calls update, render and handleInput functions with the active scene (top of stack or current)
	{
		if (current_scene_.scene_ == nullptr)
		{
			return;
		}

		if (!scene_stack_.empty())
		{
			func(scene_stack_.top().get());
		}
		else
		{
			func(current_scene_.scene_.get());
		}
	}

	GameState GetActiveGameState() const { return current_scene_.scene_state_; }
	int GetActiveSceneID() const { return current_scene_.scene_id_; }
	const std::unordered_map<int, std::shared_ptr<Scene>>& GetScenes() const { return scenes_; }

private:
	std::unordered_map<int, std::shared_ptr<Scene>> scenes_; // Map of game states to their scenes
	std::stack<std::shared_ptr<Scene>> scene_stack_; // Stack for overlay scenes
	ActiveScene current_scene_;
};

