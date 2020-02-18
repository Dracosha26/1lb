#include "application.h"
#include <iostream>
#include "polinom.h"

using namespace std;

Application::Application(int argc, char *argv[])
{
}


void Application::menu(int &ch)
{
    cout << endl << "1. Enter the coefficients of the polynomial" << endl;
    cout << "2. Complete the program" << endl;
    cout << endl << "Input: ";
    cin >> ch;
}

void Application::exec()
{
    int ch;

    while(true)
    {
        menu(ch);
        if (!ch) {
                    cin.clear();
                    while (cin.get() != '\n');
                    cout << "Incorrect input. Repeat the entry!" << endl;
                }
        else {
            if(ch == 2)
                break;
            switch (ch)
            {
            case 1:
            {
                int a = 0;
                int b = 0;
                int c = 0;
                cout << "Enter the coefficients of the polynomial (ax^2 + bx + c)" << endl;
                while (true) {
                        cout << "Enter the coefficient a: ";
                        cin >> a;
                        if (cin.good() == false) {
                            cin.clear();
                            while (cin.get() != '\n');
                            cout << "Incorrect input. Repeat the entry!" << endl;
                        }
                        else break;
                }
                while (true) {
                        cout << "Enter the coefficient b: ";
                        cin >> b;
                        if (cin.good() == false) {
                            cin.clear();
                            while (cin.get() != '\n');
                            cout << "Incorrect input. Repeat the entry!" << endl;
                        }
                        else break;
                }
                while (true) {
                        cout << "Enter the coefficient c: ";
                        cin >> c;
                        if (cin.good() == false) {
                            cin.clear();
                            while (cin.get() != '\n');
                            cout << "Incorrect input. Repeat the entry!" << endl;
                        }
                        else break;
                }
                Polinom *polinom = new Polinom(a, b, c);
                polinom->calculateX();
                cout << "Result of calculating the roots of the polynomial: " << endl << *polinom << endl;
                if (polinom->getX()->size() == 1)
                    cout << "The equation has one root: x = " << polinom->getX()->first();
                else if(polinom->getX()->size() == 2)
                    cout << "The equation has two roots:" << endl << "x1 = " << *polinom->getX()->begin() << " x2 = " << *(polinom->getX()->begin() + 1) << endl;
                else
                    cout << "The equation has no roots";
            }
                break;
            default:
                break;
            }

        }

    }
}
