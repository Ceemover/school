#include "ZombieHorde.hpp"
#include "Zombie.hpp"

ZombieHorde::ZombieHorde(int N){
	this->N = N;
	this->Zombies = new Zombie[N];
	for (int i = 0; i < N; ++i)
		Zombies[i].announce();
}

ZombieHorde::~ZombieHorde(){
	delete [] this->Zombies;
}