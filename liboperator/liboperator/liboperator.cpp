#include "stdafx.h"
#include <iostream>
#include "has_addition_operator.h"
#include "has_dereference_operator.h"

struct point{
	int x, y;

	point operator + (point const & o)
	{
		point r = *this;
		r.x += o.x;
		r.y += o.y;
		return r;
	}

};

void testing_addition_operator()
{
	static_assert(liboperator::has_addition_operator<point,point>::value == 1,"Points cannot be added");
	static_assert(liboperator::has_addition_operator<point,char>::value == 0,"Points can be added with characters");

	static_assert(liboperator::has_addition_operator<point&,point&>::value == 1,"Points cannot be added");
	static_assert(liboperator::has_addition_operator<point&,char&>::value == 0,"Points can be added characters");

	static_assert(liboperator::has_addition_operator<point*,point*>::value == 1,"Points cannot be added");
	static_assert(liboperator::has_addition_operator<point*,char*>::value == 0,"Points can be added characters");

	static_assert(liboperator::has_addition_operator<point*&,point*&>::value == 1,"Points cannot be added");
	static_assert(liboperator::has_addition_operator<point*&,char*&>::value == 0,"Points can be added characters");
}

void testing_dereference_operator()
{
	static_assert(liboperator::has_dereference_operator<point>::value == 0,"Able to derefence point");
}


int main()
{
	return 0;
}

