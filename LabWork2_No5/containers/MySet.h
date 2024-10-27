#include "MyVector.h"

template <typename T>
class MySet : public MyVector<T>
{
public:
    //MySet(char* el = NULL) : MyVector(el) {};
    MySet(T el = 0) : MyVector<T>(el) {};
	bool operator==(MySet& s);
	MySet& operator+=(MySet& s);
	MySet& operator-=(MySet& s);
	MySet& operator*=(MySet& s);

	void add_element(T el);
	void delete_element(T el);
	bool is_element(T el);

    friend std::ostream& operator<< <> (std::ostream& out, MySet<T>& s);

    template<typename T>
    friend MySet<T> operator+(MySet<T>& s1, MySet<T>& s2);

    template<typename T>
    friend MySet<T> operator-(MySet<T>& s1, MySet<T>& s2);

    template<typename T>
    friend MySet<T> operator* (MySet<T>& s1, MySet<T>& s2);

};

template <typename T>
std::ostream& operator<<<>(std::ostream& out, MySet<T>& s)
{
    out << "{ ";
    for (size_t i = 0; i < s.size; i++) {
        out << s.pdata[i] << ' ';
    }
    out << '}';
    return out;
}

void MySet<char*>::delete_element(char* el)
{
    size_t index = find(el);
    if (index != -1) {
        std::copy(this->pdata + index + 1, this->pdata + this->size, this->pdata + index);
        this->size--;
    }
}

template <typename T>
bool MySet<T>::operator==(MySet<T>& s)
{
    if (this->size != s.size)
        return false;

    for (size_t i = 0; i < this->size; ++i) {
        if (!this->is_element(s[i]))
            return false;
    }
    return true;
}

template <typename T>
MySet<T>& MySet<T>::operator+=(MySet<T>& s)
{
    for (size_t i = 0; i < s.size; ++i)
        this->add_element(s[i]);
    return *this;
}

template <typename T>
MySet<T>& MySet<T>::operator-=(MySet<T>& s)
{
    for (size_t i = 0; i < s.size; ++i)
        this->delete_element(s[i]);
    return *this;
}

template <typename T>
MySet<T>& MySet<T>::operator*=(MySet<T>& s)
{
    for (size_t i = 0; i < this->size; ++i) {
        if (!s.is_element((*this)[i]))
            this->delete_element((*this)[i]);
    }
    return *this;
}

template <typename T>
void MySet<T>::add_element(T el)
{
    if (is_element(el)) 
    {
        return;
    }

    MyVector<T>::add_element(el);
    this->sort();
}

template <typename T>
void MySet<T>::delete_element(T el)
{
    size_t index = find(el);
    if (index != -1) {
        std::copy(this->pdata + index + 1, this->pdata + this->size, this->pdata + index);
        this->size--;
    }
}

template <typename T>
bool MySet<T>::is_element(T el) 
{
    for (size_t i = 0; i < this->size; ++i) 
    {
        if (this->pdata[i] == el)
            return true;
    }
    return false;
}

template <>
bool MySet<char*>::is_element(char* el)
{
    for (size_t i = 0; i < this->size; ++i)
    {
        if (strcmp(this->pdata[i], el) == 0)
            return true;
    }
    return false;
}


template <typename T>
MySet<T> operator+(MySet<T>& s1, MySet<T>& s2)
{
    MySet set(s1);
    for (size_t i = 0; i < s2.size; i++) 
    {
        set.add_element(s2.pdata[i]);
    }
    return set;
}

template<typename T>
MySet<T> operator-(MySet<T>& s1, MySet<T>& s2) 
{
    MySet<T> set(s1);
    for (size_t i = 0; i < s2.size; i++) 
    {
        set.delete_element(s2.pdata[i]);
    }

    return set;
}

template <typename T>
MySet<T> operator* (MySet<T>& s1, MySet<T>& s2)
{
    MySet<T> set;
    for (size_t i1 = 0, i2 = 0; i1 < s1.size && i2 < s2.size;) {
        if (s1.pdata[i1] != s2.pdata[i2]) {
            if (s1.pdata[i1] < s2.pdata[i2]) {
                i1++;
            }
            else {
                i2++;
            }
        }
        else {
            set.add_element(s1.pdata[i1]);
            i1++, i2++;
        }
    }
    return set;
}

template<>
MySet<char*> operator*(MySet<char*>& s1, MySet<char*>& s2) 
{
    MySet<char*> set;
    for (size_t i1 = 0, i2 = 0; i1 < s1.size && i2 < s2.size;) 
    {
        if (strcmp(s1.pdata[i1], s2.pdata[i2]) != 0) 
        {
            if (strcmp(s1.pdata[i1], s2.pdata[i2]) < 0) 
            {
                i1++;
            }
            else 
            {
                i2++;
            }
        }
        else {
            set.add_element(s1.pdata[i1]);
            i1++, i2++;
        }
    }
    return set;
}

template <typename T>
MySet<T> operator*(MySet<T>& s2) 
{
    MySet set{};
    for (size_t i1 = 0, i2 = 0; i1 < this->size && i2 < s2.size;) {
        if (this->pdata[i1] != s2.pdata[i2]) {
            if (this->pdata[i1] < s2.pdata[i2]) {
                i1++;
            }
            else {
                i2++;
            }
        }
        else {
            set.add_element(this->pdata[i1]);
            i1++, i2++;
        }
    }
    return set;
}
