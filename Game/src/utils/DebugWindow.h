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
	void Update(float dt);
private:
	QueueLoop<float, 100> fps_history_;
	float fps_low_;
	float fps_high_;

	float FPSAverage();
};

