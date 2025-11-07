#pragma once
#include <vector>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <imgui.h>
#include <imgui-SFML.h>

#include "Common.h"
#include "FPSTracker.h"

class DebugWindow
{
public:
	/// <summary>
	/// Initialise the debug window system.
	/// </summary>
	/// <param name="window">Reference to the active window.</param>
	void Init(sf::RenderWindow& window);
	/// <summary>
	/// Close the debug window system.
	/// </summary>
	void Shutdown();

	/// <summary>
	/// Update ImGui to process all the events, like clicking the buttons.
	/// </summary>
	/// <param name="window">Reference to the active window</param>
	/// <param name="event">Reference to an event that has happened</param>
	void ProcessEvent(sf::RenderWindow& window, const sf::Event& event);
	/// <summary>
	/// Call once per frame, updates all the values.
	/// </summary>
	/// <param name="window">Reference to active window</param>
	/// <param name="delta_time">Time value from the GameMaster</param>
	void Update(sf::RenderWindow& window, sf::Time delta_time);
	/// <summary>
	/// Displays all the UI elements on the screen.
	/// </summary>
	/// <param name="window_">Reference to the active window</param>
	void Render(sf::RenderWindow& window_);
private:
	float elapsed_time_ = 0.f;
	FPSTracker fps_tracker_;
};

