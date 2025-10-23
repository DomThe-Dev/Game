#pragma once
#include "ResourceManager.h"
#include "SceneManager.h"
#include "SFML/System.hpp"

class GameManager
{
public:
	void Start();
private:
	sf::Clock clock_;

	void Update();
};