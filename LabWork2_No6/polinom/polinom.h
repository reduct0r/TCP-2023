#pragma once
#include "term.h"

class Polynomial
{
private:
    MyVector<Term> poly;
    int degree;
    bool order_; // true - по возрастанию, false - по убыванию

public:
    // Constructors
    Polynomial(bool ascending_order = true)
        : order_(ascending_order)
    {
        poly.add_element(Term(0, 0));
        degree = 0;
    }

    Polynomial(MyVector<Term>& terms, bool ascending_order = true)
        : poly(terms), order_(ascending_order), degree(getDegree())
    {
        Sort();
    }

    Polynomial(int n, bool ascending_order = true)
        : order_(ascending_order)
    {
        poly.add_element(Term(n, 0));
        degree = 0;
    }

    Polynomial(Term term, bool ascending_order = true)
        : order_(ascending_order)
    {
        poly.add_element(term);
        degree = std::max(degree, term.GetY());
    }

    Polynomial(Polynomial& p)
        : poly(p.poly), degree(p.degree), order_(p.order_)
    {}

    // Methods
    void SetTerm(const Term& t, bool subtraction = false)
    {
        bool found = false;
        for (auto& term : poly)
        {
            if (term.GetY() == t.GetY())
            {
                term.SetX(subtraction ? term.GetX() - t.GetX() : term.GetX() + t.GetX());
                found = true;
                break;
            }
        }
        if (!found && !subtraction) poly.add_element(t);
        Sort();
    }

    bool HaveTerm(Term t)
    {
        for (auto& term : poly)
        {
            if (term.GetY() == t.GetY())
            {
                return true;
            }
        }
        return false;
    }

    int getDegree()
    {
        int deg = 0;
        for (auto& term : poly)
        {
            deg = std::max(deg, term.GetY());
        }
        return deg;
    }

    void Sort()
    {
        MyVector<Term> p;
        degree = getDegree();

        for (int i = (order_ ? 0 : degree);
            (order_ ? i <= degree : i >= 0);
            (order_ ? ++i : --i))
        {
            int x = 0;
            int y = i;

            for (auto& term : poly)
            {
                if (term.GetY() == i)
                {
                    x += term.GetX();
                }
            }

            if (x != 0)
            {
                p.add_element(Term(x, y));
            }
        }
        this->poly = p;
        degree = getDegree();
    }

    Polynomial& operator= (Polynomial& p)
    {
        if (this == &p)
            return *this;

        poly = p.poly;
        degree = p.degree;
        order_ = p.order_;
        return *this;
    }

    void operator+= (Polynomial p)
    {
        for (auto& term : p.poly)
        {
            this->poly.add_element(term);
        }

        Sort();
    }

    void operator-= (Polynomial p)
    {
        for (auto& term : p.poly)
        {
            term.SetX((-1) * term.GetX());
            this->poly.add_element(term);
        }

        Sort();
    }

    friend Polynomial operator+ (Polynomial p1, Polynomial p2)
    {
        Polynomial p(p1.order_);
        for (auto& term : p1.poly)
        {
            p.poly.add_element(term);
        }

        for (auto& term : p2.poly)
        {
            p.poly.add_element(term);
        }

        p.Sort();

        return p;
    }

    friend Polynomial operator- (Polynomial p1, Polynomial p2)
    {
        Polynomial p(p1.order_);
        for (auto& term : p1.poly)
        {
            p.poly.add_element(term);
        }

        for (auto& term : p2.poly)
        {
            term.SetX((-1) * term.GetX());
            p.poly.add_element(term);
        }

        p.Sort();

        return p;
    }

    friend Polynomial operator* (Polynomial p1, Polynomial p2)
    {
        Polynomial p(p1.order_);

        for (auto& term1 : p1.poly)
        {
            for (auto& term2 : p2.poly)
            {
                p.poly.add_element(term1 * term2);
            }
        }

        p.Sort();

        return p;
    }

    friend std::istream& operator>>(std::istream& in, Polynomial& p)
    {
        char str[256];
        in.getline(str, 256);

        MyVector<Term> terms;
        Term::parseTerms(str, terms);

        Polynomial np(terms, p.order_);
        p = np;

        return in;
    }

    friend void operator<<(std::ostream& out, Polynomial& p)
    {
        if (p.poly.empty())
        {
            out << 0 << std::endl;
            return;
        }
        bool isFirst = true;

        for (size_t i = p.poly.get_size(); i--;)
        {
            int X = p.poly[i].GetX();
            int Y = p.poly[i].GetY();

            if (p.poly[i].IsZero()) continue;

            if (!isFirst)
            {
                char symbol = X > 0 ? '+' : '-';
                out << " " << symbol << " ";
            }
            else if (X < 0)
            {
                out << "-";
            }
            isFirst = false;

            if (std::abs(X) != 1 || Y == 0)
            {
                out << std::abs(X);
            }
            if (Y == 1)
            {
                out << "x";
            }
            else if (Y != 0)
            {
                out << "x^" << Y;
            }
        }
        out << std::endl;
    }
};
