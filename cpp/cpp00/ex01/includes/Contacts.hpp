#pragma once
#include <iostream>
#include <iomanip>
#define PEOPLE_MAX 8

class Contacts{
private:
    int         set;
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string login;
    std::string postalAddress;
    std::string phoneNumber;
    std::string birthdayDate;
    std::string favoriteMeal;
    std::string underwearColor;
    std::string darkestSecret;

public:
    void setContact();
	int isSet();
    std::string getContactFirstName();
	std::string getContactLastName();
	std::string getContactNickname();
	void printContactInfo();
	void printSearch(int i);
	Contacts();
	~Contacts();
};

int arr_length(Contacts people[]);
int getInput(std::string &input);
std::string truncate_to_10(std::string str);
bool is_number(const std::string& s);
bool is_bigger_than_9(std::string s);
