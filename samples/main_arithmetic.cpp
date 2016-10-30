#include "arithmetic.h"
#include <iostream>

 int main(){
 	bool flag1 = true, flag3 = true; 
	int p = 0; 
	
	Check str("");
	Check newstr("");
	str.len = 256;
 	setlocale(LC_ALL, "Russian");
 
 	cout << "Enter an expression" << endl;
	cout << "The operations: +, -, /, *, ^. " << endl;
 	while (flag1 == true){
 		cout << "Enter: " ;
		cin >> str.s;
		str.len = str.GetLen();
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
			newstr.len = newstr.GetLen();
 		}
		newstr.len = newstr.GetLen();	
		if (!newstr.CheckBrackets() ||(!newstr.CheckOperands()))
 			cout << "Expression is uncorrect" <<endl;
 		else{
 			double result;
			bool flag2 = true;
			Check newstr1(""), newstr2("");
 			newstr.ChangeExpression(newstr1.s);
			newstr.len = newstr.GetLen();
			newstr1.len = newstr1.GetLen();
 			while (flag2 == true){
				newstr1.len = newstr1.GetLen();
				newstr2.len = newstr2.GetLen();
 				newstr1.Input(newstr2.s); //Çהוסü מרטבךא למזוע בûעü
				newstr2.len = newstr2.GetLen();
				result = newstr2.Calculation();
 				cout << "Result = " << result <<endl;
				str.len = str.GetLen();
				if(str.AreVars())
				{
 				cout << "Expression contians vars. Do you want to enter value? " << endl;
 				cout << "1.Yes" << endl;
 				cout << "2.No" << endl;
 				cin  >> p;
 				if (p == 2)
 					flag2 = false;
				}
				else
					flag2 = false;
 			}
 			flag1 = false;
		//	delete []newstr1.s; delete []newstr2.s;
 		}
 	}
//	delete[]newstr.s;
 return 0;
}