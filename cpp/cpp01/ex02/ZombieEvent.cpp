#include "ZombieEvent.hpp"
#include "Zombie.hpp"

ZombieEvent::ZombieEvent(){
	this->type = "";
}

ZombieEvent::~ZombieEvent() {}

void ZombieEvent::setZombieType() {
	std::string input;
	while (!getInfInput("Enter zombie type ", input))
		continue;
	this->type = input;
}

Zombie* ZombieEvent::newZombie(std::string name){
	Zombie *Generated = new Zombie(name, this->type);
	return (Generated);
}

void ZombieEvent::randomChump(){
	Zombie RandomZombie(generate_name(), type);

	RandomZombie.announce();
}