#include "DebugWindow.h"

void DebugWindow::Init(sf::RenderWindow& window)
{
	if (ImGui::SFML::Init(window))
	{
		spdlog::info("Initialised SFML ImGUI SFML.");
	}
	else 
	{
		spdlog::error("Could not initialise SFML ImGui.");
		return;
	}
}

void DebugWindow::ProcessEvent(sf::RenderWindow& window, const sf::Event& event)
{
	ImGui::SFML::ProcessEvent(window, event);
}

void DebugWindow::Shutdown()
{
	ImGui::SFML::Shutdown();
}

void DebugWindow::Update(sf::RenderWindow& window, sf::Time delta_time)
{
	elapsed_time_ += delta_time.asSeconds();

	ImGui::SFML::Update(window, delta_time);
	fps_tracker_.Update(delta_time);

	if (elapsed_time_ >= 1.f) // Runs every second
	{
		fps_tracker_.UpdateStats(delta_time);
		elapsed_time_ = 0.f;
	}
}

void DebugWindow::Render(sf::RenderWindow& window_)
{
	ImGui::Begin("Debug Window");
	ImGui::Text("FPS: %.1f", fps_tracker_.GetAverageFps());
	ImGui::Text("Lows: %.1f", fps_tracker_.GetLowsFps());
	ImGui::Text("Highs: %.1f", fps_tracker_.GetHighsFps());
	ImGui::Text("Frame Time: %.3f ms", fps_tracker_.GetFrameTimeMs());
	ImGui::Separator();
	ImGui::Text("Window Size: %dx%d", window_.getSize().x, window_.getSize().y);
	ImGui::End();

	// Render to the screen
	ImGui::SFML::Render(window_);
}
