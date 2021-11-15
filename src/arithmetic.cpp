#include "arithmetic.h"
#include "stack.h"
using namespace std;

void Arithmetic::divided_lex()
{
    //s = Lex_in[0];
    int j = 0;
    //int type;
    for (int i = 0; i < size; i++)
    { //операции
        if ((s[i] == '+') || (s[i] == '-') || (s[i] == '*') || (s[i] == '/'))
        { Lex_in[j] = s[i];  type = 3; j++; }
        else // скобки
        {
            if ((s[i] == '(') || (s[i] == ')'))
            { Lex_in[j] = s[i];  type = 1; j++; }
            else //переменные
            {
                if (((s[i] >= 'a') && (s[i] <= 'z')) || ((s[i] >= 'A') && (s[i] <= 'Z')))
                { Lex_in[j] = s[i]; type = 4; j++; }
                else //числа
                {
                    if ((s[i] >= '0') && (s[i] <= '9'))
                    { Lex_in[j] = s[i]; type = 2; j++; }
                }
            }
        }
    }
}

bool Arithmetic::check_brackets()
{
    Stack<char> T(100);
    for (int i = 0; i < size; i++)
    {
        if (s[i] == '(') 
            T.Push(s[i]); 
        if (s[i] == ')') 
        {
            if (T.IsEmpty() == true)
                throw "error"; 
            else 
                T.Pop();
        }
    }
    if (T.IsEmpty() != true) {return true;}   
    else 
        return false;
}

//int Arithmetic::check_formula()
//{
//
//    for (int i = 0; i < s.size(); i++)
//    {
//        if ((is_operations(s[i]) == 3) && (is_operations(s[i]) == 3))
//        {
//            return false;
//        }
//        return true;
//    }
//}

int Arithmetic::prioritet(string s)
{
    if (s == "(") { return 0; }
    if ((s == "+") || (s == "-")) return 1;
    if ((s == "*") || (s == "/")) return 2;
}

void Arithmetic::polsk_zap()
{
    int j;
    string* result = 0;
    Stack<char> res;
    //int j;
    for (int i = 0; i < size; i++)
    {
        if ((type == 2) || (type == 4))
        {
            result[j] = Lex_in[i]; j++;
        }
        if (type == 1)
        {
            if (res.IsEmpty()) { res.Push(s[i]); }
            else
            {
                if (prioritet(Lex_in[i]) > prioritet(Lex_in[res.Peek()]))
                {
                    result[j] = Lex_in[i]; j++;
                }
                else
                {
                    while (prioritet(Lex_in[i]) <= prioritet(Lex_in[res.Peek()]))
                    {
                        res.Pop();
                        result[j] = Lex_in[res.Pop()]; j++;
                        res.Push(i);
                    }
                }
            }
        }
        if (Lex_in[i] == "(")
            res.Push(i);
        if (Lex_in[i] == ")")
        {
            while (Lex_in[i] >= "(")
            {
                res.Pop();
                result[j] = Lex_in[res.Pop()]; j++;
            }
        } 
    } 
    while (!res.IsEmpty())
    {
        res.Pop();
        result[j] = Lex_in[res.Pop()]; j++;
    }
    for (int i = 0; i < size; i++)
        polish += result[j];
}

bool Arithmetic::calculating()
{
    Stack<char> result;
    int* value = 0;
    int a, b;
    for (int i = 0; i < size; i++)
    {
        if (type == 2)
        {
            result.Push(polish[i]);
        }
        if (type == 4)
        {
            cout << "¬ведите " << polish[i] << ": ";
            cin >> value[polish[i]];
            result.Push(value[polish[i]]);
        }
        if (type == 2) 
        {
            a = result.Pop();
            b = result.Pop();
            if (Lex_in[i] == "+") { result.Push(a + b); }
            if (Lex_in[i] == "-") { result.Push(a - b); }
            if (Lex_in[i] == "*") { result.Push(a * b); }
            if (Lex_in[i] == "/") { result.Push(a / b); }
        }
    }
    int resultat = result.Pop();
    return resultat;
}

