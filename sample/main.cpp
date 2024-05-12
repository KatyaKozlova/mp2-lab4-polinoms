#include <iostream>
#include <string>
#include "Polinom.h"
#include <locale>

void main() {
	setlocale(LC_ALL, "rus");
	cout << "0. Multiply polynoms" << endl << "1. Add Polynoms" <<
		endl << "2. Substruct Polynoms" << "4. Constant Multiply" << endl;
	int selector = 0;
	string str;
	cin >> selector;
	switch (selector) {
	case 0: {
		system("cls");
		cout << "Enter the first polynom ";
		cin >> str;
		double x, y, z;
		Polynom p;
		p.parseAndAddMonoms(str);
		cout << endl << "1st polynom: "; p.printPolynom(); cout << endl;
		cout << "Enter the second polynom ";
		cin >> str;
		Polynom p2;
		p2.parseAndAddMonoms(str);
		cout << endl << "2nd polynom: "; p2.printPolynom();
		p.multiplyPolynom(p2);
		cout << "p1 * p2: "; p.printPolynom(); cout << endl;
		system("pause");
		break;
	}
	case 1: {
		system("cls");
		cout << "Enter the first polynom ";
		cin >> str;
		double x, y, z;
		Polynom p;
		p.parseAndAddMonoms(str);
		cout << endl << "1st polynom: "; p.printPolynom(); cout << endl;
		cout << "Enter the second polynom "; cin >> str;
		Polynom p2;
		p2.parseAndAddMonoms(str);
		cout << endl << "2nd polynom: "; p2.printPolynom();
		p2.addPolynom(p);
		cout << "p1 + p2: "; p2.printPolynom(); cout << endl;
		system("pause");
		break;
	}
	}
}