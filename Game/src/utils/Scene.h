#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
class Scene
{
public:
	virtual ~Scene() = default;

	virtual void Enter() = 0;
	virtual void Exit() = 0;

	virtual void Update(float delta_time) = 0;
	virtual void Render(sf::RenderWindow& window) = 0;

private:
};

