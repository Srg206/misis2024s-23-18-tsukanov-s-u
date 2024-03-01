#include "../prj.lab/queuearr/queuearr.hpp"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include<iostream>
TEST_CASE("ctor") {
	QueueArr my_queue;
	CHECK_THROWS(my_queue.Top());
	CHECK_EQ(my_queue.IsEmpty(), 1);

	my_queue.Push(Complex(3, 5));
	my_queue.Push(Complex(2, 7));
	//my_queue.print();

	CHECK_EQ(my_queue.Top(), Complex(3, 5));
	my_queue.Pop();
	CHECK_EQ(my_queue.Top(), Complex(2, 7));



	QueueArr my_queue2;
	my_queue2.Push(Complex(1, 1));
	my_queue2.Push(Complex(2, 2));
	my_queue2.Push(Complex(3, 4));
	my_queue2.Push(Complex(5, 5));
	my_queue2.Push(Complex(6, 6));

	my_queue = my_queue2;
	my_queue.print();
	my_queue2.print();
	my_queue.print();

	my_queue.Clear();

	my_queue.Push(Complex(1, 1));
	my_queue.Push(Complex(2, 2));
	my_queue.Push(Complex(3, 4));
	my_queue.Push(Complex(5, 5));
	my_queue.Push(Complex(5, 5));
	my_queue.Push(Complex(5, 5));
	my_queue.Push(Complex(5, 5));
	my_queue.Push(Complex(5, 5));
	my_queue.Push(Complex(5, 5));
	my_queue.Push(Complex(5, 5));
	my_queue.Push(Complex(5, 5));
	my_queue.Push(Complex(6, 6));
	my_queue.Push(Complex(6, 6));
	my_queue.Push(Complex(6, 6));
	my_queue.Push(Complex(6, 6));
	my_queue.Push(Complex(6, 6));
	my_queue.Clear();
	my_queue.Push(Complex(6, 6));
	my_queue.Push(Complex(2, 2));
	my_queue.Push(Complex(3, 4));
	my_queue.Push(Complex(5, 5));
	my_queue.Push(Complex(5, 5));
	my_queue.Push(Complex(5, 5));
	my_queue.Push(Complex(5, 5));
	my_queue.Push(Complex(5, 5));
	my_queue.Push(Complex(5, 5));
	my_queue.Push(Complex(5, 5));
	my_queue.Push(Complex(5, 5));
	my_queue.Push(Complex(6, 6));
	my_queue.Push(Complex(6, 6));
	my_queue.Push(Complex(6, 6));
	my_queue.Push(Complex(6, 6));
	my_queue.Push(Complex(6, 6));
	my_queue.Push(Complex(6, 6));
	my_queue.print();
	my_queue.Pop();
	my_queue.print();
	my_queue.Pop();
	my_queue.print();
	my_queue.Pop();
	my_queue.print();
	my_queue.Pop();
	my_queue.print();
	my_queue.Pop();
	my_queue.print();
	my_queue.Pop();
	my_queue.print();
	my_queue.Pop();
	my_queue.print();
	my_queue.Pop();
	my_queue.print();
	my_queue.Pop(); my_queue.print(); my_queue.Pop(); my_queue.print(); my_queue.Pop(); my_queue.print(); my_queue.Pop(); my_queue.print(); my_queue.Pop(); my_queue.print(); my_queue.Pop(); my_queue.print(); my_queue.Pop(); my_queue.print(); my_queue.Pop(); my_queue.print(); my_queue.Pop(); my_queue.print(); my_queue.Pop(); my_queue.print(); my_queue.Pop();

	//CHECK_EQ(my_queue.Top(), Complex(1, 1));

	QueueArr a(my_queue);
	//CHECK_THROWS(a.Top());

	my_queue.Clear();

	my_queue.Push(Complex(2.3, 7.3));

	CHECK_EQ(my_queue.Top(),Complex(2.3,7.3));
	Complex addddd = my_queue.Top();

	/*my_queue.Push(Complex(2.003, 0));
	CHECK_EQ(my_queue.Top(), Complex(2.003, 0));*/


}