#pragma once
#include <iostream>

class Zombie{
public:
	std::string name;
	std::string type;

	void announce();
	Zombie(std::string name, std::string type);
	~Zombie();
};
std::string generate_name();
int     getInfInput(std::string message, std::string &input);




