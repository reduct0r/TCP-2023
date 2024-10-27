#include "planets/planets.h"

using namespace std;
int sunsys::Planets::total = 0;
int main() 
{
    setlocale(LC_ALL, "Russian");

    sunsys::Planets* planets  = nullptr;
    const int N = 100;
    int n_planet = 0;
    const char* file_name = "sunsys.txt";
    int current_index = 0;
    int n_sort = 0;
    char find_name[20];

    while (true) 
    {
        switch (sunsys::menu()) 
        {
        case 1: // Чтение из файла
            planets = sunsys::CreateDynArray(file_name, n_planet);
            sunsys::read_dbase(file_name, planets, n_planet, N);
            break;

        case 2: // Запись в файл
            sunsys::write_dbase(file_name, planets, n_planet);
            break;

        case 3: // Редактирование (поиск по имени планеты)
            cout << "Введите имя необходимой для планеты: ";
            cin >> find_name;
            current_index = sunsys::find(planets, n_planet, find_name);
            sunsys::edit_object(planets, current_index);
            break;

        case 4: // Вывод на экран
            sunsys::print_dbase(planets, n_planet);
            break;

        case 5: // Удаление планеты
            cout << "Введите имя объекта для УДАЛЕНИЯ: ";
            cin >> find_name;
            current_index = sunsys::find(planets, n_planet, find_name);
            sunsys::remove_planet(planets, n_planet, current_index);
            break;

        case 6: // Сортировка
            int key, order;
            sunsys::prepare_sort(key, order);
            sunsys::sort_planets(planets, n_planet, key, order);
            break;

        case 7: // Добавить новую планету
            planets = sunsys::add_planet(planets, n_planet, N);
            break;

        case 8: // Перегрузка сортировка
            sunsys::sort_planets_overload(planets, n_planet);
            break;

        case 0: // Выход
            delete[] planets;
            return 0;

        default:
            cout << " Неправильный ввод" << endl;
            break;
        }
    }
    delete[] planets;
    return 0;
}