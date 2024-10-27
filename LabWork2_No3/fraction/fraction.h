#include <iostream>
#include <cmath>
#include <algorithm> 

class fraction 
{
private:
    int numerator{};
    int denominator{};

public:
    // Fraction constructors
    fraction(int first, int second);

    fraction(const char* string);

    fraction(fraction& o);

    fraction(double value);

    fraction() : numerator(0), denominator(1) {};

    // Fraction getters
    int getNumerator() const;

    int getDenominator() const;

    // Fraction functions
    friend void fractionParse(fraction& o, const char* string);

    // Fraction setters
    void setNumerator(int first);
    void setDenominator(int second);

    // Fractions operators overload
    // friend fraction operator+(int wholePart, fraction &o);
    fraction operator+(fraction& o) const;
    friend fraction operator+(fraction& frac, double dbl);
    friend fraction operator+(double dbl, fraction& frac);
    friend fraction operator+(int i, fraction& frac);

    fraction operator+=(fraction& frac);
    fraction operator+=(double dbl);
    fraction operator+=(int i);

    fraction operator=(fraction const& o);
    friend std::ostream& operator<<(std::ostream& out, fraction& o);
    friend std::istream& operator>>(std::istream& in, fraction& o);
};
