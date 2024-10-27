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
        std::cout << "�������" << std::endl;
        std::cout << "��������: " << name << std::endl;
        std::cout << "�������������:" << waterDisplacement << std::endl;
        std::cout << "���-�� ������������ ����: " << passangers << std::endl;
    }
};