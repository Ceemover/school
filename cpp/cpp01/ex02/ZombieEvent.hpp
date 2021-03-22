#include "Zombie.hpp"

class ZombieEvent{
public:
	std::string type;

	Zombie* newZombie(std::string name);
	void setZombieType();
	void randomChump();
	ZombieEvent();
	~ZombieEvent();
};