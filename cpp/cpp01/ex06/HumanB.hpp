#pragma once
#include "Weapon.hpp"

class HumanB{
private:
	std::string name;
	Weapon *weapon;
public:
	void setWeapon(Weapon &weapon);
	void attack();
	HumanB(std::string name);
	~HumanB();
};