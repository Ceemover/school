#include <iostream>

int main(){
	std::string s = "HI THIS IS BRAIN";
	std::string *s_ptr = &s;
	std::string &s_ref = s;

	std::cout << "Pointer: "    << *s_ptr << std::endl;
	std::cout << "Reference: "  << s_ref << std::endl;
}