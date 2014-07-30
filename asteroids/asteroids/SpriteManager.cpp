#include "SpriteManager.h"
#include "AnimatedSprite.h"
#include <iostream>
#include <fstream>
#include <string>

SpriteManager::SpriteManager(std::string directory)
{
	ms_DirectoryPath = directory;
}

sf::Sprite* SpriteManager::loadSprite(std::string ps_fileName, int pi_x, int pi_y, int pi_w, int pi_h)
{
	//Redone draw method made with additional variables. Also taken from reference.
	auto it = mm_textures.find(ps_fileName);

	if (it == mm_textures.end())
	{
		sf::Texture *texture = new sf::Texture;

		texture->loadFromFile(ms_DirectoryPath + ps_fileName, sf::IntRect(pi_x, pi_y, pi_w, pi_h));

		mm_textures.insert(std::pair<std::string, sf::Texture*>(ps_fileName, texture));

		it = mm_textures.find(ps_fileName);
	}

	return new sf::Sprite(*it->second);

	/*
	//New Draw method #1

	sf::Texture *texture = new sf::Texture;

	texture->loadFromFile(ms_DirectoryPath + ps_filePath);

	return new sf::Sprite(*texture, sf::IntRect(0, 0, texture->getSize().x, texture->getSize().y));*/

	/*
	//Original draw method
	
	std::fstream stream(ms_DirectoryPath + ps_filePath);

	std::string sTexturePath;

	stream >> sTexturePath;

	auto it = mm_textures.find(sTexturePath);

	if (it == mm_textures.end())
	{
		sf::Texture *texture = new sf::Texture;

		std::cout << ms_DirectoryPath + sTexturePath << std::endl;

		texture->loadFromFile(ms_DirectoryPath + sTexturePath);

		mm_textures.insert(std::pair<std::string, sf::Texture*>(sTexturePath, texture));

		it = mm_textures.find(sTexturePath);
	}

	int x, y, w, h;

	stream >> x >> y >> w >> h;

	return new sf::Sprite(*it->second, sf::IntRect(x, y, w, h));*/
}

sf::Sprite* SpriteManager::loadSprite(std::string ps_filePath)
{
	//std::fstream stream(ms_DirectoryPath + ps_filePath);

	std::string sTexturePath;

	//stream >> sTexturePath;

	sTexturePath = ms_DirectoryPath + ps_filePath;

	auto it = mm_textures.find(sTexturePath);

	if (it == mm_textures.end())
	{
		sf::Texture *texture = new sf::Texture;

		texture->loadFromFile(ms_DirectoryPath + ps_filePath);

		mm_textures.insert(std::pair<std::string, sf::Texture*>(sTexturePath, texture));

		it = mm_textures.find(sTexturePath);
	}

	int x, y, w, h;

	x = 0;
	y = 0;
	w = it->second->getSize().x;
	h = it->second->getSize().y;
	//stream >> x >> y >> w >> h;

	return new sf::Sprite(*it->second, sf::IntRect(x, y, w, h));
}

AnimatedSprite *SpriteManager::loadanimatedSprite(std::string ps_fileName)
{
	std::fstream stream(ms_DirectoryPath + ps_fileName);

	std::string sTexturePath;

	//sTexturePath = ms_DirectoryPath + ps_fileName;

	stream >> sTexturePath;

	auto it = mm_textures.find(sTexturePath);

	if (it == mm_textures.end())
	{
		sf::Texture *texture = new sf::Texture;

		texture->loadFromFile(ms_DirectoryPath + sTexturePath);

		mm_textures.insert(std::pair<std::string, sf::Texture*>(sTexturePath, texture));
		
		it = mm_textures.find(sTexturePath);
	}
	
	AnimatedSprite *anSprite = new AnimatedSprite;

	std::string sRow;

	int row = 0;

	while (!stream.eof())
	{
		int x, y, w, h;

		AnimatedSprite::Frame *frame = new AnimatedSprite::Frame;

		stream >> frame->mf_duration;

		stream >> x >> y >> w >> h;

		frame->m_placement = sf::IntRect(x, y, w, h);

		frame->m_texture = it->second;

		anSprite->addFrame(frame);
	}
	return anSprite;
}