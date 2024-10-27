#include "planets.h"
using namespace std;

// Меню
int sunsys::menu()
{
    std::cout << std::endl;
    std::cout << " ======================== ГЛАВНОЕ МЕНЮ ========================\n";
    std::cout << "1 - Чтение БД из файла\t\t 4 - Вывод БД на экран" << std::endl;
    std::cout << "2 - Запись БД в файл\t\t 5 - Удаление из БД" << std::endl;
    std::cout << "3 - Редактирование\t\t 6 - Сортировка" << std::endl;
    std::cout << "7 - Добавить новый объект\t 8 - Cортировка перегрузкой" << std::endl;
    std::cout << "0 - ВЫХОД              \t\t 0 - ВЫХОД" << std::endl;
    std::cout << "Для выбора операции введите цифру от 0 до 8" << std::endl;
    int resp;
    std::cin >> resp;
    std::cin.clear();
    std::cin.ignore(10, '\n');
    return resp;
}

// Создание динамического массива 
sunsys::Planets* sunsys::CreateDynArray(const char* filename, int& n)
{
    ifstream fin(filename, ios::in);
    if (!fin)
    {
        cout << "Heт файла " << filename << endl;
        exit(1);
    }
    else
    {
        fin >> n;
        sunsys::Planets* planets = new sunsys::Planets[n];
        return planets;
    }
}

// Чтение БД из файла
void sunsys::read_dbase(const char* filename, sunsys::Planets* arr, int n, const int N)
{
    int num;
    ifstream fin(filename, ios::in);
    if (!fin) 
    {
        cout << "Heт файла " << filename << endl;
    }
    fin >> num;
    if (n > N) 
    {
        cout << "Переполнение БД. n= " << n << endl;
    }

    for (int i = 0; i < n; i++)
    {
        fin >> arr[i];
    }
    fin.close();
    cout << "Чтение завершено" << endl;
}

// Вывод базы в файл
int sunsys::write_dbase(const char* filename, sunsys::Planets const* arr, int n)
{
    ofstream fout(filename, ios::out);
    if (!fout) 
    {
        cout << "Ошибка открытия файла" << endl;
        return 1;
    }

    fout << n << '\n';

    for (int i = 0; i < n; i++)
    {
        fout << arr[i];
    }
    cout << "Успешно записано в файл" << endl;
    fout.close();
    return 0;
}

// Вывод базы на экран
void sunsys::print_dbase(sunsys::Planets const* arr, int n)
{
    cout << " База Данных " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << setw(3) << i + 1 << ". " << arr[i];
    }
}

// Поиск планеты по имени
int sunsys::find(sunsys::Planets* arr, int n, const char* name)
{
    int ind = -1;
    for (int i = 0; i < n; i++)
    {
        if (!strcmp(arr[i].GetName(), name)) // Когда имя совпало
        {
            cout << name << " найдено в БД" << endl;
            ind = i;
        }
    }
    return ind;
}

