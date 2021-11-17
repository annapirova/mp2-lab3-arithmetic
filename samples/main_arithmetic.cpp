#include "../arithmetic1/arithmetic.h"
#include <string>

#include <iostream>

int main()
{
    string str = " ";
    cout << "Enter :" << endl;
    getline(cin, str);
    pair<char, int> m;
    Arithmetic A;
   // string str1;
    A.divided_lex();
    A.polsk_zap();
    //cout << "Польская запись: " << A.divided_lex() << endl;
    double res;
    res = A.calculating();
    cout << "Result: " << res << endl;
}
