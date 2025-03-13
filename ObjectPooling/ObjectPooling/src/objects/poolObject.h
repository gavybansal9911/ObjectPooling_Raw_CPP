#pragma once

class PoolObject {
public:
	PoolObject();
	~PoolObject();
	
	virtual void SetInUse(const bool bValue);
	
private:
	bool m_InUse = true;
};
