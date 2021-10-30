// реализация функций и классов для вычисления арифметических выражений
#include "..\include\arithmetic.h"
#include "..\include\stack.h"

// Определение приоритета опирации
int PR(string a)
{  if(a=="+"){ return(1);}
   if(a=="-") {return(1);}
   if(a=="*") {return(2);}
   if(a=="/") {return(2);}
   if(a=="^") {return(3);}
   if(a=="sin") {return(4); }
}

//Конструкторы и деструкторы    
Tlexeme::Tlexeme(string a)
{ Size = a.length();
  mLexeme = new string[Size];
  priority = new int[Size];
  TStack <char> S1;
  for (int i = 0; i < Size; i++)
  { mLexeme[i] = ' ';	
    priority[i] = -1;
  }
  mLexeme[0] = a;
}
Tlexeme::~Tlexeme()
{ delete[] mLexeme;
  delete[] priority;
}
//Операции
bool Tlexeme::Split()
{ string a= " ";
  if ((mLexeme[0]!=a)&&(priority[0] == -1)) 
  { return 0; } else {return 1;}
}
void Tlexeme::Divide()
{ if(!Split())
  { string a = mLexeme[0];
    int j=0;
    string S1="";
    string* mLexeme1= new string[Size];
    int* priority1 = new int[Size];
    for (int i = 0; i < Size; i++)
    { //знаки операций (кроме минуса)
      if((a[i]=='+')|| (a[i] == '*')|| (a[i] == '/')|| (a[i] == '^'))
      { if(S1 != ""){ mLexeme1[j] = S1; priority1[j] = 2; j++; S1 = "";}
        mLexeme1[j] = a[i]; 
	    priority1[j] = 1; j++;}
      else //минус
      { if(a[i] == '-')
        { if((i==0)||(((priority1[j-1]==4)||(priority1[j-1]==1)))&&(S1 == "")){ S1=S1+'-';}
          else { if (S1 != "") { mLexeme1[j] = S1; priority1[j] = 2; j++; S1 = ""; }
                 mLexeme1[j] = a[i];
                 priority1[j] = 1; j++;}}
        else //скобки
        { if((a[i]=='(')||(a[i] == ')'))
          { if(S1 != ""){ mLexeme1[j] = S1; priority1[j] = 2; j++; S1 = "";}
            mLexeme1[j] = a[i]; 
	        priority1[j] = 4; j++;}
          else // функция sin
          { if((a[i]=='s')&&(a[i+1]=='i')&&(a[i+2]=='n'))
          { if(S1 != ""){ mLexeme1[j] = S1; priority1[j] = 2; j++; S1 = "";}
            mLexeme1[j] = "sin"; i = i + 2;
	        priority1[j] = 5; j++;}
            else //операнды-переменные
            { if(((a[i]>='A')&&(a[i]<='Z'))||((a[i] >= 'a') && (a[i] <= 'z')))
              { if (S1 != "") { mLexeme1[j] = S1; priority1[j] = 2; j++; S1 = ""; }
                mLexeme1[j] = a[i];
                priority1[j] = 3; j++;}
              else //операнды числа
              { if(((a[i] >= '0') && (a[i] <= '9'))||(a[i]=='.'))
                {S1=S1+a[i];}
              else { Flag = i; } //ошибка не распознаный символ
              }
            }
          }
        }
      }
    }
    if (S1 != "") { mLexeme1[j] = S1; priority1[j] = 2; S1 = ""; j++; }
    Size=j;
    mLexeme = new string[Size];
    priority = new int[Size];
    for (int i = 0; i < Size; i++)
    { mLexeme[i] = mLexeme1[i]; cout<< mLexeme1[i]<<" ";
      priority[i] = priority1[i];
    }
    cout << endl;
    for (int i = 0; i < Size; i++)
    { cout<<priority[i]<<" ";
    }
    cout << endl;
  }
}
void Tlexeme::Check_correct()
{ if (!Split())
  {if (Flag != 0) { cout << "Input error: incorrect character is entered in place " << Flag << endl; }
   int a = -1;
   a = Check_brack(); 
   if (a != -1) { cout << "Input error: brackets are entered incorrectly" << endl; Flag = 1; }
   a = Check_sign();
   if (a != -1) { cout << "Input error: signs of operations are entered incorrectly in place " << a << endl;Flag = 1;}
   a = Check_point();
   if (a != -1) { cout << "Input error: points of real numbers are entered incorrectly in place " << a << endl;Flag = 1; }
   a = Check_variable();
   if (a != -1) { cout << "Input error: variables are entered incorrectly in place " << a << endl;Flag = 1; }
   a = Check_function();
   if (a != -1) { cout << "Input error: function are entered incorrectly in place " << a << endl; Flag = 1;}
  }
}
int Tlexeme::Check_brack()
{ //что-то стоит между двух скобок одинакового типа
  int a = -1, i = 0;
  while ((i < Size) && (a == -1))
  { if ((mLexeme[i]=="(")&&(mLexeme[i+1]!="(")&&(mLexeme[i+ 2]=="(")) { a = i; } 
    if ((mLexeme[i] == ")") && (mLexeme[i + 1] != ")") && (mLexeme[i + 2] == ")")) { a = i; }
    i++;}
  if (a == -1) //проверка на правильность растановки скобок
  { TStack <int> S1; i=0;
    while ((i < Size) && (a == -1))
    { if(priority[i]==4)
      { if(mLexeme[i]=="("){ S1.Push(1); }
        else 
        { if(S1.Empty()){a=i;}
          else {S1.Pop();}
        } 
      } i++;
    }
    if(!(S1.Empty())){a=11;} 
  }
  
  return a;
}
int Tlexeme::Check_sign() 
{ int a=-1, i = 1;
  if (priority[0] == 1){a =0; } //первый символ в выражении знак операции
  while ((i<Size)&&(a==-1))
  { if(priority[i]== 1)
    { if((priority[i+1] == 1)||(mLexeme[i-1]=="(")||(mLexeme[i + 1] == ")")) { a = i; }
      // два знака подряд, знак после открывающейся скобки, знак перед закрывающейся скобкой
    } i++;
  }
  if (mLexeme[0] == "-") { a = 0;}
  return a;
}
int Tlexeme::Check_point()
{ int a=-1, i = 0;
  while ((i<Size)&&(a==-1))
  { if(priority[i]== 2) // две и более точек в одном числе
    { string f = mLexeme[i];
      int  k = count(f.begin(), f.end(), '.');
      if (k > 1) {  a = i; }
    } i++;}
  return a;
}
int Tlexeme::Check_variable()
{ int a=-1, i = 0;
  while ((i<Size)&&(a==-1))
  { if((priority[i]== 3)&&(priority[i+1] == 3)){ a = i; } // две переменные стоят подряд
    i++;}
  return a;
}
int Tlexeme::Check_function()
{ int a=-1, i = 0;
  while ((i<Size)&&(a==-1))
  { if((priority[i]== 5)&&(priority[i+1] == 1)){ a = i; } 
    if((priority[i]== 5)&&(priority[i-1] == 3)){ a = i; } 
    if ((priority[i] == 5) && (priority[i - 1] == 2)) { a = i; }
    i++;}
  return a;
}
void Tlexeme::Pol()
{ TStack <int> S1; //
  TStack <int> S2; //знаки операций
  string* mLexeme1;
  int* priority1;
  mLexeme1 = mLexeme;
  priority1 = priority;
  mLexeme = new string[Size];
  priority = new int[Size];
  int j=0;
  for (int i = 0; i < Size; i++)
  { switch (priority1[i])
    { case 2: mLexeme[j]= mLexeme1[i]; priority[j] = priority1[i]; cout << mLexeme[j] << " "; j++;  break;
      case 4: if (mLexeme1[i]=="(") { S1.Push(i); }
              else { while((mLexeme1[S1.Top()]!="(") || (!S1.Empty()))
                     { int q=S1.Pop(); mLexeme[j] = mLexeme1[q]; priority[j] = priority1[q]; cout << mLexeme[j] << " "; j++;  }}
      case 3: mLexeme[j] = mLexeme1[i]; priority[j] = priority1[i]; cout << mLexeme[j] << " "; j++; break;
      default: if (S1.Empty()) { S1.Push(i); } //(1 или 5)
              else { int pr1 = PR(mLexeme1[i]), pr2= PR(mLexeme1[S1.Top()]);
                     if(pr1>pr2){ mLexeme[j]= mLexeme1[i]; priority[j] = priority1[i]; cout << mLexeme[j] << " "; j++;}
                     else 
                     { while (pr1<=pr2)
                       { int q=S1.Pop(); mLexeme[j] = mLexeme1[q]; priority[j] = priority1[q]; cout << mLexeme[j] << " "; j++;
                         pr2= PR(mLexeme1[S1.Top()]);
                     } S1.Push(i);
                     }
                   }     
    }
  }
  while (!S1.Empty())
  { int q = S1.Pop(); mLexeme[j] = mLexeme1[q]; priority[j] = priority1[q]; j++;}

  for (int i = 0; i < Size; i++)
  {
      cout << mLexeme[i] << " ";
  }

}


/*
      
      
    mLexeme[i] = ' ';	
    priority[i] = -1;




  }*/