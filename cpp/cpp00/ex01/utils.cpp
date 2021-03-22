#include "Contacts.hpp"

int arr_length(Contacts people[]){
    int i = 0;

    while (people[i].isSet() && i < PEOPLE_MAX)
        i++;
    return (i);
}

int getInput(std::string &input)
{
	getline(std::cin, input);
	if (std::cin.eof()) {
		std::cout<<std::endl;
		std::cin.clear();
		std::cin.ignore(input.size());
		clearerr(stdin);
		return 0;
	}
	return 1;
}

std::string truncate_to_10(std::string str)
{
    std::string ret_str;

    if (str.length() >= 10){
        ret_str = str.substr(0, 10);
        ret_str[9] = '.';
    }
    else
        ret_str = str;
    return ret_str;
}

bool is_number(const std::string& s)
{
    std::string::const_iterator i = s.begin();
    if (i != s.end() && *i == '-')
        i++;
    if (i == s.end())
        return (0);
    while (i != s.end() && std::isdigit(*i))
        i++;
    return !s.empty() && i == s.end();
}

bool is_bigger_than_9(std::string s)
{
    std::string::const_iterator i = s.begin();
    int zero_flag = 0;

    if (i != s.end() && *i == '-')
        i++;
    while (i != s.end() && *i == '0' && (zero_flag = 1))
        i++;
    std::string::const_iterator i_beginning = i;
    while (i != s.end() && std::isdigit(*i))
        i++;
    if (i - i_beginning < 2)
        return 0;
    else
        return 1;
}