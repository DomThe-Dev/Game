#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <imgui.h>
#include <imgui-SFML.h>

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
	sf::RenderWindow window_;

	void Update();
};