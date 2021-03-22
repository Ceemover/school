#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int main(){
	ZombieEvent zombie_event;
	zombie_event.setZombieType();

	Zombie *heapMan = zombie_event.newZombie("HeapMan");
	heapMan->announce();
	delete heapMan;

	zombie_event.randomChump();

	Zombie zombie("Vasya", "Stack");
	zombie.announce();
}