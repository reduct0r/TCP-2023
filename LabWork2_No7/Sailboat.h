#pragma once
#include "Ship.h"

class Sailboat : public Ship {
private:
    int sailsArea;
public:
    Sailboat(char* name, int waterDisplacement, int sailsArea) : Ship(name, waterDisplacement) {
        this->sailsArea = sailsArea;
        std::cout << "Sailboat()" << std::endl;
    }

    ~Sailboat() override {
        std::cout << "~Sailboat()" << std::endl;
    }

    void show() override {
        std::cout << "��������" << std::endl;
        std::cout << "��������: " << name << std::endl;
        std::cout << "�������������: " << waterDisplacement << std::endl;
        std::cout << "������� �������: " << sailsArea << std::endl;
    }
};

