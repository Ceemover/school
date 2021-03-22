#pragma once

#include <iostream>
#include <iomanip>

class Pony{
public:
    std::string age;
    std::string height_cm;
    std::string name;
    Pony();
    ~Pony();
};

void ponyOnTheHeap();
void ponyOnTheStack();