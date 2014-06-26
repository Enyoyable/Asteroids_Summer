#pragma once

#include "stdafx.h"

class SpriteManager
{
public:
	SpriteManager(std::string ps_directory);

	sf::Sprite* loadSprite(std::string ps_FileName);

private:
	std::string ms_DirectoryPath;

	std::map<std::string, sf::Texture*> mm_textures;
};