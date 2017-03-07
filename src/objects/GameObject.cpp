#include "../objects/GameObject.h"

bool GameObjectFactory::Register(std::string creatorId, GameObjectCreator* creator)
{
	auto it = m_creators.find(creatorId);

	if (it == m_creators.end())
	{
		m_creators[creatorId] = creator;
		return true;
	}

	delete creator;
	return false;
}

GameObject* GameObjectFactory::Create(std::string creatorId)
{
	auto it = m_creators.find(creatorId);

	if (it != m_creators.end())
		return it->second->CreateGameObject();

	return nullptr;
}

GameObjectFactory::~GameObjectFactory()
{
	for (auto it : m_creators)
	{
		delete it.second;
	}
}