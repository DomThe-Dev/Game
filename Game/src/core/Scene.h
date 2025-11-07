#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
class Scene
{
public:
	virtual ~Scene() = default;

	virtual void Enter() = 0; // Called when scene is active - initialize stuff here
	virtual void Exit() = 0; // Called when scene is no longer active - cleanup stuff here
	virtual void Pause() { } // Called when scene is paused - pushed over by another scene
	virtual void Resume() { } // Called when scene is resumed - popped back to top

	virtual void HandleInput(sf::RenderWindow& window) = 0;
	virtual void Update(float delta_time) = 0;
	virtual void Render(sf::RenderWindow& window) = 0;
	
private:
};

