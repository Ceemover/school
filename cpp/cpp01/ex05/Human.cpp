#include "Human.hpp"

Brain& Human::getBrain() {
	return brain;
}

std::string Human::identify() {
	return brain.identify();
}

Human::Human(){}
Human::~Human(){}