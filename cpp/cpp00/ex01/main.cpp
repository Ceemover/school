#include "Contacts.hpp"

int     searchContacts(Contacts people[], int people_added)
{
    int i = 0;
    int index_wanted;
    std::string to_print;
    std::string input;

    if (!people_added) {
        std::cout << "No people have been added yet\n";
        return (0);
    }

    while (i < people_added){
    	people[i].printSearch(i);
        i++;
    }

    while (1) {
        std::cout << "Contact index: ";
        if (!getInput(input))
                continue;
        if (!is_number(input))
            std::cout << "Not a number" << std::endl;
        else {
            if (!is_bigger_than_9(input))
                index_wanted = std::stoi(input, nullptr, 10);
            if (is_bigger_than_9(input) || index_wanted < 1 || index_wanted > people_added) {
                std::cout << "The index should be in the range from 1 to the number of people added: " << people_added << ". Try another one? (y/n)  ";
                if (!getInput(input))
                    continue;;
                if (input.compare("y")) {
                    if (input.compare("n"))
                        std::cout << "Misleading entry. Exiting index search" << std::endl;
                    return (0);
                }
            }
            else {
                people[index_wanted - 1].printContactInfo();
                return (0);
            }
        }
    }
}

int main(void)
{
    int next_empty_index = 0;
    std::string input;

    Contacts people[PEOPLE_MAX];

    while (1) {
        std::cout << "Please type ADD, SEARCH, or EXIT : ";
        if (!getInput(input) || (input.compare("ADD") && input.compare("SEARCH") && input.compare("EXIT")))
            continue;
        else if (!input.compare("ADD")) {
            if ((next_empty_index = arr_length(people)) < PEOPLE_MAX)
                people[next_empty_index].setContact();
            else
                std::cout << "Maximum number of contacts has been reached, the limit is: " << PEOPLE_MAX << std::endl;
        }
        else if (!input.compare("SEARCH"))
            searchContacts(people, arr_length(people));
        else if (!input.compare("EXIT"))
            return (0);
    }
}

