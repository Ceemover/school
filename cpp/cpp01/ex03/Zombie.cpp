#include "Zombie.hpp"
// INPUT CHECKER

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

// RANDOM NAME GENERATOR

int findCeil(int arr[], int r, int l, int h)
{
	int medium;
	while (l < h)
	{
		medium = l + ((h - l) >> 1);
		(r > arr[medium]) ? (l = medium + 1) : (h = medium);
	}
	return (arr[l] >= r) ? l : -1;
}

char myRand(char *arr, int freq[], int n)
{
	int frequencySummator[n], i;
	frequencySummator[0] = freq[0];
	for (i = 1; i < n; ++i)
		frequencySummator[i] = frequencySummator[i - 1] + freq[i];
	int r = (rand() % frequencySummator[n - 1]) + 1;
	int indexc = findCeil(frequencySummator, r, 0, n - 1);
	return arr[indexc];
}

char generate_name_A()
{
	char alphabet[6] = "aeiou";

	int freq[] = {82, 130, 70, 75, 28};
	int n = 5;
	return myRand(alphabet, freq, n);
}

char generate_name_B()
{
	char alphabet[22] = "bcdfghjklmnpqrstvwxyz";

	int freq[] = {15, 28, 43, 22, 20, 61,\
		1, 8, 40, 24, 67, 19, 1, 60, 63, 91, 10, 24, 1, 20, 1};
	int n = 21;
	return myRand(alphabet, freq, n);
}

std::string generate_name(){
	std::string name(7, '\0');
	if (!has_been_randomized)
		srand(time(NULL));
	has_been_randomized = 1;
	for (int i = 0; i < 6; i++){
		if (i % 2)
			name[i] = generate_name_A();
		else
			name[i] = generate_name_B();
	}
	name[0] = toupper(name[0]);
	return (name);
}

// ZOMBIE CLASS FUNCTIONS:

Zombie::Zombie(){
	this->name = generate_name();
	this->type = generate_name();
}

Zombie::~Zombie(){}

void Zombie::announce(){
	std::cout << "<" << this->name << " (" << this->type << ")>  Braiiiiiiinnnssss..." << std::endl;
}



