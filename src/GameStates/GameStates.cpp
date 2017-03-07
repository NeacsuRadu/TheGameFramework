#include "../GameStates/GameState.h"

bool GameStateFactory::Register(std::string creatorId, GameStateCreator* creator)
{
	auto it = m_creators.find(creatorId);
	if (it != m_creators.end())
	{
		delete creator;
		return false;
	}
	m_creators[creatorId] = creator;
	return true;
}

GameState* GameStateFactory::Create(std::string creatorId)
{
	auto it = m_creators.find(creatorId);
	if (it == m_creators.end())
	{
		return nullptr;
	}
	return it->second->create();
}

GameStateFactory::~GameStateFactory()
{
	for (auto it : m_creators)
	{
		delete it.second;
	}
}