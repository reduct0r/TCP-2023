#include <iostream>
#include <cmath>

const int MAX_SIZE = 5;

template <typename T>
class MyVector
{
protected:
	size_t max_size;
	size_t size;
	T* pdata;

public:
	MyVector(T el = NULL , int max_size = MAX_SIZE);
	MyVector(MyVector& vecToCopy);
	~MyVector();

	void add_element(T el);
	bool delete_element(int index);
	size_t find(T el);
	void resize();
	void sort();
	size_t get_size() { return size; }
	size_t get_max_size() { return max_size; }

	MyVector& operator=(MyVector& v);
	char* operator[](int i);

	template<typename T>
	friend std::ostream& operator<<(std::ostream& out, const MyVector<T>& v);
};

size_t CalculateNewSize(int size, int max_size)
{
	if (size == max_size || size * 4 == max_size)
	{
		return std::max(size * 2, MAX_SIZE);
	}
	return max_size;
}


// resize
template <typename T>
void MyVector<T>::resize()
{
	size_t new_size = CalculateNewSize(this->size, this->max_size);
	if (new_size == this->max_size)
	{
		return;
	}
	T* temp = new T[new_size];

	for (size_t i = 0; i < size; i++)
	{
		temp[i] = this->pdata[i];
	}

	delete[] this->pdata;
	this->pdata = temp;
	this->max_size = new_size;
}

template <>
void MyVector<char*>::resize()
{
	size_t new_size = CalculateNewSize(this->size, this->max_size);
	if (new_size == this->max_size)
	{
		return;
	}
	char** temp = new char* [new_size];

	for (size_t i = 0; i < size; i++)
	{
		temp[i] = new char[strlen(this->pdata[i]) + 1];
		strcpy(temp[i], this->pdata[i]);

		delete[] this->pdata[i];
	}

	delete[] this->pdata;
	this->pdata = temp;
	this->max_size = new_size;
}

// add el
template<typename T>
void MyVector<T>::add_element(T el)
{
	resize();
	this->pdata[this->size] = el;
	this->size++;
}

template<>
void MyVector<char*>::add_element(char* el)
{
	resize();
	this->pdata[this->size] = new char[strlen(el) + 1];
	strcpy(this->pdata[this->size], el);
	this->size++;
}

// Конструктор
template <typename T>
MyVector<T>::MyVector(T el, int max_size)
{
	this->size = 0;
	this->max_size = max_size;
	this->pdata = new T[max_size];
	if (el)
	{
		add_element(el);
	}
}

template <>
MyVector<char*>::MyVector(char* el, int max_size)
{
	this->size = 0;
	this->max_size = max_size;
	this->pdata = new char* [max_size];
	if (el)
	{
		add_element(el);
	}
}

// Деструктор
template <typename T>
MyVector<T>::~MyVector()
{
	delete[] this->pdata;
}

template <>
MyVector<char*>::~MyVector()
{
	for (size_t i = 0; i < size; i++)
	{
		delete[] pdata[i];
	}
	delete[] pdata;
}

// К Копирования
template <typename T>
MyVector<T>::MyVector(MyVector& vecToCopy)
{
	this->max_size = vecToCopy.max_size;
	this->size = vecToCopy.size;
	this->pdata = new T[this->max_size];
	for (size_t i = 0; i < this->size; i++)
	{
		this->pdata[i] = vecToCopy.pdata[i];
	}
}

template <>
MyVector<char*>::MyVector(MyVector& vecToCopy)
{
	this->max_size = vecToCopy.max_size;
	this->size = vecToCopy.size;
	this->pdata = new char* [this->max_size];
	for (size_t i = 0; i < this->size; i++)
	{
		this->pdata[i] = new char[strlen(vecToCopy.pdata[i]) + 1];
		strcpy(this->pdata[i], vecToCopy.pdata[i]);
	}
}

// удаление
template<typename T>
bool MyVector<T>::delete_element(int index)
{
	if (index >= this->size || index < 0) {
		return false;
	}
	for (size_t i = index; i < this->size - 1; i++) {
		this->pdata[i] = this->pdata[i + 1];
	}
	this->size--;
	resize();
	return true;
}

template<>
bool MyVector<char*>::delete_element(int index)
{
	if (index >= this->size || index < 0)
	{
		return false;
	}
	delete[] this->pdata[index];

	for (size_t i = index; i < this->size - 1; i++)
	{
		this->pdata[i] = this->pdata[i + 1];
	}
	this->size--;
	resize();
	return true;
}

// поиск
template<typename T>
size_t MyVector<T>::find(T el)
{
	for (size_t i = 0; i < this->size; i++) {
		if (el == pdata[i]) {
			return i;
		}
	}
	return -1;
}

template<>
size_t MyVector<char*>::find(char* el)
{
	for (size_t i = 0; i < this->size; i++) {
		if (el == pdata[i]) {
			return i;
		}
	}
	return -1;
}

// сортировка
template <typename T>
void MyVector<T>::sort()
{
	for (size_t i = 0; i < size; i++) 
	{
		for (size_t j = 0; j < size - 1; j++) 
		{
			if (pdata[j] > pdata[j + 1]) {
				std::swap(pdata[j], pdata[j + 1]);
			}
		}
	}
}

template <>
void MyVector<char*>::sort()
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size - 1; j++)
		{
			if (strcmp(pdata[j], pdata[j + 1])) //str
			{
				std::swap(pdata[j], pdata[j + 1]);
			}
		}
	}
}


/* Перегрузки операторов */
template<typename T>
MyVector<T>& MyVector<T>::operator=(MyVector& v)
{
	if (this != &v) 
	{
		for (size_t i = 0; i < this->size; i++) // удаление левой части
		{
			delete[] this->pdata[i];
		}
		//delete[] this->pdata;

		this->size = v.size;
		this->max_size = v.max_size;
		this->pdata = new DATA[this->max_size];
		for (size_t i = 0; i < this->size; i++) 
		{
			this->pdata[i] = v.pdata[i];
		}
	}
	return *this;
}

template<typename T>
char* MyVector<T>::operator[](int i)
{
	return this->pdata[i];
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const MyVector<T>& v)
{
	for (size_t i = 0; i < v.size; ++i) 
	{
		out << v.pdata[i] << " ";
	}
	return out;
}

/* Перегрузки операторов */
template<>
MyVector<char*>& MyVector<char*>::operator=(MyVector& v)
{
	if (this != &v)
	{
		for (size_t i = 0; i < this->size; i++) // удаление левой части
		{
			delete[] this->pdata[i];
		}
		delete[] this->pdata;

		this->size = v.size;
		this->max_size = v.max_size;
		this->pdata = new char* [this->max_size];

		for (size_t i = 0; i < this->size; i++)
		{
			this->pdata[i] = new char[strlen(v.pdata[i]) + 1]; // +1 \n
			strcpy(this->pdata[i], v.pdata[i]);
		}
	}
	return *this;
}


template<>
char* MyVector<char*>::operator[](int i)
{
	return this->pdata[i];
}

template<>
std::ostream& operator<<(std::ostream& out, const MyVector<char*>& v)
{
	for (size_t i = 0; i < v.size; ++i)
	{
		out << v.pdata[i] << " ";
	}
	return out;
}