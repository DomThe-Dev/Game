#pragma once
#include <memory>
#include <unordered_map>
#include <stack>
#include "../core/Scene.h"

enum GameState // 
{
	PLAYING,
	PAUSED,
	MAIN_MENU,
	GAME_OVER
};

struct ActiveScene
{
	GameState state_;
	std::shared_ptr<Scene> scene_ = nullptr;
};

class SceneManager
{
public:
	SceneManager() = default;

	// For switching and adding scenes
	void AddScene(GameState state, std::shared_ptr<Scene> scene);
	void ChangeScene(GameState new_state, size_t scene_index);

	// For overlaying scenes
	void PushScene(std::shared_ptr<Scene> scene);
	void PopScene();

	template<typename Func>
	void ForActiveScene(Func func) // Calls update, render and handleInput functions with the active scene (top of stack or current)
	{
		if(current_scene_.scene_ == nullptr)
		{
			return;
		}

		if(!scene_stack_.empty()) 
		{
			func(scene_stack_.top().get());
		}
		else 
		{
			func(current_scene_.scene_.get());
		}
	}
	void HandleInput(sf::RenderWindow& window);
	void Update(float delta_time);
	void Render(sf::RenderWindow& window);

	GameState GetActiveGameState() const { return current_scene_.state_; }
private:
	std::unordered_map<GameState, std::vector<std::shared_ptr<Scene>>> scenes_; // Map of game states to their scenes
	std::stack<std::shared_ptr<Scene>> scene_stack_; // Stack for overlay scenes

	ActiveScene current_scene_;
};

