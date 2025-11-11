#pragma once
#include <string>
#include <unordered_map>
#include <memory>

#include "../core/Resource.h"

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
class ResourceManager
{
public:
	static ResourceManager& GetInstance();

	/// <summary>
	/// Load will first try to get the asset by ID, returning the asset if it exists.
	/// If it does not exist, it will load the asset from the file path, and store it in a map.
	/// </summary>
	/// <param name="id"></param>
	/// <param name="file_path"></param>
	/// <returns></returns>
	std::shared_ptr<Resource> Load(std::string id, std::string file_path);
	std::shared_ptr<Resource> Get(std::string id); // Gets a certain asset by ID
private:
	std::unordered_map<std::string, std::shared_ptr<Resource>> resources_; // Map of resources by ID

	ResourceManager(); // Private constructor for singleton pattern
	ResourceManager(ResourceManager const&); // Stop copies
	ResourceManager operator=(ResourceManager const&); // Stop copies
};