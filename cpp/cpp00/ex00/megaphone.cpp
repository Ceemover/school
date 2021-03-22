#include <iostream>

std::string toUpperCase(char *message) {
    int stringLen = 0;

    while (message[stringLen])
        stringLen++;
    while (--stringLen > -1) {
        if (message[stringLen] >= 'a' && message[stringLen] <= 'z')
            message[stringLen] -= 32;
    }
    return message;
}


int main(int argc, char **argv)
{
    int i = 2;

    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else {
        while (i <= argc) {
            std::cout << toUpperCase(argv[i - 1]);
            i++;
        }
    }
    std::cout << std::endl;

    return 0;
}