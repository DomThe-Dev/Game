#pragma once
#include "ResourceManager.h"
#include "SceneManager.h"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

class GameManager
{
public:
	void Start();
private:
	ResourceManager m_resource_;

	sf::Clock clock_;
	sf::Window window_;

	void Update();
};