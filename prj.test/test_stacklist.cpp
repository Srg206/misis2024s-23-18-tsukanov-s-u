#include "../prj.lab/StackList/StackList.hpp"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"


TEST_CASE("stackarr test") {
	StackList my_stack;
	CHECK_THROWS(my_stack.Top());
	CHECK_EQ(my_stack.IsEmpty(), 1);

	my_stack.Push(Complex(3, 5));
	my_stack.Push(Complex(2, 7));

	CHECK_EQ(my_stack.Top(), Complex(2, 7));

	my_stack.Pop();
	CHECK_EQ(my_stack.Top(), Complex(3, 5));



	StackList my_stack2;
	my_stack2.Push(Complex(1, 1));
	my_stack = my_stack2;
	CHECK_EQ(my_stack.Top(), Complex(1, 1));

	StackList a(my_stack);
	CHECK_EQ(a.Top(), Complex(1, 1));

	my_stack.Push(Complex(2.3, 7.3));
	CHECK_EQ(my_stack.Top(), Complex(2.3, 7.3));
	my_stack.Push(Complex(2.003, 0));
	CHECK_EQ(my_stack.Top(), Complex(2.003, 0));
}
