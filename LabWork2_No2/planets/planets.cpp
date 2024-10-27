#include "planets.h"
using namespace std;

// ����
int sunsys::menu()
{
    std::cout << std::endl;
    std::cout << " ======================== ������� ���� ========================\n";
    std::cout << "1 - ������ �� �� �����\t\t 4 - ����� �� �� �����" << std::endl;
    std::cout << "2 - ������ �� � ����\t\t 5 - �������� �� ��" << std::endl;
    std::cout << "3 - ��������������\t\t 6 - ����������" << std::endl;
    std::cout << "7 - �������� ����� ������\t 8 - C��������� �����������" << std::endl;
    std::cout << "0 - �����              \t\t 0 - �����" << std::endl;
    std::cout << "��� ������ �������� ������� ����� �� 0 �� 8" << std::endl;
    int resp;
    std::cin >> resp;
    std::cin.clear();
    std::cin.ignore(10, '\n');
    return resp;
}

// �������� ������������� ������� 
sunsys::Planets* sunsys::CreateDynArray(const char* filename, int& n)
{
    ifstream fin(filename, ios::in);
    if (!fin)
    {
        cout << "He� ����� " << filename << endl;
        exit(1);
    }
    else
    {
        fin >> n;
        sunsys::Planets* planets = new sunsys::Planets[n];
        return planets;
    }
}

// ������ �� �� �����
void sunsys::read_dbase(const char* filename, sunsys::Planets* arr, int n, const int N)
{
    int num;
    ifstream fin(filename, ios::in);
    if (!fin) 
    {
        cout << "He� ����� " << filename << endl;
    }
    fin >> num;
    if (n > N) 
    {
        cout << "������������ ��. n= " << n << endl;
    }

    for (int i = 0; i < n; i++)
    {
        fin >> arr[i];
    }
    fin.close();
    cout << "������ ���������" << endl;
}

// ����� ���� � ����
int sunsys::write_dbase(const char* filename, sunsys::Planets const* arr, int n)
{
    ofstream fout(filename, ios::out);
    if (!fout) 
    {
        cout << "������ �������� �����" << endl;
        return 1;
    }

    fout << n << '\n';

    for (int i = 0; i < n; i++)
    {
        fout << arr[i];
    }
    cout << "������� �������� � ����" << endl;
    fout.close();
    return 0;
}

// ����� ���� �� �����
void sunsys::print_dbase(sunsys::Planets const* arr, int n)
{
    cout << " ���� ������ " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << setw(3) << i + 1 << ". " << arr[i];
    }
}

// ����� ������� �� �����
int sunsys::find(sunsys::Planets* arr, int n, const char* name)
{
    int ind = -1;
    for (int i = 0; i < n; i++)
    {
        if (!strcmp(arr[i].GetName(), name)) // ����� ��� �������
        {
            cout << name << " ������� � ��" << endl;
            ind = i;
        }
    }
    return ind;
}

// �������� ������� �� �������
void sunsys::remove_planet(sunsys::Planets* arr, int& n, int index)
{
    if (index < 0 or index >= n)
    {
        cout << "������: ������ �� ������. ���������, ��� �� ������� " << endl;
        return;
    }

    // ���������� ��� �������� ����� ���������� �� ���� ������� �����
    for (int i = index; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    n--;    // ��������� ������ �������
    cout << "������ ������ �� ��" << endl;
}

// ��������������
void sunsys::edit_object(Planets* arr, int index)
{
    if (index < 0)
    {
        cout << "������: ������ �� ������. ���������, ��� �� ������� " << endl;
        return;
    }

    int choice;
    char input[50];

    do
    {
        cout << "========================================================================" << endl;
        cout << setw(3) << index + 1 << ". " << arr[index].GetName() << setw(10 - strlen(arr[index].GetName()) + 6)
            << arr[index].GetDiam() << setw(10) << arr[index].GetLife() << setw(10) << arr[index].GetSate() << endl;

        std::cout << " ======================== ���� �������������� ========================\n";
        std::cout << "1 - ������������� ���" << std::endl;
        std::cout << "2 - ������������� �������" << std::endl;
        std::cout << "3 - ������������� ������� �����" << std::endl;
        std::cout << "4 - ������������� ���-�� ���������" << std::endl;
        std::cout << "0 - ��������� ��������������" << std::endl;
        std::cout << "��� ������ �������� ������� ����� �� 1 �� 5" << std::endl;

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
            std::cout << "����� �� ���� ��������������" << endl;
            break;
        default:
            cout << " ������������ ����" << endl;
            break;
        }
    } while (choice != 0);
}

// ���������� ���������
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
                cout << "����� � ������� ����, ���������� ��������" << endl;
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
        cout << "������������� �� ��������� ��������, ����� � ������� ����" << endl;
    }
}

// ���� ����������
void sunsys::prepare_sort(int& key, int& order)
{
    bool ready = 0;
    do
    {
        std::cout << std::endl;
        std::cout << " ======================== ���� ���������� ========================\n";
        std::cout << "�������� ���� ����������" << std::endl;
        std::cout << "1 - ���" << std::endl;
        std::cout << "2 - �������" << std::endl;
        std::cout << "3 - ������� �����" << std::endl;
        std::cout << "4 - ���-�� ���������" << std::endl;
        std::cout << "0 - ����� �� ���� ����������" << std::endl;
        std::cout << "��� ������ �������� ������� ����� �� 0 �� 4" << std::endl;
        std::cin >> key;
        if (key == 0)
        {
            break;
        }

        if (key > 4 or key < 0)
        {
            std::cout << "������������ ����, ����������� � ���� ����������: ��������� �������" << std::endl;
            continue;
        }
        std::cout << "�������� ������� ����������" << std::endl;
        std::cout << "0 - �� �����������, 1 - �� ��������" << std::endl;
        std::cin >> order;
        if (order > 1 or order < 0)
        {
            std::cout << "������������ ����, ����������� � ���� ����������: ��������� �������" << std::endl;
            continue;
        }
        ready = 1;
    } while (ready != 1);
}

// �������� �������
sunsys::Planets* sunsys::add_planet(sunsys::Planets* &arr, int& n, const int N)
{
    if (n < N)
    {
        char name[100];
        int diam{};
        bool life{};
        int satellite{};


        std::cout << "������� ��� �������:";
        std::cin >> name;

        while (std::cout << "������� ������� �������: " and !(std::cin >> diam) and !diam) 
        {
            std::cin.clear(); // ������� ������������ ����
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // �������� ����
            std::cout << "�������� ����\n";
        }

      
        while (std::cout << "������� ����� (1 - ��, 0 - ���): " and !(std::cin >> life))
        {
            std::cin.clear(); // ������� ������������ ����
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // �������� ����
            std::cout << "�������� ����\n";
        }

        while (std::cout << "���������� ���������: " and !(std::cin >> satellite))
        {
            std::cin.clear(); // ������� ������������ ����
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // �������� ����
            std::cout << "�������� ����\n";
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
        std::cout << "���� ������ �����������" << std::endl;
        return arr;
    }
}

// ���������� � �������������� ����������
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
