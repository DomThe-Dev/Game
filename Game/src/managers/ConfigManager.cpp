#include "ConfigManager.h"

// Note: file.close() is not needed as the destructor is called when the variable is out of scope. To my current knowledge.

using json = nlohmann::json;

bool ConfigManager::Load(const std::string& config_location)
{
	// Try opening file
	std::ifstream file(config_location);
	if (!file.is_open())
	{
		spdlog::error("Could not open config file at: {}", config_location);
		return false;
	}
	spdlog::info("Loaded config file at: {}", config_location);

	// Store the config.json file contents into temp variable j
	json j;
	try
	{
		file >> j;
	}
	catch (const std::exception& e)
	{
		spdlog::error("Could not parse json data into variable. Error: {}", e.what());
		return false;
	}

	// Store data in the struct, for fast access
	if (j.contains("window"))
	{
		auto& window = j["window"];
		// Second parameter is a default value if that line of code is missing.
		window_conf_.fullscreen = window.value("fullscreen", false);
		window_conf_.vsync = window.value("vsync", false);
		window_conf_.width = window.value("width", 1280);
		window_conf_.height = window.value("height", 720);
		window_conf_.refresh_rate = window.value("refresh_rate", 60);
	}
	else // Config does not contain window section
	{
		spdlog::warn("config.json does not contain the window section. Using default struct.");
	}

	// Store for saving and such.
	config_path_ = config_location;
	return true;
}


bool ConfigManager::Save()
{
	// Check if there is already a config path
	if (config_path_.empty())
	{
		spdlog::error("Config path is empty, not able to save.");
		return false;
	}

	// Try to open the file path, if it can't for some reason, then throw an error.
	std::ofstream file(config_path_);
	if (!file.is_open())
	{
		spdlog::error("Could not open config file to save at {}", config_path_);
		return false;
	}

	// Try to put all the data into the file
	json j;
	try
	{
		auto& window = j["window"];
		window["fullscreen"] = window_conf_.fullscreen;
		window["vsync"] = window_conf_.vsync;
		window["width"] = window_conf_.width;
		window["heigh"] = window_conf_.height;
		window["refresh_rate"] = window_conf_.refresh_rate;

		file << j.dump(4);
		return true;
	}
	catch (const std::exception& e)
	{
		spdlog::error("Could not store the struct in the config file. Error {}", e.what());
		return false;
	}
}

WindowConfig& ConfigManager::GetWindowConfig()
{
	return window_conf_;
}