// Удаление объекта по индексу
void sunsys::remove_planet(sunsys::Planets* arr, int& n, int index)
{
    if (index < 0 or index >= n)
    {
        cout << "Ошибка: Объект не найден. Убедитесь, что БД считана " << endl;
        return;
    }

    // Перемещаем все элементы после удаляемого на одну позицию влево
    for (int i = index; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    n--;    // Уменьшаем размер массива
    cout << "Объект удален из БД" << endl;
}

// Редактирование
void sunsys::edit_object(Planets* arr, int index)
{
    if (index < 0)
    {
        cout << "Ошибка: Объект не найден. Убедитесь, что БД считана " << endl;
        return;
    }

    int choice;
    char input[50];

    do
    {
        cout << "========================================================================" << endl;
        cout << setw(3) << index + 1 << ". " << arr[index].GetName() << setw(10 - strlen(arr[index].GetName()) + 6)
            << arr[index].GetDiam() << setw(10) << arr[index].GetLife() << setw(10) << arr[index].GetSate() << endl;

        std::cout << " ======================== МЕНЮ РЕДАКТИРОВАНИЯ ========================\n";
        std::cout << "1 - Редактировать имя" << std::endl;
        std::cout << "2 - Редактировать диаметр" << std::endl;
        std::cout << "3 - Редактировать наличие жизни" << std::endl;
        std::cout << "4 - Редактировать кол-во спутников" << std::endl;
        std::cout << "0 - ЗАКОНЧИТЬ редактирвоание" << std::endl;
        std::cout << "Для выбора операции введите цифру от 1 до 5" << std::endl;

        std::cin >> choice;
        switch (choice)
        {
        case 1:
            std::cout << "Enter new name: ";
            std::cin >> input;
            arr[index].SetName(input);
            break;
        case 2:
            std::cout << "Enter new diameter: ";
            std::cin >> input;
            arr[index].SetDiam(atoi(input));
            break;
        case 3:
            std::cout << "Enter new life status (0 for false, 1 for true): ";
            std::cin >> input;
            arr[index].SetLife(atoi(input));
            break;
        case 4:
            std::cout << "Enter new number of satellites: ";
            std::cin >> input;
            arr[index].SetSate(atoi(input));
            break;
        case 0:
            std::cout << "Выход из меню редактирования" << endl;
            break;
        default:
            cout << " Неправильный ввод" << endl;
            break;
        }
    } while (choice != 0);
}

// Сортировка пузырьком
void sunsys::sort_planets(Planets* arr, int size, int key, int order)
{
    sunsys::Planets temp;
    bool stop = 0;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            switch (key)
            {
            case 1:
                if (order == 0)
                {
                    if (strcmp(arr[j].GetName(), arr[j + 1].GetName()) > 0)
                    {
                     
                        temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;

                    }
                }
                else
                {
                    if (strcmp(arr[j].GetName(), arr[j + 1].GetName()) < 0)
                    {
                        temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
                break;

            case 2:
                if (order == 0)
                {
                    if (arr[j].GetDiam() > arr[j + 1].GetDiam())
                    {
                        temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
                else
                {
                    if (arr[j].GetDiam() < arr[j + 1].GetDiam())
                    {
                        temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
                break;

            case 3:
                if (order == 0)
                {
                    if (int(arr[j].GetLife()) > int(arr[j + 1].GetLife()))
                    {
                        temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
                else
                {
                    if (int(arr[j].GetLife()) < int(arr[j + 1].GetLife()))
                    {
                        temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
                break;

            case 4:
                if (order == 0)
                {
                    if (arr[j].GetSate() > arr[j + 1].GetSate())
                    {
                        temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
                else
                {
                    if (arr[j].GetSate() < arr[j + 1].GetSate())
                    {
                        temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
                break;
            case 0:
                stop = 1;
                cout << "Выход в ГЛАВНОЕ МЕНЮ, сортировка ОТМЕНЕНА" << endl;
                break;
            }
        if (stop)
        {
            break;
        }
        }
    if (stop)
    {
        break;
    }
    }
    if (key != 0)
    {
        cout << "Отсортировано по выбранным условиям, выход в ГЛАВНОЕ МЕНЮ" << endl;
    }
}

// Меню сортировки
void sunsys::prepare_sort(int& key, int& order)
{
    bool ready = 0;
    do
    {
        std::cout << std::endl;
        std::cout << " ======================== МЕНЮ СОРТИРОВКИ ========================\n";
        std::cout << "Выберите ключ сортировки" << std::endl;
        std::cout << "1 - Имя" << std::endl;
        std::cout << "2 - Диаметр" << std::endl;
        std::cout << "3 - Наличие жизни" << std::endl;
        std::cout << "4 - Кол-во спутников" << std::endl;
        std::cout << "0 - ВЫЙТИ из меню сортировки" << std::endl;
        std::cout << "Для выбора операции введите цифру от 0 до 4" << std::endl;
        std::cin >> key;
        if (key == 0)
        {
            break;
        }

        if (key > 4 or key < 0)
        {
            std::cout << "Некорректный ввод, возвращение в меню сортировки: повторите попытку" << std::endl;
            continue;
        }
        std::cout << "Выберите порядок сортировки" << std::endl;
        std::cout << "0 - по возрастанию, 1 - по убыванию" << std::endl;
        std::cin >> order;
        if (order > 1 or order < 0)
        {
            std::cout << "Некорректный ввод, возвращение в меню сортировки: повторите попытку" << std::endl;
            continue;
        }
        ready = 1;
    } while (ready != 1);
}

// Добавить элемент
sunsys::Planets* sunsys::add_planet(sunsys::Planets* &arr, int& n, const int N)
{
    if (n < N)
    {
        char name[100];
        int diam{};
        bool life{};
        int satellite{};


        std::cout << "Введите имя планеты:";
        std::cin >> name;

        while (std::cout << "Введите диаметр планеты: " and !(std::cin >> diam) and !diam) 
        {
            std::cin.clear(); // Удалить некорректный ввод
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Отменить ввод
            std::cout << "Неверный ввод\n";
        }

      
        while (std::cout << "Наличие жизни (1 - да, 0 - нет): " and !(std::cin >> life))
        {
            std::cin.clear(); // Удалить некорректный ввод
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Отменить ввод
            std::cout << "Неверный ввод\n";
        }

        while (std::cout << "Количество спутников: " and !(std::cin >> satellite))
        {
            std::cin.clear(); // Удалить некорректный ввод
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Отменить ввод
            std::cout << "Неверный ввод\n";
        }

        sunsys::Planets* newPlanets = new sunsys::Planets[n + 1];

        for (int i = 0; i < n; ++i)
        {
            newPlanets[i] = arr[i];
        }

        delete[] arr;
        arr = newPlanets;

        arr[n].SetName(name);
        arr[n].SetDiam(diam);
        arr[n].SetLife(life);
        arr[n].SetSate(satellite);

        n += 1;
        return arr;
    }
    else
    {
        std::cout << "База данных переполнена" << std::endl;
        return arr;
    }
}

// Сортировка с использованием перегрузки
void sunsys::sort_planets_overload(Planets* arr, int n)
{
    sunsys::Planets temp;
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] < arr[j + 1]) 
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
