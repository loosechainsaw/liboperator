#include "stdafx.h"
#include <iostream>
#include <memory>
#include "has_addition_operator.h"
#include "has_subtraction_operator.h"
#include "has_dereference_operator.h"
#include "has_addressof_operator.h"
#include "has_subscript_operator.h"

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

struct point2{
	int x, y;

	point2 operator - (point2 const & o)
	{
		point2 r = *this;
		r.x -= o.x;
		r.y -= o.y;
		return r;
	}

};

class fake_address_of{
public:
	int* operator & (){
		return nullptr;
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

void testing_subtraction_operator()
{
	static_assert(liboperator::has_subtraction_operator<point2,point2>::value == 1,"Point2s cannot be subtracted");
	static_assert(liboperator::has_subtraction_operator<point,point>::value == 0,"Points can be subtracted");

	static_assert(liboperator::has_subtraction_operator<point2&,point2&>::value == 1,"Point2s cannot be added");
	static_assert(liboperator::has_subtraction_operator<point&,point&>::value == 0,"Points can be added");

	static_assert(liboperator::has_subtraction_operator<point2*,point2*>::value == 1,"Point2s cannot be added");
	static_assert(liboperator::has_subtraction_operator<point*,point*>::value == 0,"Points can be added");

	static_assert(liboperator::has_subtraction_operator<point2*&,point2*&>::value == 1,"Point2s cannot be added");
	static_assert(liboperator::has_subtraction_operator<point*&,point*&>::value == 0,"Points can be added");
}

void testing_dereference_operator()
{
	static_assert(liboperator::has_dereference_operator<point>::value == 0,"Able to derefence point");
}

void testing_addressof_operator()
{
	static_assert(liboperator::has_addressof_operator<point*>::value == 1,"Unable to get address of a point");
	static_assert(liboperator::has_addressof_operator<std::shared_ptr<point>>::value == 0,"Cant get address of shared_ptr");
	static_assert(liboperator::has_addressof_operator<point>::value == 0,"can get address of a point");
	static_assert(liboperator::has_addressof_operator<fake_address_of>::value == 1,"fake_address_of should have address of operator");
	
}

void testing_subscript_operator(){
	static_assert(liboperator::has_subscript_operator<fake_address_of>::value == 0,"fake_address_of should have address of operator");
	static_assert(liboperator::has_subscript_operator<int[5]>::value == 1,"fake_address_of should have address of operator");
}

int main()
{
	return 0;
}

