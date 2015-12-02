#include "arithmetic.h"

using namespace std;


int main()
{   
	double a = 0;
	double b = 0;
	double c = 0;
	double d = 0;
	int flag[4]={0,0,0,0};
	arithmetic Formula;
	double rez;
	string strformula;
	
	cout << "DocTynHble napametpbl : a,b,c,d" << endl;
	cout << "BBedute formuly" << endl;
	cin >> strformula;
	Formula.SetFormula(strformula);
	Formula.InfixToPost();
	strformula = Formula.GetPost();
	cout << "3anucb: " << strformula << endl;
	for (int i = 0; i < Formula.GetPost().size(); i++)
	{
		if ((Formula.GetSymbvolOfFormula(i) == 'a')&& (flag[0]==0))
		{
			
			cout << "BBedute a" << endl;
			cin >> a;
			cout << endl;
			flag[0]=1;
			
		}
		if ((Formula.GetSymbvolOfFormula(i) == 'b')&&(flag[1]==0))
		{
			
			cout << "BBedute b" << endl;
			cin >> b;
			cout << endl;
			flag[1]=1;
		}
		if ((Formula.GetSymbvolOfFormula(i) == 'c')&&(flag[2]==0))
		{
			cout << "BBedute c" << endl;
			cin >> c;
			cout << endl;
			flag[2]=1;
		}
		if ((Formula.GetSymbvolOfFormula(i) == 'd')&&(flag[3]==0))
		{
			cout << "BBedute d" << endl;
			cin >> d;
			cout << endl;
			flag[3]=1;
		}
	}

	Formula.SetParamater(a,b,c,d);
	rez = Formula.Calc();
	cout << rez << endl;
	system("pause");
}