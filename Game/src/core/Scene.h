#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "SceneTypes.h"
class Scene
{
public:
	Scene(const SceneData& data) : id_(data.id_), name_(data.display_name_), state_(data.state_) {}
	virtual ~Scene() = default;

	virtual void Enter() = 0;
	virtual void Exit() = 0;
	virtual void Pause() = 0; 
	virtual void Resume() = 0;

	virtual void HandleInput(sf::RenderWindow& window) = 0;
	virtual void Update(float delta_time) = 0;
	virtual void Render(sf::RenderWindow& window) = 0;

	const std::string& GetName() const { return name_; }
	int GetID() const { return id_; }
	GameState GetState() const { return state_; }
private:
	int id_;
	std::string name_;
	GameState state_;
};

