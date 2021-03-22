#pragma once
#include <iostream>
extern int has_been_randomized;

class Zombie{
public:
	std::string name;
	std::string type;

	void announce();
	Zombie();
	~Zombie();
};
;





