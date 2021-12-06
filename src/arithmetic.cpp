#include "stack.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include "arithmetic.h"

using namespace std;

bool Arithmetic::CheckBrackets(char* s)
{
    Stack<char> T(100);
    int lex = strlen(s);
    for (int i = 0; i < lex; i++)
    {
        if (s[i] == '(')
            T.Push(i);
        if (s[i] == ')')
        {
            if (T.IsEmpty() == true)
                cout << "error. brackets are wrong.";
            else
                T.Pop();
        }
    }
    if (T.IsEmpty() != true) 
      cout << "error. brackets are wrong";
    else
        return false;
}

bool Arithmetic::CheckOperations_StandTogether(char* s)
{
    char operations[] = "+-/*";
    int lex = strlen(s);

    for (int i = 0; i < lex; i++ )
    {
        for (int j = 0; j < 3; j++)
        {
            if ((s[i] == operations[j]) && (s[i + 1] == operations[j]))
            {
                cout << "error.two operations stand together" << endl;
                break;
                return false;
            }
        }
    }   
}

bool Arithmetic::CheckOperations_StartsWithOP(char* s)
{
    char operations[] = "+-/*";
    int lex = strlen(s);

    for (int i = 0; i < lex; i++)
    {
        if (s[0] == operations[i])
        {
            cout << "error. starts with operation" << endl;
            break;
            return false;
        }
    }
}

bool Arithmetic::CheckOperations_UnknownSymbols(char* s)
{
    char operations[] = "+-/*";
    char operand[] = "abcdefghijklmnopqrstuvwxyz";
    char digit[] = "0123456789";
    int lex = strlen(s);

    for (int i = 0; i < lex; i++)
    {
        for (int j = 0; j < lex; j++)
        {
            if ((s[i] != operations[j]) || (s[i] != operand[j]) || (s[i] != digit[j]))
            {
                cout << "error. unknown symbol" << endl;
                break;
                return false;
            }
        }
    }
}

void Arithmetic::Lexems()
{
   // char lex[100];
    int j = 0;
   // int lex = strlen(s);

    //while (i < lex)
    {
        for (int i = 0; i < s.size(); i++)
        {
            //for (int j = 0; j < lex; j++)
            {
                if ((s[i] == '+') || (s[i] == '-') || (s[i] == '*') || (s[i] == '/'))
                {
                    lex[j] = s[i];
                    j++;
                }
                else
                {
                    if ((s[i] == '(') || (s[i] == ')'))
                    {
                        lex[j] = s[i];
                        j++;
                    }
                    else
                    {
                        if (((s[i] >= 'a') && (s[i] <= 'z')) || ((s[i] >= 'A') && (s[i] <= 'Z')))
                        {
                            lex[j] = s[i];
                            j++;
                        }
                        else
                        {
                            if ((s[i] >= '0') && (s[i] <= '9'))
                            {
                                lex[j] = std::stoll(s);
                                j++;
                            }
                        }
                    }
                }
            }
        }
    }


}

int Arithmetic::Prioritet(char s)
{
    if (s == '(') { return 0; }
    if ((s == '+') || (s == '-')) { return 1; }
    if ((s == '*') || (s == '/')) { return 2; }
}

void Arithmetic::PolishZap()
{
    int j;
    Stack<char> st(100);

    //int lex = strlen(s);
    
    for (int i = 0; i < s.size(); i++)
    {
        if ((((lex[i] >= 'a') && (lex[i] <= 'z')) || ((lex[i] >= 'A') && (lex[i] <= 'Z'))) || ((lex[i] >= '0') && (lex[i] <= '9')))
        {
            r[j] = lex[i];
            j++;
        }

        if ((lex[i] == '(') || (lex[i] == ')'))
        {
            if (st.IsEmpty())
                st.Push(lex[i]);
            else
            {
                if (Prioritet(lex[i]) > Prioritet(lex[st.Peek()]))
                {
                    r[j] = lex[i]; 
                    j++;
                }
                else
                {
                    while (Prioritet(lex[i]) <= Prioritet(lex[st.Peek()]))
                    {
                        r[j] = lex[st.Pop()]; 
                        j++;
                        st.Push(lex[i]);
                    }
                }
            }
        }

        if (lex[i] == '(')
            st.Push(lex[i]);
        if (lex[i] == ')')
        {
            while (lex[i] != '(')
            {
                r[j] = st.Pop(); 
                j++;
            }
        }


    } 
    while (st.IsEmpty() != true)
    {
        r[j] = st.Pop();
        j++;
    }

    for (j = 0; j < r.size(); j++)
        cout << r[j];

}

double Arithmetic::Calculating()
{
    Stack<char> st(100);
    double a, b, res;
    //int lex = strlen(r);

    for (int i = 0; i < r.size(); i++)
    {
        if ((r[i] >= '0') && (r[i] <= '9'))
            st.Push(r[i]);
        if (((r[i] >= 'a') && (r[i] <= 'z')) || ((r[i] >= 'A') && (r[i] <= 'Z')))
        {
            cout << "enter the value" << r[i];
            cin >> r[i];
            st.Push(r[i]);
        }
        if ((r[i] == '+') || (r[i] == '-') || (r[i] == '*') || (r[i] == '/'))
        {
            a = st.Pop();
            b = st.Pop();
            if (r[i] == '+') { st.Push(a + b); }
            if (r[i] == '-') { st.Push(a - b); }
            if (r[i] == '*') { st.Push(a * b); }
            if (r[i] == '/') { st.Push(a / b); }
        }
    }
    res = st.Pop();
    return res;
}


