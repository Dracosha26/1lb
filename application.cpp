#include "application.h"
#include <iostream>
#include "polinom.h"

using namespace std;

Application::Application(int argc, char *argv[])
{
}

using namespace std;

void menu(int &ch)
{
    cout << endl << "1. Ввести коэффициенты полинома" << endl;
    cout << "2. Вывести полином" << endl;
    cout << "3. Завершить программу" << endl;
    cout << endl << "Ввод: ";
    cin >> ch;
}

void Application::exec()
{
    int ch;

    while(true)
    {
        menu(ch);
        if(ch == 0)
            break;
        switch (ch)
        {
        case 1:
        {
            int a = 0;
            int b = 0;
            int c = 0;
            cout << "Введите коэффицинеты полинома" << endl;
            bool rightIn = false;
            cin.exceptions(istream::failbit | istream::badbit);
            while(!rightIn)
            {
                try
                {
                    cin >> a;
                    cin >> b;
                    cin >> c;
                    rightIn = true;
                }
                catch(istream::failure e)
                {
                    cout << "Некорректный ввод, поробуйте еще раз" << endl;
                    cin.clear();
                }
            }

            Polinom *polinom = new Polinom(a, b, c);
            polinom->calculateX();
            cout << "Результат вычисления коренй полинома: " << endl << *polinom << endl;
            if (polinom->getX()->size() == 1)
                cout << "Уравнение имеет один корень: x = " << polinom->getX()->first();
            else if(polinom->getX()->size() == 2)
                cout << "Уравнение имеет два корня:" << endl << "x1 = " << *polinom->getX()->begin() << " x2 = " << *(polinom->getX()->begin() + 1) << endl;
            else
                cout << "Уравнение не имеет коренй";
        }
            break;
        default:
            break;
        }
    }
}
