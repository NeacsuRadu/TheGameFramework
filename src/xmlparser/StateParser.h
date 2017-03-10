#pragma once
#ifndef BLEAH_XMLPARSER_STATEPARSER_H_
#define BLEAH_XMLPARSER_STATEPARSER_H_

#include <iostream>
#include <vector>

#include "../objects/GameObject.h"
#include "../../include/tinyxml/tinyxml.h"

class StateParser
{
public:
	bool parseState(const char* stateFile, std::string stateID, std::vector<GameObject*> *pObjects, std::vector<std::string>* pTextureIDs);
private:
	void parseObjects(TiXmlElement* pStateRoot, std::vector<GameObject*> *pObjects);  
	void parseTextures(TiXmlElement* pStateRoot, std::vector<std::string> *pTextureIDs);
};
#endif // !BLEAH_XMLPARSER_STATEPARSER_H_

