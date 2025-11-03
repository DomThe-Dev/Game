#pragma once
#include <iostream>
#include <string>
#include <json.hpp>
#include <fstream>
#include "../utils/Common.h"

// Default window config.
struct WindowConfig
{
	bool fullscreen = false;
	bool vsync = false;
	unsigned int width = 1280;
	unsigned int height = 720;
	unsigned int refresh_rate = 60;
};

class ConfigManager
{
public:
	/// <summary>
	/// Loads the config file from a given path, and stores it in
	/// the structs of this class.
	/// </summary>
	/// <param name="config_location"></param>
	/// <returns>true if loaded correctly, otherwise false</returns>
	bool Load(const std::string& config_location);
	/// <summary>
	/// Saves the config stored in the current struct to the config location.
	/// </summary>
	/// <returns>true if it ran correctly, false otherwise</returns>
	bool Save();

	/// <summary>
	/// Returns the saved config of the window.
	/// </summary>
	/// <returns>window_config_&, the current config in memory</returns>
	WindowConfig& GetWindowConfig();
private:
	std::string config_path_; // Store the config path when loading for quick access later.
	WindowConfig window_conf_; // Have the configs stored quickly in a variable
};