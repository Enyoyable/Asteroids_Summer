#pragma once

#include "stdafx.h"

class SpriteManager
{
public:
	SpriteManager(std::string ps_directory);

	sf::Sprite* loadSprite(std::string ps_FileName, int pi_x, int pi_y, int pi_w, int pi_h);

private:
	std::string ms_DirectoryPath;

	std::map<std::string, sf::Texture*> mm_textures;
};