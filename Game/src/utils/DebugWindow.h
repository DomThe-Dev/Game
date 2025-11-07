#pragma once
#include <vector>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <imgui.h>
#include <imgui-SFML.h>

#include "Common.h"

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
	/// Call once per frame. Makes everything in the GUI and displays the values. Also updates values.
	/// </summary>
	/// <param name="window">Reference to active window</param>
	/// <param name="delta_time">Time value from the GameMaster</param>
	void Update(sf::RenderWindow& window, sf::Time delta_time);
	void Render(sf::RenderWindow& window_);
private:
	float second_timer_ = 0.f; // The time unit timer, so some stuff can get updated every second.

	// FPS Tracking
	static constexpr size_t FPS_HISTORY_SIZE_ = 64; // Must be a power of 2 for performance. Constexpr to make it a compile time constant, making it faster
	std::vector<float> fps_history_[FPS_HISTORY_SIZE_];

};

