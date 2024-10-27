#pragma once
#include "Ship.h"

class Ñorvette : public Ship {
private:
    int maxSpeed;
public:
    Ñorvette(char* name, int waterDisplacement, int maxSpeed) : Ship(name, waterDisplacement) {
        this->maxSpeed = maxSpeed;
        std::cout << "Ñorvette()" << std::endl;
    }

    ~Ñorvette() override {
        std::cout << "~Ñorvette()" << std::endl;
    }

    void show() override {
        std::cout << "Êîðâåò" << std::endl;
        std::cout << "Íàçâàíèå: " << name << std::endl;
        std::cout << "Âîäîèçìåùåíèå: " << waterDisplacement << std::endl;
        std::cout << "Ìàêñèìàëüíàÿ ñêîðîñòü: " << maxSpeed << std::endl;
    }
};