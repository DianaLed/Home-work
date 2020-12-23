#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>
#include "TStack.h"
#include "TScaner.h"
#include "TFormPoliz.h"
#include "TRecord.h"
#include "TTable.h"
#include "TPolizCalculate.h"
using namespace std;

int seach_place_br(char* a, int nom) {
	int dop = -1;
	for (int i = 0; i < 200; i++) {
		if ((a[i] == '(')|| (a[i] == ')')) dop++;
		if (dop == nom) return i;
	}
	return -1;
}

bool type_br(char* a, int nom) {
	int dop = 0;
	try
	{
		int i = seach_place_br(a, nom);
	  if (a[i] == '(') return  0;
	  if (a[i] == ')') return  1;
		throw - 1; // типичный стейтмент throw
	}
	catch (int) {
		cout << "Exeption, not found element" << endl;
	}
	return 0;
}

int doSkbControl(char *ch) {
	int sum=0;
	for (int i = 0; i < 200; i++) {
		if (ch[i] == '(') sum++;
		if (ch[i] == ')') sum++;
	}
	bool* type_mass_br = new bool[sum];//0-'(', 1-')'
	bool* v_mass_br = new bool[sum]; //вектор выводили(0) ли мы скобки или нет(1)
	for (int i = 0; i < sum; i++) {
		v_mass_br[i] = 1;
		type_mass_br[i] = type_br(ch, i);
	}
	bool dop = 1;
	int nom_cl, nom_op, res = 0;;
	while (dop) {
		nom_cl = sum+1;
		nom_op = -1;
		for (int i = 0; i < sum; i++) {
			if ((type_mass_br[i]) && (v_mass_br[i])) {
				nom_cl = i;
				break;
			}
		} //нашли закрывающую скобку
		for (int i = nom_cl-1; i >= 0; i--) {
			if (!(type_mass_br[i]) && (v_mass_br[i])) {
				nom_op = i;
				break;
			}
		} //нашли открывающую скобку к найденной закрывающей
		if ((nom_op != -1) && (nom_cl != sum+1)) {
			cout << seach_place_br(ch, nom_op) << " - " << seach_place_br(ch, nom_cl) << endl;
			v_mass_br[nom_op] = 0;
			v_mass_br[nom_cl] = 0;
		} //вывели и отметили 
		else {//если нашлась непарная
			if (nom_op == -1) {
				cout << "? - " << seach_place_br(ch, nom_cl) << endl;
				v_mass_br[nom_cl] = 0;
			} else {
				cout << seach_place_br(ch, nom_op) << " - ?"<< endl;
				v_mass_br[nom_op] = 0;
			}
		  res++;
		}
		dop = 0;
		for (int i = 0; i < sum; i++) {
			dop = dop + v_mass_br[i];
			if(dop==1) break;
		}
	}
	delete[] v_mass_br;
	delete[] type_mass_br;
	return res;
}




int main() {
	{
		TTable<double> varTable;
		char expr[200] = "x + 5.5";
		cout << "Test 1. Expr = " << expr << endl;
		// 1. x = 4.5 -> res = 10
		// 2. x = -4.5 -> res = 1

		TFormPoliz poliz(expr);
		/*poliz.formPizExpr(varTable);*/
		char* pizExpr = poliz.getPizPoliz();

		cout << "1. pizExpr:" << endl;
		cout << "Expected pizExpr: x 5.5 +" << endl;
		cout << "Actual pizExpr:   " << pizExpr << endl;

		varTable.ImpTFormPoliz(poliz);
		cout << "2. Print table before:" << endl;
		varTable.outputVarTable();
		cout << "3. Enter variables:" << endl;
		varTable.inputVarValues();
		cout << "4. Print table after:" << endl;
		varTable.outputVarTable();

		TPolizCalculate polizCalculate(pizExpr, varTable);
		double res = polizCalculate.calculatePizExpr();

		cout << "5. res = " << res << endl;
		cout << endl;
	}
//
	{
		TTable<double> varTable;
		char expr[200] = "5.5 - x";
		cout << "Test 2. Expr = " << expr << endl;
		// 1. x = 4.5 -> res = 1
		// 2. x = -4.5 -> res = 10

		TFormPoliz poliz(expr);
		/*poliz.formPizExpr(varTable);*/
		char* pizExpr = poliz.getPizPoliz();

		cout << "1. pizExpr:" << endl;
		cout << "Expected pizExpr: 5.5 x -" << endl;
		cout << "Actual pizExpr:   " << pizExpr << endl;

		cout << "2. Print table before:" << endl;
		varTable.outputVarTable();
		cout << "3. Enter variables:" << endl;
		varTable.inputVarValues();
		cout << "4. Print table after:" << endl;
		varTable.outputVarTable();

		TPolizCalculate polizCalculate(pizExpr, varTable);
		double res = polizCalculate.calculatePizExpr();

		cout << "5. res = " << res << endl;
		cout << endl;
	}
return 0;
}