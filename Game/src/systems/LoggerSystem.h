#pragma once
#include <spdlog/logger.h>

class LoggerSystem
{
public:
	static LoggerSystem& GetInstance()
	{
		static LoggerSystem* instance = new LoggerSystem();
		return *instance;
	}
private:
	LoggerSystem();
};