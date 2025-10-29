#pragma once
#include <iostream>
#include <string>
#include <json.hpp>
#include <fstream>
#include "../utils/Common.h"

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
	bool Load(const std::string& config_location);
private:
	WindowConfig window_conf_; // Have the configs stored quickly in a variable
};