#include "SpriteManager.h"
#include <fstream>

SpriteManager::SpriteManager(std::string directory)
{
	ms_DirectoryPath = directory;
}

sf::Sprite* SpriteManager::loadSprite(std::string ps_filePath)
{
	std::fstream stream(ms_DirectoryPath + ps_filePath);

	std::string sTexturePath;

	stream >> sTexturePath;

	auto it = mm_textures.find(sTexturePath);

	if (it == mm_textures.end())
	{
		sf::Texture *texture = new sf::Texture;

		texture->loadFromFile(ms_DirectoryPath + sTexturePath);

		mm_textures.insert(std::pair<std::string, sf::Texture*>(sTexturePath, texture));

		it = mm_textures.find(sTexturePath);
	}

	int x, y, w, h;

	stream >> x >> y >> w >> h;

	return new sf::Sprite(*it->second, sf::IntRect(x, y, w, h));
}