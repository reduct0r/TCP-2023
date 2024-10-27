#pragma once
#include "Ship.h"

class Steamboat : public Ship {
private:
    int passangers;
public:
    Steamboat(char* name, int waterDisplacement, int passangers) : Ship(name, waterDisplacement) {
        this->passangers = passangers;
        std::cout << "Steamboat()" << std::endl;
    }

    ~Steamboat() override {
        std::cout << "~Steamboat()" << std::endl;
    }

    void show() override {
        std::cout << "Пароход" << std::endl;
        std::cout << "Название: " << name << std::endl;
        std::cout << "Водоизмещение:" << waterDisplacement << std::endl;
        std::cout << "Кол-во пассажирских мест: " << passangers << std::endl;
    }
};