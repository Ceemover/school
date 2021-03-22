#include "Pony.hpp"

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

std::string centered( std::string const& message, int width, char c)
{
	int i = 0;
	int j = 0;
	std::string ret_string;
	int len = message.length();
	int before = (width - len)/2;

	if (len == width) {
		return message;
	}
	else if (len > width){
		ret_string = message.substr(0,width);
		ret_string[width - 1] = '.';
		return ret_string;
	}
	else{
		char mal_ret_string[width + 1];
		while (i < before)
			mal_ret_string[i++] = c;
		while (i - before < len)
			mal_ret_string[i++] = message[j++];
		while (i < width)
			mal_ret_string[i++] = c;
		mal_ret_string[i] = '\0';
		return mal_ret_string;
	}
}

void    RIP(std::string name, std::string epitaph){
	std::string message = name.substr(0,13);
	if (name.length() > 13)
		message[12] = '.';
	else
		message = centered(message, 13, ' ');

	std::cout << "\n"
	             "    .-----------..\n"
	             "  .'   _     _   `.#\n"
	             "  |   |_) | |_)   |#\n"
				 "  |   | \\ | |     |#\n"
	             "  |               |#\n"
				 "  | "<< message << " |#\n"
	             "  |               |#\n";
	std::string message_p2;
	if (epitaph.length() > 15){
		message = epitaph.substr(0, 15);
		message[14] = '-';
		message_p2 = epitaph.substr(14, epitaph.length() - 14);
		if (message_p2.length() > 15){
			message_p2[14] = '.';
			message_p2[15] = '\0';
		}
	}
	else
		message = centered(epitaph.substr(0), 15, ' ');
	std::cout << " -------------------ˊ\n"
	             " | " << message << " |#| \n";
	if (message_p2.compare(""))
		std::cout << " | " << std::setw(15) << std::left << message_p2.c_str() <<  " |#| \n";
	std::cout << 	 " -------------------ˊ"<< std::endl;
	std::string f = "🥀";
	int flower = 0;
	while (flower++ < 12)
		std::cout << f.c_str();
	std::cout << std::endl;
}

Pony::Pony() {
	std::cout << "Generating new pony ...\n-----------------------" << std::endl;
	while (!getInfInput("Enter name: ", this->name) || !this->name.compare(""))
		std::cout << "Name cannot be empty" << std::endl;
	while (!getInfInput("Enter age: ", this->age) || !is_number_print_err(this->age, 1))
		continue;
	while (!getInfInput("Enter height(cm): ", this->height_cm) || !is_number_print_err(this->height_cm, 1))
		continue;
	std::cout <<  "\nCreated a Pony named '" <<  this->name << "';\nHeight: '" << this->height_cm \
	<< "' cm; \nAge: '"<< this->age << "'\n" << "That's a very big boi\n-----------------------" << std::endl;
}

Pony::~Pony(){
	std::string epitaph;
	std::cout <<  "'" <<  this->name << "' is now dead.\n" << std::endl;
	while (!getInfInput("Enter pony's memorial message: ", epitaph))
		continue;
	RIP(this->name, epitaph);
}

