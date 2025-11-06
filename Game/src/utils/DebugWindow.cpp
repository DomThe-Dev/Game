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

void DebugWindow::Update(sf::RenderWindow& window, sf::Time& delta_time)
{
	ImGui::SFML::Update(window, delta_time);
	float dt = delta_time.asSeconds();
	total_time_ += dt;
	// Calculate FPS
	float new_fps = 1.f / dt;
	fps_history_.Enqueue(new_fps);
	if (new_fps < fps_low_ || fps_low_ == 0.f)
		fps_low_ = new_fps;
	if (new_fps > fps_high_)
		fps_high_ = new_fps;

	if (total_time_ >= 1.f)
	{
		// Update average every second
		current_average_ = FPSAverage();
		total_time_ = 0.f;
	}

	ImGui::Begin("Debug Menu");
	float fps = dt > 0.f ? 1.f / dt : 0.f;
	ImGui::Text("FPS: %.1f", fps);
	ImGui::Text("Avg FPS: %.1f", current_average_);
	ImGui::Text("Lows %.1f", fps_low_);
	ImGui::Text("Highs %.1f", fps_high_);
	ImGui::End();
}

float DebugWindow::FPSAverage()
{
	float total = 0;
	for (size_t i = 0; i < fps_history_.Size(); i++)
	{
		total += fps_history_.GetQueue()[i];
	}
	total /= static_cast<float>(fps_history_.Size());
	return total;
}

void DebugWindow::Shutdown()
{
	ImGui::SFML::Shutdown();
}

void DebugWindow::Render(sf::RenderWindow& window_)
{
	ImGui::SFML::Render(window_);
}