#include <iostream>
#include "MyVector.h"


using namespace std;

class Term
{
private:
    int x;
    int y;
    friend class Polynomial;

public:
    static void parseTerms(char* str, MyVector<Term>& terms) 
    {
        char* ptr = str; // ��������� �� ������� ������� � ������
        int sign = 1; // ���� ���������� �����
        int coefficient, exponent;

        while (*ptr != '\0') {
            coefficient = 0;
            exponent = 0;
            bool isCoef = false;

            while (*ptr == ' ') ++ptr;

            if (*ptr == '-') {
                sign = -1;
                ++ptr;
            }
            else if (*ptr == '+') {
                sign = 1;
                ++ptr;
            }
            else {
                sign = 1;
            }

            while (*ptr == ' ') ++ptr;

            while (isdigit(*ptr)) {
                coefficient = coefficient * 10 + (*ptr - '0');
                ++ptr;
                isCoef = true;
            }

            if (!isCoef && (*ptr != 'x' && *ptr != 'X')) {
                coefficient = 1;
            }
            coefficient *= sign;

            while (*ptr == ' ') ++ptr;

            if (*ptr == 'x' || *ptr == 'X') {
                if (!isCoef) coefficient = sign; // ���� ����������� �� ������ ����, �� �� ����� ����� (+1 ��� -1)
                ++ptr;
                exponent = 1;

                while (*ptr == ' ') ++ptr;

                if (*ptr == '^') {
                    ++ptr;
                    exponent = 0;
                    while (*ptr == ' ') ++ptr;
                    while (isdigit(*ptr)) {
                        exponent = exponent * 10 + (*ptr - '0');
                        ++ptr;
                    }
                }
            }
            else {
                exponent = 0;
            }

            terms.add_element(Term(coefficient, exponent));

            while (*ptr == ' ') ++ptr;
        }
    }


    Term()
    {
        x = 0;
        y = 0;
    }

    Term(int x, int y = 1)
    {
        this->x = x;
        this->y = y;
    }

    Term(const Term& t)
    {
        this->x = t.x;
        this->y = t.y;
    }

    Term operator= (Term t)
    {
        this->x = t.x;
        this->y = t.y;
        return *this;
    }

    friend Term operator+ (Term t1, Term t2)
    {
        if (t1.GetY() != t2.GetY())
        {
            cout << "������" << endl;
            exit(1);
        }

        return Term(t1.x + t2.x, t1.y);
    }

    friend Term operator- (Term t1, Term t2)
    {
        if (t1.GetY() != t2.GetY())
        {
            cout << "������" << endl;
            exit(0);
        }

        return Term(t1.x - t2.x, t1.y);
    }

    friend Term operator* (Term t1, Term t2)
    {
        return Term(t1.x * t2.x, t1.y + t2.y);
    }

    friend Term operator* (double x, Term t)
    {
        return Term(x * t.x, t.y);
    }

    friend Term operator* (Term t, double x)
    {
        return Term(x * t.x, t.y);
    }

    friend ostream& operator<< (ostream& out, const Term& t)
    {
        if (t.x == 0)
            out << 0;
        else if (t.y == 0)
            out << t.x;
        else if (t.y == 1)
            out << t.x << "x";
        else
            out << t.x << "x^" << t.y;

        return out;
    }

    friend istream& operator>>(istream& in, Term& t) {
        char input[100]; // ������ ��� �������� ������� ������
        in >> input; // ��������� ������ �� ������

        // ��������� �� ������� ������� � ������
        const char* ptr = input;
        int sign = 1; // ���� ���������� �����
        int coefficient = 0, exponent = 0;

        // ������� �������� �� ������ �����
        while (*ptr == ' ') ++ptr;

        // �������� ����� �����
        if (*ptr == '-') {
            sign = -1;
            ++ptr;
        }
        else if (*ptr == '+') {
            sign = 1;
            ++ptr;
        }
        else {
            sign = 1;
        }

        // ������� �������� ����� �����
        while (*ptr == ' ') ++ptr;

        // ������ ������������
        bool isCoef = false;
        while (*ptr >= '0' && *ptr <= '9') {
            coefficient = coefficient * 10 + (*ptr - '0');
            ++ptr;
            isCoef = true;
        }

        // ������, ���� ����������� �� ������
        if (!isCoef && (*ptr != 'x' && *ptr != 'X'))
            coefficient = 1;
        coefficient *= sign;

        // ������� �������� ����� ������������ (���� ����)
        while (*ptr == ' ') ++ptr;

        if (*ptr == 'x' || *ptr == 'X') {
            if (!isCoef) coefficient = sign; // ���� ����������� �� ������ ����, �� �� ����� ����� (+1 ��� -1)
            ++ptr;
            exponent = 1;

            // ������� �������� ����� 'x'
            while (*ptr == ' ') ++ptr;

            // ������ ����������, ���� ��� �������
            if (*ptr == '^') {
                ++ptr;
                exponent = 0; // ����� ���������� ����� �������
                while (*ptr == ' ') ++ptr; // ������� �������� ����� '^'
                while (*ptr >= '0' && *ptr <= '9') {
                    exponent = exponent * 10 + (*ptr - '0');
                    ++ptr;
                }
            }
        }
        else {
            if (isCoef || coefficient == 0) exponent = 0;
        }

        t.x = coefficient;
        t.y = exponent;

        return in;
    }



    // ������ � ���������� ������� ������
    int GetX() const { return this->x; }
    int GetY() const { return this->y; }
    void SetX(int value) { this->x = value; }
    void SetY(int value) { this->y = value; }
    bool IsZero() const { return this->x == 0; }
};




