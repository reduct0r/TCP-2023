#include "fraction.h"
#include <numeric> 

// -0 3/2 == -3/2
// 5
fraction::fraction(int first, int second) : numerator(first), denominator(second) 
{
    int commonDivisor = std::gcd(first, second);
    first /= commonDivisor;
    second /= commonDivisor;

    this->numerator = first;
    this->denominator = second;
}


fraction::fraction(const char* string) {
    fractionParse(*this, string);
}

fraction::fraction(double value) 
{
    static const int N_DEC = 4;

    int integerPart = static_cast<int>(value);
    double decimalPart = value - integerPart;

    // Преобразование дробной части в дробь
    double numeratorDouble = decimalPart * pow(10, N_DEC);
    int commonFactor = std::gcd(static_cast<int>(numeratorDouble), static_cast<int>(pow(10, N_DEC)));
    numerator = static_cast<int>(numeratorDouble / commonFactor);
    denominator = static_cast<int>(pow(10, N_DEC) / commonFactor);

    // Добавление целой части к дроби
    numerator += integerPart * denominator;

    // Сокращение дроби
    int divisor = std::gcd(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;
}

int fraction::getNumerator() const {
    return numerator;
}

int fraction::getDenominator() const {
    return denominator;
}

void fraction::setNumerator(int first) {
    this->numerator = first;
}

void fraction::setDenominator(int second) {
    this->denominator = second;
}


std::ostream& operator<<(std::ostream& out, fraction& o) 
{
    int tempNumerator = o.numerator;
    int tempDenominator = o.denominator;

    if (abs(tempNumerator) > tempDenominator && tempDenominator != 0) 
    {
        int commonDivisor = std::gcd(tempNumerator, tempDenominator);
        tempNumerator /= commonDivisor;
        tempDenominator /= commonDivisor;

        int wholePart = tempNumerator / tempDenominator;
        tempNumerator = tempNumerator - wholePart * tempDenominator;
        if (tempNumerator < 0) 
        {
            tempNumerator *= -1;
            out << wholePart << " " << tempNumerator << '/' << tempDenominator;
            return out;
        }

        else if (tempNumerator == 0) 
        {
            out << wholePart;
            return out;
        }

        else 
        {
            out << wholePart << " " << tempNumerator << '/' << tempDenominator;
            return out;
        }
    }
    else if (abs(tempNumerator) == tempDenominator) 
    {
        if (tempNumerator < 0) {
            out << "-1";
            return out;
        }
        else {
            out << "1";
            return out;
        }
    }
    else if (tempDenominator != 0 && tempNumerator != 0) {
        out << tempNumerator << '/' << tempDenominator;
        return out;
    }
    else if (tempDenominator != 0 && tempNumerator == 0) {
        out << tempNumerator;
        return out;
    }
    else {
        out << "Неправильный ввод!";
        return out;
    }
}

bool find(const char* string) 
{
    int i = 0;
    while (string[i] != '\0') 
    {
        if (string[i] == ' ') 
        {
            return true;
        }
        i++;
    }
    return false;
}

std::istream& operator>>(std::istream& in, fraction& o) {
    char* string = new char[45] {};
    in.getline(string, 45);
    fractionParse(o, string);

    delete[] string;
    return in;
}

void fractionParse(fraction& o, const char* string) 
{
    char* wholePart = new char[45] {};
    char* numeratorChar = new char[45] {};
    char* denominatorChar = new char[45] {};
    bool ceil = 1;
    bool under = 0;

    if (string[0] == '-')
    {
        under = 1;
    }

    if (find(string)) 
    {
        int i = 0;
        int index = 0;

        while (string[i] != ' ') 
        {


            wholePart[index] = string[i];
            index++;
            i++;
        }

        i++;
        index = 0;
        while (string[i] != '/') 
        {
            numeratorChar[index] = string[i];
            index++;
            i++;
        }

        i++;
        index = 0;
        while (string[i] != '\0') {
            denominatorChar[index] = string[i];
            index++;
            i++;
        }

        if (atoi(wholePart) < 0) 
        {
            o.numerator = -1 * atoi(numeratorChar) + atoi(denominatorChar) * atoi(wholePart);
            o.denominator = atoi(denominatorChar);
        }

        else if (under == 1)
        {
            o.numerator = -1 * atoi(numeratorChar) + atoi(denominatorChar) * atoi(wholePart);
            o.denominator = atoi(denominatorChar);
        }

        else 
        {
            o.numerator = atoi(numeratorChar) + atoi(denominatorChar) * atoi(wholePart);
            o.denominator = atoi(denominatorChar);
        }

    }

    else 
    {
        int index = 0;
        int i = 0;

        while (string[i] != '/' && string[i] != '\0')
        {
            numeratorChar[index] = string[i];
            index++;
            i++;
        }

        if (string[i + 1] == '/')
        {
            ceil = 0;
        }
        index = 0;
        i++;

        while (string[i] != '\0') 
        {
            denominatorChar[index] = string[i];
            index++;
            i++;
        }
        o.numerator = atoi(numeratorChar);
        o.denominator = atoi(denominatorChar);
    }
    if (o.denominator == 0 && ceil)
    {
        o.denominator = 1;
    }
    else if (o.denominator == 0)
    {
        std::cout << "Incorrect input\n";
        exit(1);
    }

    delete[] numeratorChar;
    delete[] denominatorChar;
    delete[] wholePart;
}

fraction::fraction(fraction& o) 
{
    this->numerator = o.numerator;
    this->denominator = o.denominator;
}

fraction fraction::operator+(fraction& o) const
{
    fraction resultFraction;

    if (this->denominator == o.getDenominator()) 
    {
        resultFraction.setNumerator(this->numerator + o.getNumerator());
        resultFraction.setDenominator(this->denominator);
    }
    else 
    {
        resultFraction.setNumerator((this->numerator * o.getDenominator()) + (o.getNumerator() * this->denominator));
        resultFraction.setDenominator(this->denominator * o.getDenominator());
    }

    return resultFraction;
}

fraction operator+(fraction& frac, double dbl)
{
    fraction dblFraction(dbl);
    fraction result = frac + dblFraction;
    return result;

}

fraction operator+(double dbl, fraction& frac)
{
    fraction dblFraction(dbl);
    fraction result = dblFraction + frac;
    return result;
}

fraction operator+(int i, fraction& frac)
{
    fraction iFraction(i, 1);
    fraction result = iFraction + frac;
    return result;
}

fraction operator+(fraction& frac, int i)
{
    fraction iFraction(i, 1);
    fraction result = iFraction + frac;
    return result;
}

fraction fraction::operator+=(fraction& frac)
{
    *this = *this + frac;
    return *this;
}

fraction fraction::operator+=(double dbl)
{
    fraction dblFraction(dbl);
    *this = *this + dblFraction;
    return *this;
}

fraction fraction::operator+=(int i)
{
    fraction iFraction(i, 1);
    *this = *this + iFraction;
    return *this;
}


fraction fraction::operator=(fraction const& o) 
{
    this->numerator = o.numerator;
    this->denominator = o.denominator;
    return *this;
}
