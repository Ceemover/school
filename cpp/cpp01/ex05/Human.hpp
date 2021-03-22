#pragma once
#include "Brain.hpp"
#include <iostream>

class Human{
public:
	Brain brain;
	std::string identify();

	Brain &getBrain();
	Human();
	~Human();
};
