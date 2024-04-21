#include "../prj.lab/stacklstt/stacklstt.hpp"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include"../prj.lab/complex/complex.hpp"


TEST_CASE("stacklstt int test") {
	StackLstT<int> my_stack;
	CHECK_THROWS(my_stack.Top());
	CHECK_EQ(my_stack.IsEmpty(), 1);


	my_stack.Push(4);
	my_stack.Push(5);
	my_stack.Push(8);

	CHECK_EQ(my_stack.Top(), 8);

	my_stack.Pop();
	CHECK_EQ(my_stack.Top(), 5);



	StackLstT<int> my_stack2;
	my_stack2.Push(7);
	my_stack = my_stack2;
	CHECK_EQ(my_stack.Top(), 7);

	StackLstT<int> a(my_stack);
	CHECK_EQ(a.Top(), 7);

	my_stack.Push(11);
	CHECK_EQ(my_stack.Top(), 11);
	my_stack.Push(13);
	CHECK_EQ(my_stack.Top(), 13);
}

TEST_CASE("stacklstt Complex test") {
	StackLstT<Complex> my_stack;
	CHECK_THROWS(my_stack.Top());
	CHECK_EQ(my_stack.IsEmpty(), 1);

	Complex cc(3,5);

	my_stack.Push(cc);
	//my_stack.Push(Complex(3, 5));
	//my_stack.Push(Complex(2, 7));

	//CHECK_EQ(my_stack.Top(), Complex(2, 7));

	//my_stack.Pop();
	//CHECK_EQ(my_stack.Top(), Complex(3, 5));



	//StackLstT<Complex> my_stack2;
	//my_stack2.Push(Complex(1, 1));
	//my_stack = my_stack2;
	//CHECK_EQ(my_stack.Top(), Complex(1, 1));

	//StackLstT<Complex> a(my_stack);
	//CHECK_EQ(a.Top(), Complex(1, 1));

	//my_stack.Push(Complex(2.3, 7.3));
	//CHECK_EQ(my_stack.Top(), Complex(2.3, 7.3));
	//my_stack.Push(Complex(2.003, 0));
	//CHECK_EQ(my_stack.Top(), Complex(2.003, 0));
}
TEST_CASE("Stress test") {


	//StackLstT a;
	//srand(time(0));

	//for (int i = 0; i < 1000; i++) {
	//	a.Push(abs(rand()));
	//}
	//for (int i = 0; i < 1000; i++) {
	//	a.Pop();
	//}



}