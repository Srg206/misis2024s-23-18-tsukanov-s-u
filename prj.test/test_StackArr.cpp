#include "../prj.lab/StackArr/StackArr.hpp"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"


TEST_CASE("ctor") {
	StackArr a;
	StackArr b;
	CHECK_THROWS(a.Top());
	CHECK_THROWS(b.Top());
	CHECK(a.IsEmpty() == true);
	CHECK(b.IsEmpty() == true);

	a.Push({ 3, 4 });
	a.Push(Complex(7, 4));
	a.Push(Complex(2, 5));

	a.Pop();
	a.Pop();
	a.Pop();
	a.Pop();
	a.Pop();
	a.Pop();
	a.Push(Complex(3, 4));
	a.Push(Complex(7, 4));
	a.Push(Complex(2, 5));


	StackArr c(a);
	CHECK(c.Top() == Complex(2, 5));

	b = a;
	CHECK(b.Top() == Complex(2, 5));
}

TEST_CASE("Push & Pop") {
	StackArr a;
	for (size_t i = 0; i < 100; i++)
	{
		a.Push({ 3, 4 });
		a.Push(Complex(7, 4));
		a.Push(Complex(2, 5));

	}
	for (size_t i = 0; i < 333; i++)
	{
		a.Pop();
	}
	CHECK_THROWS(a.Top());
	CHECK(a.IsEmpty() == true);
}
