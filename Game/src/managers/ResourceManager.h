#pragma once
#include <string>
#include <unordered_map>
//#include <memory>

/*
* Create a singleton resource manager class
* Have a resource class
* Resource class is inherited by different asset types (e.g. Texture, Sound, Model)
*	Reource class has a path to the file
*	Child class has the actual data for it, e.g texture, timings, volume, etc
*/

/// <summary>
/// Loads and returns the assets from file paths, and stores them in a map. Singleton.
/// </summary>
template<typename Resource>
class ResourceManager
{
public:
	static ResourceManager& GetInstance()
	{
		static ResourceManager instance;
		return instance;
	}

private:
	// Singleton class.
	ResourceManager() = default; // Private constructor.
	ResourceManager(const ResourceManager&) = delete; // Delete copy constructor.
	ResourceManager& operator=(const ResourceManager&) = delete; // Delete assignment operator.
	ResourceManager(ResourceManager&&) = delete; // Delete move constructor.
	ResourceManager& operator=(ResourceManager&&) = delete; // Delete move assignment operator.

	
};