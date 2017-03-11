#include "../xmlparser/StateParser.h"

#include "../TextureManager/TextureManager.h"
#include "../../include/tinyxml/tinyxml.h"

bool StateParser::parseState(const char* stateFile, std::string stateID, std::vector<GameObject*> *pObjects, std::vector<std::string> *pTextureIDs)
{
	TiXmlDocument xmlDoc;
	if (!xmlDoc.LoadFile(stateFile))
	{
		std::cout << xmlDoc.ErrorDesc() << std::endl;
		return false;
	}

	TiXmlElement* pRoot = xmlDoc.RootElement();
	TiXmlElement* pStateRoot = nullptr;
	
	for (auto e = pRoot->FirstChildElement(); e != nullptr; e = e->NextSiblingElement())
	{
		if (e->Value() == stateID)
		{
			pStateRoot = e;
		}
	}

	TiXmlElement *pTextureRoot = nullptr;
	for (auto e = pStateRoot->FirstChildElement(); e != nullptr; e = e->NextSiblingElement())
	{
		if (e->Value() == std::string("TEXTURES"))
		{
			pTextureRoot = e;
		}
	}
	parseTextures(pTextureRoot, pTextureIDs);

	TiXmlElement* pObjectRoot = nullptr;
	for (auto e = pStateRoot->FirstChildElement(); e != nullptr; e = e->NextSiblingElement())
	{
		if (e->Value() == std::string("OBJECTS"))
		{
			pObjectRoot = e;
		}
	}
	parseObjects(pObjectRoot, pObjects);

	return true;
}

void StateParser::parseObjects(TiXmlElement* pStateRoot, std::vector<GameObject*> *pObjects)
{
	for (auto e = pStateRoot->FirstChildElement(); e != nullptr; e = e->NextSiblingElement())
	{
		int x, y, width, height, callbackID;
		std::string textureID;

		e->Attribute("x", &x);
		e->Attribute("y", &y);
		e->Attribute("width", &width);
		e->Attribute("height", &height);
		e->Attribute("callbackID", &callbackID);

		textureID = e->Attribute("textureID");

		GameObject* pGameObject = Game::Instance()->GetGameObjectFactory()->Create(e->Attribute("type"));
		pGameObject->load(new LoaderParams(x, y, width, height, textureID, callbackID));
		pObjects->push_back(pGameObject);
	}
}

void StateParser::parseTextures(TiXmlElement* pStateRoot, std::vector<std::string> *pTextureIDs)
{
	for (auto e = pStateRoot->FirstChildElement(); e != nullptr; e = e->NextSiblingElement())
	{
		std::string filenameAttribute = e->Attribute("filename");
		std::string idAttribute = e->Attribute("id");
		pTextureIDs->push_back(idAttribute);
		TextureManager::Instance()->load(idAttribute, filenameAttribute);
	}
}
