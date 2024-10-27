#pragma once
#include "Ship.h"

class �orvette : public Ship {
private:
    int maxSpeed;
public:
    �orvette(char* name, int waterDisplacement, int maxSpeed) : Ship(name, waterDisplacement) {
        this->maxSpeed = maxSpeed;
        std::cout << "�orvette()" << std::endl;
    }

    ~�orvette() override {
        std::cout << "~�orvette()" << std::endl;
    }

    void show() override {
        std::cout << "������" << std::endl;
        std::cout << "��������: " << name << std::endl;
        std::cout << "�������������: " << waterDisplacement << std::endl;
        std::cout << "������������ ��������: " << maxSpeed << std::endl;
    }
};