#pragma once
#include <string>
#include <unordered_map>
#include <memory>

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
	bool Load(std::string id, std::string file_path);
	void Get(std::string id); // Gets a certain asset by ID
private:
	ResourceManager(); // Private constructor for singleton pattern
	ResourceManager(ResourceManager const&); // Stop copies
	ResourceManager operator=(ResourceManager const&); // Stop copies
};