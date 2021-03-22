#pragma once
#include "Zombie.hpp"

class ZombieHorde{
public:
	int N;
	Zombie *Zombies;
	ZombieHorde(int N);
	~ZombieHorde();
};