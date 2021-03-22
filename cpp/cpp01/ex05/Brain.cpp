#include "Brain.hpp"

int     getInfInput(std::string message, std::string &input)
{
	std::cout << message;
	getline(std::cin, input);
	if (std::cin.eof()) {
		std::cout<<std::endl;
		std::cin.clear();
		clearerr(stdin);
		std::cin.ignore(input.size());
		return 0;
	}
	return 1;
}

bool    is_number_print_err(const std::string& s, int only_positive)
{
	bool negative_sign;

	std::string::const_iterator i = s.begin();
	if (i != s.end() && *i == '-')
		i++;
	negative_sign = (only_positive && i != s.begin());
	if (i == s.end()){
		std::cout << "Not a number" << std::endl;
		return (0);
	}
	while (i != s.end() && std::isdigit(*i))
		i++;
	if (!(!s.empty() && i == s.end()))
		std::cout << "Not a number" << std::endl;
	else if (only_positive && negative_sign)
	{
		std::cout << "Not a positive number" << std::endl;
		return (0);
	}
	return !s.empty() && i == s.end();
}

std::string Brain::identify(){
	const void * address = static_cast<const void*>(this);
	std::stringstream ss;
	ss << std::hex << address;
	std::string name = ss.str();
	for (int i = 0; i < (int)name.length(); ++i)
		name[i] = toupper(name[i]);
	return (name);
}

Brain::Brain(){
	std::string input;

	while (!getInfInput("Enter brain size in cm: ", input) || !is_number_print_err(input, 1))
		continue;
	size_cm = input;
	while (!getInfInput("Enter main characteristics of this brain: ", input))
		continue;
	main_characteristics = input;
	std::cout << std::endl;
}

Brain::~Brain() {}
