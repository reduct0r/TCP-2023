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
        std::cout << "Парусник" << std::endl;
        std::cout << "Название: " << name << std::endl;
        std::cout << "Водризмещение: " << waterDisplacement << std::endl;
        std::cout << "Площадь парусов: " << sailsArea << std::endl;
    }
};

