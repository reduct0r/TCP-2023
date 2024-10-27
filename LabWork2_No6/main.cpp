#include "polinom/polinom.h"
#include <iostream>
#include <cstring>

// Включите необходимые заголовки и используйте правильные пространства имен

int main()
{
    std::setlocale(LC_ALL, "Russian");
    char inter[200];
    std::cout << "Введите 'd' - для демонстрационного режима или 'i' - для интерактивного: ";
    std::cin >> inter;

    // Игнорируем оставшийся символ новой строки в буфере
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (inter[0] == 'd')
    {
        MyVector<Term> terms;
        char str[] = "3x^2 - 4x + 5 + 3x^2";
        std::cout << str << "\n";

        // Разбор строки и заполнение вектора термами
        Term::parseTerms(str, terms);
        Polynomial poly(terms);
        std::cout << poly;
    }
    else
    {
        std::cout << "Введите терм: ";
        Term term;
        std::cin >> term;
        std::cout << term;

        std::cout << "\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Введите полином: ";
        Polynomial poly;
        std::cin >> poly;
        std::cout << poly;
    }
    return 0;
}
