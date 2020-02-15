#include "polinom.h"
#include <math.h>

Polinom::Polinom(number a, number b, number c)
    :a(a), b(b), c(c)
{
    x = new QVector< number >;
}

double Polinom::getA()
{
    return a;
}

double Polinom::getB()
{
    return b;
}

double Polinom::getC()
{
    return c;
}

QVector< double >* Polinom::getX()
{
    return x;
}

void Polinom::calculateX()
{

    double D = b*b - 4*a*c;

    if(D == 0)
    {
        x->push_back(-b/(2*a));
    }
    else
    {
        x->push_back((-b + sqrt(D))/(2*a));
        x->push_back((-b - sqrt(D))/(2*a));
    }
}

std::ostream& operator<<(std::ostream &out, const Polinom &polinom) {
    out << polinom.a << "x^2 + " << polinom.b << "x + " << polinom.c;
    return out;
}
