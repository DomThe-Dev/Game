#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <imgui.h>
#include <imgui-SFML.h>

#include "QueueLoop.h"
#include "Common.h"

class DebugWindow
{
public:
	/// <summary>
	/// Initialises the SFML ImGUI with the current window passed in as reference.
	/// </summary>
	/// <param name="window">Reference to the currently active window.</param>
	void Init(sf::RenderWindow& window);
	void ProcessEvent(sf::RenderWindow& window, const sf::Event& event);
	void Update(sf::RenderWindow& window, sf::Time& delta_time);
	void Shutdown();
	void Render(sf::RenderWindow& window_);
private:
	QueueLoop<float, 100> fps_history_;
	float current_average_ = 0.f;
	float total_time_ = 0.f;
	float fps_low_ = 0.f;
	float fps_high_ = 0.f;

	float FPSAverage();
};

