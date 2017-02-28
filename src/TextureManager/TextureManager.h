#pragma once

#ifndef BLEAH_TEXTUREMANAGER_TEXTUREMANAGER_H_
#define BLEAH_TEXTUREMANAGER_TEXTUREMANAGER_H_

#include <iostream>
#include <map>
#include "../../include/SDL.h"
#include "../../include/SDL_image.h"

class TextureManager
{
public:
	~TextureManager();

	void load(std::string pTextureID, std::string pImagePath, SDL_Renderer* pRenderer);
	void draw(std::string pTextureID, int x, int y, int width, int height, SDL_Renderer* pRenderer);

	static TextureManager* Instance();
private:
	TextureManager();

	static TextureManager* m_pInstance;
	std::map<std::string, SDL_Texture*> m_mTextureContainer;
};

#endif // !BLEAH_TEXTUREMANAGER_TEXTUREMANAGER_H_

