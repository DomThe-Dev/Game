#include "ResourceManager.h"

void ResourceManager::LoadTexture(const std::string& id, const std::string& file_path)
{
	// If texture ID is already in use
	if (textures_.find(id) != textures_.end())
	{
		spdlog::error("Texture ID: {} is already in use.", id);
		return;
	}

	sf::Texture texture;
	// If cannot load the file
	if (!texture.loadFromFile(file_path))
	{
		spdlog::error("Could not load texture with ID: {}, at file location: {}.", id, file_path);
		return;
	}

	// No errors, so continue
	textures_[id] = std::move(texture);
}

const sf::Texture* ResourceManager::GetTexture(const std::string& id) const
{
	// Using the std::optional thing because maybe the reference doesn't exist, and something needs to be handed back.
	// This does mean that 

	auto it = textures_.find(id);

	// If can't find the texture
	if (it == textures_.end())
	{
		spdlog::error("Cannot find the texture with ID: {}", id);
		return nullptr; // Return with an error texture maybe?
	}
	
	// Has found it
	return &it->second;
}

void ResourceManager::UnloadTexture(const std::string& id)
{
	auto it = textures_.find(id);

	if (it == textures_.end())
	{
		spdlog::warn("Could not unload texture with ID: {}", id); // No harm no foul?
		return;
	}
	textures_.erase(it);
}
