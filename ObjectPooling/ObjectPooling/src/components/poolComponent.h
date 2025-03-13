#pragma once

#include <vector>
#include "../objects/poolObject.h"

template<typename T>
class PoolComponent {
public:
	PoolComponent(World* inWorld, int poolSize) {
		this->m_WorldRef = inWorld;
		this->m_PoolSize = poolSize;
	}
	~PoolComponent() {

	}

	bool CreatePool() {
		//if (std::is_base_of_v(PoolObject, T) == false) return false;
		for (int i = 0; i < m_PoolSize; i++) {
			//m_ObjectsInPool.resize(m_ObjectsInPool.size() + 1);
			m_ObjectsInPool.push_back(new PoolObject());
		}
		return true;
	}

	bool DestroyPool() {
		for (PoolObject* obj : m_ObjectsInPool) {
			m_WorldRef->RemoveObjectFromWorld(obj);
			delete obj;
		}
		for (PoolObject* obj : m_ObjectsInUse) {
			m_WorldRef->RemoveObjectFromWorld(obj);
			delete obj;
		}
		m_ObjectsInPool.clear();
		m_ObjectsInUse.clear();
		return true;
	}

	T* SpawnObjectFromPool() {
		if (m_ObjectsInPool.size() > 0) {
			PoolObject* l_Obj = m_ObjectsInPool[0];
			l_Obj->SetInUse(true);
			m_ObjectsInUse.push_back(l_Obj);
			m_ObjectsInPool.erase(m_ObjectsInPool.begin());
			m_WorldRef->AddObjectToWorld(l_Obj);
			return l_Obj;
		}
		return nullptr;
	}
	bool RemoveObjectFromPool(T* objectToRemove) {
		for (int i = 0; i < m_ObjectsInUse.size(); i++) {
			if (objectToRemove == m_ObjectsInUse[i]) {
				m_ObjectsInPool.push_back(objectToRemove);
				m_ObjectsInUse.erase(m_ObjectsInUse.begin() + i);
				m_WorldRef->RemoveObjectFromWorld(objectToRemove);
			}
		}
		return false;
	}

private:
	World* m_WorldRef;
	int m_PoolSize;
	std::vector<T*> m_ObjectsInUse;
	std::vector<T*> m_ObjectsInPool;

public:
	size_t GetNumberOfObjectsInPool() const { return m_ObjectsInPool.size(); }
	size_t GetNumberOfObjectsInUse() const { return m_ObjectsInUse.size(); }
};
