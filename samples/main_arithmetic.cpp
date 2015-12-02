#include "arithmetic.h"
#include <iostream>
#define MAX_SIZE 256;

 int main(){
	 Check str("");
 	bool flag1 = true, flag3 = true; 
	int p = 0; 

	Check newstr("");
 	setlocale(LC_ALL, "Russian");
 
 	cout << "Enter an expression" <<endl;
	cout << "The operations: +, -, /, *, ^. " <<endl;
 	while (flag1 == true){
 		cout << "Enter: ";
 		gets(str.s);
 		if(str.IsUnarMinus()){
			str.UnarMinus(newstr.s);
 		}
 		else
 		{
			int i = 0;
 			while(str.s[i] != '\0'){
 				newstr.s[i] = str.s[i];
 				i++;
 			}
 			newstr.s[i]='\0';
 		}
		if (!newstr.CheckBrackets() && !newstr.CheckOperands())
 			cout << "Expression is uncorrect" <<endl;
 		else{
 			double result;
			bool flag2 = true;
			Check newstr1(""), newstr2("");
 			newstr.ChangeExpression(newstr1.s);
 			while (flag2 == true){
 				newstr1.Input(newstr2.s);
				result = newstr2.Calculation;
 				cout << "Result = " << result <<endl;
				if(str.AreVars)
				{
 				cout << "Expression contians vars. Do you want to continue entering? " <<endl;
 				cout << "1.Yes" <<endl;
 				cout << "2.No" <<endl;
 				cin  >> p;
 				if (p == 2)
 					flag2 = false;
				}
				else
					flag2 = false;
 			}
 			flag1 = false;
			//~newstr1; ~newstr2;
 		}
 	}
//	~newstr;
 return 0;
}