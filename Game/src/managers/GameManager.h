#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "../utils/Common.h"
#include "ConfigManager.h"
#include "SceneManager.h"

class GameManager
{
public:
	GameManager();
	~GameManager();

	void Start();
private:
	ConfigManager m_config_;

	sf::Clock clock_;
	sf::Window window_;

	void Update();
};