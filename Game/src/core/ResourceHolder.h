#pragma once
#include "../utils/Common.h"
#include <string>
#include <unordered_map>
#include <SFML/Graphics.hpp>

// Note: Add a wrapper for the nlohmann jsons, because they don't load like sfml types

/// <summary>
/// Each type of resource such as SFML types like texture, and config files like wave configs and game configs
/// will be handled by this class. These will be used in ResourceManager.
/// </summary>
/// <typeparam name="Resource"></typeparam>
template<typename Resource>
class ResourceHolder 
{
public:
	/// <summary>
	/// Attempt to load an resource into the map with a unique ID, at a certain file path.
	/// If the resource already exists, then write an error into log.
	/// If resource loading has failed, write error, and throw exception.
	/// </summary>
	/// <param name="id">Unique ID for the resource</param>
	/// <param name="path">Path to the resource</param>
	void Load(const std::string& id, const std::string& path)
	{
		if (Has(id))
		{
			spdlog::error("Tried loading asset in holder with an ID that already exists! ID: '{}'", id);
			return;
		}

		auto resource = std::make_unique<Resource>();
		if (!resource->loadFromFile(path))
		{
			spdlog::error("Could not load file with ID: '{}' at file path: '{}'", id, path);
			throw std::runtime_error("Failed to load resource: " + id); // Critical error?
		}

		resource_map_[id] = std::move(resource);
		spdlog::info("Successfully loaded resource '{}' at path '{}'", id, path);
	}

	/// <summary>
	/// Get the asset reference from the map. Will throw an error if the asset is not already in the map.
	/// </summary>
	/// <param name="id">Unique ID for the resource</param>
	/// <returns>Reference to the resource</returns>
	Resource& Get(const std::string& id)
	{
		// Don't use has here, as otherwise it will check for the resource twice
		auto found = resource_map_.find(id);

		if (found == resource_map_.end())
		{
			spdlog::error("Resource with ID '{}' does not exist in the map", id);
			std::runtime_error("Failed to get resource: " + id);
		}

		return *found->second;
	}

	/// <summary>
	/// Returns boolean value, depending on if the holder already has the entry for the ID of the resource.
	/// </summary>
	/// <param name="id">String ID of Entry</param>
	/// <returns>true if it is in the map, otherwise false</returns>
	bool Has(const std::string& id) const
	{
		return resource_map_.find(id) != resource_map_.end();
	}

	/// <summary>
	/// Unload a single asset from the map. If it is not there, it will write a warning in the log.
	/// </summary>
	/// <param name="id"></param>
	void Unload(const std::string& id)
	{
		if (!Has(id))
		{
			spdlog::warn("Attempted to unload resource that is not in map: '{}'", id);
			return;
		}

		resource_map_.erase(id);
		spdlog::debug("Unloaded resource '{}'", id);
	}

	/// <summary>
	/// Clears out all the entries in the map, and writes a log of how many were cleared.
	/// </summary>
	void Clear()
	{
		size_t count = resource_map_.size();
		resource_map_.clear();
		spdlog::info("Cleared {} resources from the map", count);
	}

private:
	std::unordered_map<std::string, std::unique_ptr<Resource>> resource_map_;
};
