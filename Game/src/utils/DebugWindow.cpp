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

void DebugWindow::BeginFrame(sf::RenderWindow& window, const sf::Time& delta_time)
{

}

void DebugWindow::Render(sf::RenderWindow& window_)
{
	ImGui::SFML::Render(window_);
}