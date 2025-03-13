#include "world.h"
#include <iostream>
World::World(int worldID)
{
	this->m_WorldID = worldID;
}

World::~World()
{
	for (int i = 0; i < m_WorldOutliner.size(); i++) {
		if (m_WorldOutliner[i])
			delete m_WorldOutliner[i];
	}
	m_WorldOutliner.clear();
}

bool World::AddObjectToWorld(PoolObject* newObject)
{
	//m_WorldOutliner.resize(m_WorldOutliner.size() + 1);
	m_WorldOutliner.push_back(newObject);
	return true;
}

bool World::RemoveObjectFromWorld(PoolObject* inObject)
{
	for (int i = 0; i < m_WorldOutliner.size(); i++) {
		if (m_WorldOutliner[i] == inObject) {
			m_WorldOutliner.erase(m_WorldOutliner.begin() + i);
		}
	}
	return false;
}

void World::CollectGarbage()
{
	for (int i = 0; i < m_WorldOutliner.size(); i++) {
		if (m_WorldOutliner[i] == nullptr) {
			m_WorldOutliner.erase(m_WorldOutliner.begin() + i);
		}
	}
}
