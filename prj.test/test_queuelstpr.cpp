#include "../prj.lab/queuelstpr/queuelstpr.hpp"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("constructor test") {

	QueueLstPr a;
	a.Push(1);
	a.Push(3);
	a.Push(7);

	QueueLstPr b;
	b = std::move(a);


}


TEST_CASE("Methods") {
	QueueLstPr a;
	a.Push(1);
	a.Push(4);
	a.Push(5);
	a.Push(3);
	a.Push(7);

	a.Clear();
	CHECK_THROWS(a.Top());


}

