#include "Pony.hpp"

void  getInputENTER(){
	while (1){
		std::cout << "Press ENTER to kill the pony ";
		std::cin.ignore(10000, '\n');
		if (std::cin.eof()) {
			std::cout<<std::endl;
			std::cin.clear();
			clearerr(stdin);
			continue;
		}
		break;
	}
}

void ponyOnTheHeap(){
	Pony *baby_pony;
	baby_pony = new Pony();
	std::cout << "'" << baby_pony->name << "' is sleeping on the heap of hay..." << std::endl << std::endl;
	std::cout <<
			  "     🦄\n"
	          "     ..\n"
	          "    /\\/\\\n"
	          "   /\\/\\/\\\n"
	          " _/\\_/\\_/\\_ " << std::endl;
	getInputENTER();
	delete baby_pony;
}

void ponyOnTheStack(){
	Pony baby_pony;
	std::cout << "'" << baby_pony.name << "' is resting on the stack of hay..." << std::endl << std::endl;
	std::cout <<
			  "     🦄\n"
	          "    ....\n"
	          "   /\\/\\/\\\n"
	          "   /\\/\\/\\\n"
	          "   /\\/\\/\\ " << std::endl;
	getInputENTER();
}

int main(){
	ponyOnTheStack() ;
	std::cout << std::endl << std::endl;
	ponyOnTheHeap();
	return 0;
}