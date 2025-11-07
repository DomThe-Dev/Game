#include "GameManager.h"
#include <spdlog/sinks/basic_file_sink.h>


GameManager::GameManager()
{
	spdlog::set_default_logger(spdlog::basic_logger_mt("default", "logs/game_log.log"));
}

GameManager::~GameManager()
{
}

void GameManager::Start()
{
	sf::Clock clock; // Keep track of delta time. Can be declared here as all the game is here.

	// Load managers
	m_config_.Load("assets/config/config.json");

	window_.create(
		sf::VideoMode({ m_config_.GetWindowConfig().width, m_config_.GetWindowConfig().height }), 
		"Game"
	);

	dbg_wndw.Init(window_);

	while (window_.isOpen())
	{
		sf::Time delta_time = clock.restart();

		while (const std::optional event = window_.pollEvent())
		{
			dbg_wndw.ProcessEvent(window_, *event);
			// "close requested" event: we close the window
			if (event->is<sf::Event::Closed>())
				window_.close();
		}

		// Process Input

		// Update

		// Render
		window_.clear(sf::Color::Black);
		dbg_wndw.Render(window_);
		window_.display();
	}
	dbg_wndw.Shutdown();
}

void GameManager::Update()
{
}
