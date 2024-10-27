#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

namespace sunsys
{
	class Planets
	{
	private:
		char* name;					// Имя
		int diam;					// Диаметр
		bool life;					// Наличие жизни
		int satellite;				// Спутники

		static int total;
		int id;

	public:
		Planets()
		{
			name = nullptr; 
			diam = life = satellite = 0;

			total++;								// увеличить счетчик объектов
			id = total;								// id равен текущему значению total
			std::cout << "Создание ID " << id << std::endl;
		}

		Planets(char* planetName, int diameter, bool hasLife, int numSatellites, int idf) :
			name(planetName), diam(diameter), life(hasLife), satellite(numSatellites), id(idf) {}

		~Planets()
		{
			delete[] name;

			total--;
			std::cout << "Удаление ID " << id << std::endl;
		}

		Planets& operator=(const Planets& other)
		{
			if (this != &other)
			{
				delete[] name;								// Освобождаем память для текущей строки name
				name = new char[strlen(other.name) + 1];	// Выделяем память для новой строки name
				strcpy(name, other.name);					// Копируем значение из строки other.name в строку name
				// Копирование других полей класса
				diam = other.diam;
				life = other.life;
				satellite = other.satellite;
				id = other.id;
			}
			return *this;
		}

		friend std::ostream& operator<<(std::ostream& out, const Planets& obj)
		{
			out << obj.name << std::setw(20 - strlen(obj.name) + 6) << obj.diam << std::setw(10) << obj.life << std::setw(10) << obj.satellite << '\n';
			return out;
		}

		friend std::istream& operator>>(std::istream& in, Planets& planet) 
		{
			const int initialSize = 5;					// Начальный размер для имени планеты
			char* temp_name = new char[initialSize];
			int size = initialSize;
			int length = 0;
			char c;
			in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			while (in.get(c) and c != ' ' and c != '\t')
			{
				temp_name[length] = c;
				length++;

				if (length == size) 
				{
					size *= 2;
					char* temp = new char[size];
					for (int j = 0; j < length; j++) 
					{
						temp[j] = temp_name[j];
					}
					delete[] temp_name;
					temp_name = temp;
				}
			}
			temp_name[length] = '\0';	// Конец строки

			delete[] planet.name; 
			planet.name = temp_name;
			
			in >> planet.diam >> planet.life >> planet.satellite;

			return in;
		}

		// Перегрузки для сортировки
		bool operator<(const Planets& other) const 
		{
			return diam < other.diam;
		}

		bool operator==(const Planets& other) const 
		{
			return diam == other.diam;
		}

		char* GetName() { return name; }
		int GetDiam() const { return diam; }
		bool GetLife() const { return life; }
		int GetSate() const { return satellite; }

		void SetName(const char* name)
		{
			delete[] this->name;
			this->name = new char[strlen(name) + 1];
			strncpy(this->name, name, strlen(name) + 1);
		}
		void SetDiam(int diam) { this->diam = diam; }
		void SetLife(bool life) { this->life = life; }
		void SetSate(int satellite) { this->satellite = satellite; }
	};

	int menu();
	void read_dbase(const char* filename, sunsys::Planets* arr, int n, const int N);
	int write_dbase(const char* filename, sunsys::Planets const* arr, int n);
	void print_dbase(sunsys::Planets const* arr, int n);
	int find(sunsys::Planets* arr, int n, const char* name);
	void remove_planet(sunsys::Planets* arr, int& n, int index);
	void edit_object(Planets* arr, int index);
	void sort_planets(Planets* arr, int size, int key, int order);
	void prepare_sort(int& key, int& order);
	void sort_planets_overload(Planets* arr, int n);
	Planets* add_planet(sunsys::Planets* &arr, int& n, const int N);
	Planets* CreateDynArray(const char* filename, int& n);
}