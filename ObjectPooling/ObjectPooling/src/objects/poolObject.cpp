#include "poolObject.h"

PoolObject::PoolObject()
{
}

PoolObject::~PoolObject()
{
}

void PoolObject::SetInUse(const bool bValue)
{
	m_InUse = bValue;
}
