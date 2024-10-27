#include <iostream>
#include "MyVector/MyVector.h"
#include "Ship.h"
#include "Steamboat.h"
#include "Sailboat.h"
#include "Сorvette.h"

static void print(MyVector<Ship*>& ships) {
    std::cout << "\n";
    for (int i = 0; i < ships.get_size(); i++) {
        std::cout << "Индекс судна: " << i << std::endl;
        ships[i]->show();
        std::cout << std::endl;
    }
}

static void remove(MyVector<Ship*>& ships, int index) {
    ships.delete_element(index);
}

static void clear(MyVector<Ship*>& ships) {
    while (ships.get_size() > 0) {
        ships.delete_element(0);
    }
}

static void add_ship_interactive(MyVector<Ship*>& ships) {
    int choice;
    std::string name;
    int displacement, some_other_param;

    std::cout << "Выберите тип судна (1 - Steamboat, 2 - Sailboat, 3 - Сorvette): ";
    std::cin >> choice;

    std::cout << "Введите имя судна: ";
    std::cin >> name;

    std::cout << "Введите водоизмещение: ";
    std::cin >> displacement;

    switch (choice) {
    case 1:
        std::cout << "Введите количество пассажиров: ";
        break;
    case 2:
        std::cout << "Введите площадь парусов: ";
        break;
    case 3:
        std::cout << "Введите максимальную скорость: ";
        break;
    default:
        std::cout << "Неверный выбор!" << std::endl;
        exit(1);
    }

    std::cin >> some_other_param;

    switch (choice) {
    case 1:
        ships.add_element(new Steamboat((char*)name.c_str(), displacement, some_other_param));
        break;
    case 2:
        ships.add_element(new Sailboat((char*)name.c_str(), displacement, some_other_param));
        break;
    case 3:
    {
        ships.add_element(new Сorvette((char*)name.c_str(), displacement, some_other_param));
        break;
    }
    default:
        std::cout << "Неверный выбор!" << std::endl;
        exit(1);
    }

}

static void interactive_mode() {
    MyVector<Ship*> ships;
    int choice;
    int index;

    while (true) {
        std::cout << "Меню:\n";
        std::cout << "1. Добавить судно\n";
        std::cout << "2. Печать судов\n";
        std::cout << "3. Удалить судно\n";
        std::cout << "4. Очистить все суда\n";
        std::cout << "5. Выйти\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            add_ship_interactive(ships);
            break;
        case 2:
            print(ships);
            break;
        case 3:
            std::cout << "Введите индекс судна для удаления: ";
            std::cin >> index;

            if (index >= 0 && index < ships.get_size()) {
                remove(ships, index);
            }
            else {
                std::cout << "Неверный индекс!" << std::endl;
            }
            break;
        case 4:
            clear(ships);
            break;
        case 5:
            clear(ships);
            return;
        default:
            std::cout << "Неверный выбор!" << std::endl;
        }
    }
}

static void demo_mode() {
    MyVector<Ship*> ships;

    ships.add_element(new Steamboat((char*)"Aurora", 1500, 30));
    ships.add_element(new Steamboat((char*)"Emperor", 1800, 35));
    ships.add_element(new Sailboat((char*)"Seabreeze", 3500, 50));
    ships.add_element(new Sailboat((char*)"Windrider", 4200, 55));
    ships.add_element(new Сorvette((char*)"Vigilant", 2500, 40));
    ships.add_element(new Сorvette((char*)"Defender", 2700, 45));

    std::cout << "Демонстрация работы функции print:\n";
    print(ships);

    std::cout << "Демонстрация работы функции remove (удаление судна с индексом 2):\n";
    remove(ships, 2);
    print(ships);

    std::cout << "Демонстрация работы функции clear (очистка всех судов):\n";
    clear(ships);
}

int main() {
    setlocale(LC_ALL, "Russian");
    int mode;

    std::cout << "Выберите режим работы (1 - интерактивный, 2 - демонстрационный): ";
    std::cin >> mode;

    if (mode == 1) {
        interactive_mode();
    }
    else if (mode == 2) {
        demo_mode();
    }
    else {
        std::cout << "Неверный выбор!" << std::endl;
    }

    return 0;
}
