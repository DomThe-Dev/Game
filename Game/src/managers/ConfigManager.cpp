#include "ConfigManager.h"

using json = nlohmann::json;

bool ConfigManager::Load(const std::string& config_location)
{
	std::ifstream file(config_location);
	if (!file.is_open())
	{
		spdlog::error("Could not open config file at: {}", config_location);
		return false;
	}
	spdlog::info("Loaded config file at: {}", config_location);

	json j;
	try
	{
		file >> j; // Put the json config into the variable j.
	}
	catch (const std::exception& e)
	{
		spdlog::error("Could not parse json data into variable. Error: ", e.what());
		return false;
	}
}
