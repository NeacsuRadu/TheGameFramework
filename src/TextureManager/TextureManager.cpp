#include "TextureManager.h"

TextureManager* TextureManager::m_pInstance = nullptr;

TextureManager::TextureManager()
{

}

TextureManager::~TextureManager()
{
	if (m_pInstance != nullptr)
	{
		delete m_pInstance;
	}
}

TextureManager* TextureManager::Instance()
{
	if (m_pInstance == nullptr)
	{
		m_pInstance = new TextureManager();
	}
	return m_pInstance;
}

void TextureManager::load(std::string pTextureID, std::string pImagePath)
{
	SDL_Surface* pTempSurface = IMG_Load(pImagePath.c_str());
	if (pTempSurface == nullptr)
	{
		std::cout << "Failed to load image" << std::endl;
		return;
	}

	SDL_Texture* pTexture = SDL_CreateTextureFromSurface(Game::Instance()->getRenderer(), pTempSurface);
	SDL_FreeSurface(pTempSurface);

	if (pTexture != nullptr)
	{
		m_mTextureContainer[pTextureID] = pTexture;
	}
	else
	{
		std::cout << "Failed something with the texture" << std::endl;
	}
}

void TextureManager::draw(std::string pTextureID, int x, int y, int width, int height)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(Game::Instance()->getRenderer(), m_mTextureContainer[pTextureID], &srcRect, &destRect, 0, 0, SDL_FLIP_NONE);
}