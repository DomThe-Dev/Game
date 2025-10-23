#include "GameManager.h"
#include <spdlog/sinks/basic_file_sink.h>

GameManager::GameManager()
{
	spdlog::set_default_logger(spdlog::basic_logger_mt("default", "logs/game_log.log"));
}

void GameManager::Start()
{
	sf::Clock clock; // Keep track of delta time. Can be declared here as all the game is here.
	while (true)
	{
		break;
		// Process Input

		// Update

		// Render
	}
}

void GameManager::Update()
{
}
