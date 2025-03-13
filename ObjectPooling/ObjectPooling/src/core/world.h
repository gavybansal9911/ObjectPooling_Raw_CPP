#pragma once

#include <vector>

class PoolObject;

class World {
public:
	World(int worldID);
	~World();

	bool AddObjectToWorld(PoolObject* newObject);
	bool RemoveObjectFromWorld(PoolObject* inObject);
	void CollectGarbage();

private:
	int m_WorldID = -1;
	std::vector<PoolObject*> m_WorldOutliner;

public:
	size_t GetTotalNumberOfObjects() const { return m_WorldOutliner.size(); };
};
