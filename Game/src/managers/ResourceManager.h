#pragma once
#include <string>
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <json.hpp>

#include "../utils/Common.h"

/*
* Could remove singleton and reuse the class:
*	Core resources for the menu, menu font, etc
*	Scene resources for the scene coming up, meaning that everything will be deleted when the scene is gone
*/

/// <summary>
/// Loads and returns the assets from file paths, and stores them in a map. Singleton.
/// </summary>
class ResourceManager
{
public:
	/// <summary>
	/// Returns instance of the singleton class.
	/// </summary>
	/// <returns></returns>
	static ResourceManager& GetInstance()
	{
		static ResourceManager instance;
		return instance;
	}

	// Texture
	void LoadTexture(const std::string& id, const std::string& file_path);
	const sf::Texture* GetTexture(const std::string& id) const;
	void UnloadTexture(const std::string& id);

	// Audio
	void LoadAudio(const std::string& id, const std::string& file_path);
	const sf::AudioResource& GetAudio(const std::string& id) const;
	void UnloadAudio(const std::string& id);

	// Font
	void LoadFont(const std::string& id, const std::string& file_path);
	const sf::Font GetFont(const std::string& id) const;
	void UnloadFont(const std::string& id);
	
	// Cleanup
	void UnloadAll();
	
private:
	// Singleton class.
	ResourceManager() = default; // Private constructor.
	ResourceManager(const ResourceManager&) = delete; // Delete copy constructor.
	ResourceManager& operator=(const ResourceManager&) = delete; // Delete assignment operator.
	ResourceManager(ResourceManager&&) = delete; // Delete move constructor.
	ResourceManager& operator=(ResourceManager&&) = delete; // Delete move assignment operator.

	// Maps of the resources
	std::unordered_map<std::string, sf::Texture> textures_;
	std::unordered_map<std::string, sf::AudioResource> audios_;
	std::unordered_map<std::string, sf::Font> fonts_;
};