#pragma once

#include "stdafx.h"

class AnimatedSprite;

class SpriteManager
{
public:
	SpriteManager(std::string ps_directory);
	~SpriteManager();

	sf::Sprite* loadSprite(std::string ps_FileName, int pi_x, int pi_y, int pi_w, int pi_h);
	sf::Sprite* loadSprite(std::string ps_FileName);
	
	AnimatedSprite *loadanimatedSprite(std::string ps_FileName);

	
private:
	
	std::string ms_DirectoryPath;

	std::map<std::string, sf::Texture*> mm_textures;
};