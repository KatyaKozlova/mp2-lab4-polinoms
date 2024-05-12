#include "Polinom.h"
#include <gtest.h>

TEST(Polynom, can_create_polynom_from_string) {
	string str = "xy2+12,1yz3-4x2y3z5";
	Polynom p;
	ASSERT_NO_THROW(p.parseAndAddMonoms(str));
}



TEST(Polynom, can_add_polynom) {
	string str = "xy2+12,1yz3-4x2y3z5";
	string str2 = "1-12yz3+6x4yz6";
	Polynom p, p2;
	p.parseAndAddMonoms(str);
	p2.parseAndAddMonoms(str2);
	ASSERT_NO_THROW(p.addPolynom(p2));
}

TEST(Polynom, can_multiply_two_polynoms) {
	string str = "xy2+12,1yz3-4x2y3z5";
	string str2 = "1-12yz3+6x4yz6";
	Polynom p, p2;
	p.parseAndAddMonoms(str);
	p2.parseAndAddMonoms(str2);
	ASSERT_NO_THROW(p.multiplyPolynom(p2));
}

TEST(Polynom, can_multiply_polynom_by_a_number) {
	string str = "xy2+12,1yz3-4x2y3z5";
	Polynom p, p2;
	p2.parseAndAddMonoms("5");
	p.parseAndAddMonoms(str);
	ASSERT_NO_THROW(p.multiplyPolynom(p2));
}


