#include "stdafx.h"
#include <iostream>
#include "has_addition_operator.h"

struct point{
		int x, y;

		point operator + (point const & o){

			point r = *this;
			r.x += o.x;
			r.y += o.y;
			return r;

		}

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

	cout << "Points can be added together is: " << boolalpha << (liboperator::has_addition_operator<point,point>::value) << endl;
	cout << "Points can be with characters is: " << boolalpha << (liboperator::has_addition_operator<point,char>::value) << endl;

	return 0;
}

