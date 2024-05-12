#pragma once
#include"List.h"
struct Monom {
	double coef;
	size_t degx;
	size_t degy;
	size_t degz;
};

class Polynom
{
	myList<Monom> poly;
public:
	Polynom() {}
	void parseAndAddMonoms(const string input);
	void printPolynom();
	void castMonom();
	
	void addPolynom(Polynom& p);
	void substructPoly(Polynom& p);
	void multiplyPolynom(Polynom& p);
};