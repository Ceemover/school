#pragma once
#include <iostream>
#include <iomanip>

class Brain{
public:
	std::string size_cm;
	std::string main_characteristics;

	std::string identify();
	Brain();
	~Brain();
};