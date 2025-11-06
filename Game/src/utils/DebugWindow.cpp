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

void DebugWindow::Update(float dt)
{
	// Calculate FPS
	fps_history_.Enqueue(1.f / dt);
}

float DebugWindow::FPSAverage()
{
	return 0.0f;
}

