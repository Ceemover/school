#include "Contacts.hpp"

Contacts::Contacts() {
	set = 0;
}
Contacts::~Contacts(){}

int Contacts::isSet() {
	return set;
}
void Contacts::setContact()
{
    int i = 0;
    this->set=1;

    std::string *arr[10] = {&firstName, &lastName, &nickName, &login, \
            &postalAddress, &phoneNumber, &birthdayDate, &favoriteMeal, &underwearColor, &darkestSecret};

    std::string names[10] = {"First name: ", "Last name: ", "Nickname: ", "Login: ", "Postal address: ", \
            "Phone number: ", "Birthday date: ", "Favorite meal: ", "Underwear color: ", "Darkest secret: "};

    while (i < 10) {
        std::cout << names[i];
        if (!getInput(*(arr[i])))
            continue;
        i++;
    }
}

std::string Contacts::getContactFirstName(){
	return firstName;
}
std::string Contacts::getContactLastName(){
    	return lastName;
}
std::string Contacts::getContactNickname(){
    	return nickName;
}

void     Contacts::printContactInfo() {
	std::cout << "First name: ";
	std::cout << firstName << std::endl;
	std::cout << "Last name: ";
	std::cout << lastName << std::endl;
	std::cout << "Nickname: ";
	std::cout << nickName << std::endl;
	std::cout << "Login: ";
	std::cout << login << std::endl;
	std::cout << "Postal address: ";
	std::cout << postalAddress << std::endl;
	std::cout << "Phone number: ";
	std::cout << phoneNumber << std::endl;
	std::cout << "Birthday date: ";
	std::cout << birthdayDate << std::endl;
	std::cout << "Favorite meal: ";
	std::cout << favoriteMeal << std::endl;
	std::cout << "Underwear color: ";
	std::cout << underwearColor << std::endl;
	std::cout << "Darkest secret: ";
	std::cout << darkestSecret << std::endl;
}

void Contacts::printSearch(int i){
	std::cout << std::setw(10) << (i + 1) << '|';
	std::cout << std::setw(10) << truncate_to_10(firstName) << '|';
	std::cout << std::setw(10) << truncate_to_10(lastName) << '|';
	std::cout << std::setw(10) << truncate_to_10(nickName) << std::endl;
}