#ifndef POLINOM_H
#define POLINOM_H

#include "number.h"
#include <QVector>
#include <iostream>

class Polinom
{
public:
    Polinom(number a, number b, number c);

    double getA();

    double getB();

    double getC();

    QVector< double >* getX();

    void calculateX();

    friend std::ostream& operator << (std::ostream &out, const Polinom &polinom);

private:
    number a;
    number b;
    number c;
    QVector< number > *x;
};

#endif // POLINOM_H
