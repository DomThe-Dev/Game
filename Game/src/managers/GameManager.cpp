#include "GameManager.h"
#include <spdlog/sinks/basic_file_sink.h>
#include "../utils/QueueLoop.h"


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

	m_config_.Load("assets/config/config.json");

	window_.create(
		sf::VideoMode({ m_config_.GetWindowConfig().width, m_config_.GetWindowConfig().height }), 
		"Game"
	);

	dbg_wndw.Init(window_);

	scene_manager_.Init("assets/scenes");

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
		ImGui::SFML::Update(window_, delta_time);

		float fps = 1.0f / delta_time.asSeconds();

		ImGui::Begin("Debug Menu");
		ImGui::Text("FPS: %.1f", fps);
		ImGui::Text("Frame Time: %.3f ms", delta_time.asMicroseconds() / 1000.f);
		ImGui::Text("Window Size: %dx%d", window_.getSize().x, window_.getSize().y);
		ImGui::Text("VSync: %s", m_config_.GetWindowConfig().vsync ? "On" : "Off");

		bool vsync = m_config_.GetWindowConfig().vsync;
		if (ImGui::Checkbox("VSync", &vsync))
		{
			m_config_.GetWindowConfig().vsync = vsync;
			window_.setVerticalSyncEnabled(vsync);
		}

		if (ImGui::Button("Save Config"))
		{
			m_config_.Save();
			spdlog::info("Configuration saved");
		}

		ImGui::End();

		// Render
		window_.clear(sf::Color::Black);
		ImGui::SFML::Render(window_);
		window_.display();
	}
	ImGui::SFML::Shutdown(); // Clean up
}

void GameManager::Update()
{

}
