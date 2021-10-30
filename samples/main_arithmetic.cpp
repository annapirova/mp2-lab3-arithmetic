// Реализация пользовательского приложения
#include <iostream>
#include <fstream>
#include <string>
#include "arithmetic.h"
#include "stack.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");

    string a;
    ifstream fl1("1a.txt");
    if (fl1.is_open())
    {
        getline(fl1, a); //Ввод строки с примером
        cout << a<<endl<<endl;
        Tlexeme A(a);
        A.Divide();
        A.Check_correct();
        A.Pol();
       //Проверка на корректиность
       //Вычисление
       //Вывод
    }

}