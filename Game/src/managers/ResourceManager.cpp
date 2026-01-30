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

void ResourceManager::LoadFont(const std::string& id, const std::string& file_path)
{
	// If font ID is already in use
	if (fonts_.find(id) != fonts_.end())
	{
		spdlog::error("Font ID: {} is already in use.", id);
		return;
	}

	sf::Font font;
	// If cannot load the file
	if (!font.openFromFile(file_path))
	{
		spdlog::error("Could not load font with ID: {}, at file location: {}.", id, file_path);
		return;
	}

	// No errors, so continue
	fonts_[id] = std::move(font);
}

const sf::Font* ResourceManager::GetFont(const std::string& id) const
{
	auto it = fonts_.find(id);

	// If can't find the font
	if (it == fonts_.end())
	{
		spdlog::error("Cannot find the font with ID: {}", id);
		return nullptr; // Return with an error font maybe?
	}

	// Has found it
	return &it->second;
}

void ResourceManager::UnloadFont(const std::string& id)
{
	auto it = fonts_.find(id);

	if (it == fonts_.end())
	{
		spdlog::warn("Could not unload font with ID: {}", id); // No harm no foul?
		return;
	}
	fonts_.erase(it);
}

void ResourceManager::UnloadAll()
{
	spdlog::info("Clearing Textures map, size: {}", textures_.size());
	textures_.clear();

	spdlog::info("Clearing Fonts map, size: {}", fonts_.size());
	fonts_.clear();
}
