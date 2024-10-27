// lab1.cpp: определяет точку входа для приложения.
#include <iostream>
#include "mymath/mymath.h"
#include "mylib/mylib.h"

int interactive();

int demo();

int main(int argc, char* argv[]) 
{
    setlocale(LC_ALL, "Russian");
    bool isInteractive = false;    // по умолчанию демо-режим.

    // Если i передается в качестве аргумента, то программу
    // необходимо запустить в интерактивном режиме

    if ((argc == 2) && strcmp(argv[1], "i") == 0) 
    {
        isInteractive = true;
    }

    if (isInteractive) 
    {
        return interactive();

    }
    else 
    {
        return demo();
    }
}

int interactive()
{
    int a = 0, b = 0;
    std::cout << "Введите первое число: ";
    std::cin >> a;
    std::cout << "\n Введите второе число: ";
    std::cin >> b;
    std::cout << "\n Сумма: ";
    std::cout << mymath::sum(a, b) << std::endl;

    std::cout << "\n Произведение: ";
    std::cout << mylib::mult(a, b) << std::endl;

    system("pause");
    return 0;
}

int demo()
{
    std::cout << "Я умею суммировать! Зацени 10+32=";
    std::cout << mymath::sum(10, 32) << std::endl;

    std::cout << "Я умею умнжать! Зацени 10*32=";
    std::cout << mylib::mult(10, 32) << std::endl;
    system("pause");
    return 0;
}