#include <iostream>
#include "../src/core/world.h"
#include "../src/components/poolComponent.h"

int main() {
	World* myWorld = new World(1);
	
	PoolComponent<PoolObject>* testPoolComponent = new PoolComponent<PoolObject>(myWorld, 10);
	testPoolComponent->CreatePool();
	testPoolComponent->SpawnObjectFromPool();
	PoolObject* obj = testPoolComponent->SpawnObjectFromPool();
	testPoolComponent->SpawnObjectFromPool();
	testPoolComponent->RemoveObjectFromPool(obj);
	testPoolComponent->DestroyPool();
	
	myWorld->CollectGarbage();
	std::cout << "NumberOfObjectsInWorld: " << myWorld->GetTotalNumberOfObjects() << "\n";
	std::cout << "NumberOfObjectsInPool: " << testPoolComponent->GetNumberOfObjectsInPool() << "\n";
	std::cout << "NumberOfObjectsInUse: " << testPoolComponent->GetNumberOfObjectsInUse() << "\n";
	
	return 0;
}