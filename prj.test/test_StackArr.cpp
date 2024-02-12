#include "../prj.lab/stackarr/stackarr.hpp"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("constructor test") {
	StackArr stack1;
	CHECK_THROWS(stack1.Top());
	Complex a(3, 4);
	Complex b(a);
	stack1.Push(a);
	CHECK(stack1.Top() == b);
	StackArr stack2;
	stack2 = stack1;
	CHECK(stack2.Top() == stack1.Top());
}
TEST_CASE("methods test") {
	StackArr stack1;
	stack1.Push(Complex(5, 6));
	CHECK(stack1.IsEmpty() == false);
	Complex b(5, 6);
	CHECK(stack1.Top() == b);
	stack1.Pop();
	stack1.Pop();
	stack1.Pop();
	CHECK(stack1.IsEmpty() == true);
	StackArr stack2;
	stack2.Push(Complex(1, 1));
	stack2.Push(Complex(2, 2));
	stack2.Push(Complex(3, 3));
	stack2.Push(Complex(4, 4));
	stack2.Push(Complex(5, 5));
	Complex comp(5, 5);
	Complex minus(1, 1);
	for (int i = 0; i <= 5; ++i) {
		if (i < 5) {
			CHECK(stack2.IsEmpty() == false);
			CHECK(comp == stack2.Top());
			comp -= minus;
			stack2.Pop();
		}
		else {
			CHECK(stack2.IsEmpty() == true);
			CHECK_THROWS(stack2.Top());
		}

	}

}
TEST_CASE("DDDD") {
	StackArr s1;
	//s1.Push();

}