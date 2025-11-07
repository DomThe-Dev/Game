#include "DebugWindow.h"

void DebugWindow::Init(sf::RenderWindow& window)
{
	if (ImGui::SFML::Init(window))
	{
		spdlog::info("Initialised SFML ImGUI SFML.");
		fps_history_.reserve(FPS_HISTORY_SIZE_); // Reserve space for FPS history
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
	ImGui::SFML::Update(window, delta_time);
	float current_fps = 1.f / delta_time.asSeconds();
	AddFpsSample(current_fps);

	ImGui::Begin("Debug Window");
	ImGui::Text("FPS: %.1f", GetAverageFps());
	ImGui::Text("Frame Time: %.3f ms", delta_time.asMilliseconds());

	// FPS Graph
	if (!fps_history_.empty())
	{
		ImGui::PlotLines("FPS History",
			fps_history_.data(),
			fps_history_.size(),
			0,
			nullptr,
			0.0f,
			5000.0f,
			ImVec2(0, 80));
	}

	ImGui::Separator();
	ImGui::Text("Window Size: %dx%d", window.getSize().x, window.getSize().y);

	ImGui::End();

}

void DebugWindow::Render(sf::RenderWindow& window_)
{


	// Render to the screen
	ImGui::SFML::Render(window_);
}

void DebugWindow::AddFpsSample(float sample)
{
	fps_history_.push_back(sample);
	if (fps_history_.size() >= FPS_HISTORY_SIZE_)
		fps_history_.erase(fps_history_.begin()); // Shifts everything over, so oldest element is removed
}

float DebugWindow::GetAverageFps() const
{
	if (fps_history_.size() <= 0)
		return 0.0f;

	float sum = 0.f;
	for (auto& i : fps_history_)
	{
		sum += i;
	}
	return sum / fps_history_.size();
}
