#include "stdafx.h"
#include <iostream>
#include "has_addition_operator.h"

struct point{
		int x, y;


	};


int main()
{

	
	using namespace std;

	point a;
	a.x = 5;
	a.y = 6;

	point b;
	b.x = 10;
	b.y = 20;

	bool has = liboperator::has_addition_operator<point,point>::value;

	cout << boolalpha << (has) << endl;


	return 0;
}

