#pragma once
#include <iostream>

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
};