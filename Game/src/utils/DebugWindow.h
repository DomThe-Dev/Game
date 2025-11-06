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
	/// Initialises the SFML ImGUI with the current window passed in as reference.
	/// </summary>
	/// <param name="window">Reference to the currently active window.</param>
	void Init(sf::RenderWindow& window);
	void ProcessEvent(sf::RenderWindow& window, const sf::Event& event);
private:
	std::vector<float> fps_history_[60];
};

