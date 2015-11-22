#include "arithmetic.h"

using namespace std;


int main()
{   
	double a = 0;
	double b = 0;
	double c = 0;
	double d = 0;
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
		if (Formula.GetSymbvolOfFormula(i) == 'a')
		{
			
			cout << "BBedute a" << endl;
			cin >> a;
			cout << endl;
			
		}
		if (Formula.GetSymbvolOfFormula(i) == 'b')
		{
			
			cout << "BBedute b" << endl;
			cin >> b;
			cout << endl;
		}
		if (Formula.GetSymbvolOfFormula(i) == 'c')
		{
			cout << "BBedute c" << endl;
			cin >> c;
			cout << endl;
		}
		if (Formula.GetSymbvolOfFormula(i) == 'd')
		{
			cout << "BBedute d" << endl;
			cin >> d;
			cout << endl;
		}
	}

	Formula.SetParamater(a,b,c,d);
	rez = Formula.Calc();
	cout << rez << endl;
	system("pause");
}