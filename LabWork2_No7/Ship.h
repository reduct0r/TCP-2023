#pragma once
#include <iostream>

class Ship {
protected:
    char* name;
    int waterDisplacement;

public:
    explicit  Ship(char* name, int waterDisplacement) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->waterDisplacement = waterDisplacement;
        std::cout << "Ship()" << std::endl;
    }

    virtual ~Ship() {
        std::cout << "~Ship()" << std::endl;
        delete[] name;
    };

    virtual void show() = 0;
};
