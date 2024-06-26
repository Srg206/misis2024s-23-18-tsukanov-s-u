#include "../prj.lab/rational/rational.hpp"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <sstream>
#include <iostream>


void testing() {
  Rational r(int64_t(3));
  std::cout << Rational(4) << std::endl;

  std::cout << Rational(4, 3) << std::endl;
  try {
    std::cout << Rational(4, 0) << std::endl;
  } catch (const std::invalid_argument& e) {
    std::cout << e.what() << std::endl;
  }
  try {
    std::cout << Rational(4, -1) << std::endl;
  } catch (const std::invalid_argument& e) {
    std::cout << e.what() << std::endl;
  }
}

TEST_CASE("rational ctor") {
  Rational r_def;
  CHECK(0 == r_def.get_num());
  CHECK(1 == r_def.get_den());

  Rational r_int(3);
  CHECK(3 == r_int.get_num());
  CHECK(1 == r_int.get_den());

  Rational r_minus_int(-3);
  CHECK(-3 == r_minus_int.get_num());
  CHECK(1 == r_minus_int.get_den());
  Rational r1(2, 3);
  r1 +=Rational(6, 8);// 17/12

  CHECK(r1==Rational(34,24));
  CHECK_THROWS(Rational(1, 0));
}

TEST_CASE("rational gcd") {

  Rational r(15, 6);
  CHECK(5 == r.get_num());
  CHECK(2 == r.get_den());

  Rational r_minus(-15, 6);
  CHECK(-5 == r_minus.get_num());
  CHECK(2 == r_minus.get_den());
}

TEST_CASE("arithmetics") {
  Rational r23(2, 3);
  Rational r12(1, 2);
  Rational r76(7, 6);
  Rational r16(1, 6);
  Rational r0(0, 1);

  CHECK(r76 == r23 + r12);
  CHECK(r16 == r76 - 1);
  CHECK(r76 == r16 * 7);
  CHECK(r76 == 7 * r16);
  CHECK(r16 == r76 / 7);
  CHECK_THROWS(r16/r0);

};

TEST_CASE("IO") {
  std::istringstream istream("2 / 3 "); //?
  Rational reading;
  Rational r23(2, 3);

  istream >> reading;
  CHECK(reading == r23);

  std::istringstream istream2("-3|3"); //?

  //CHECK_THROWS(istream2 >> reading);
  //istream2 >> reading;
  std::cout<<"nsnajdnjasngjnasjk\n\n\n\n\n\n\dnvjsbadjkvbasdbvbsdjvb\n\nn\n\n\"";
  std::cout << r23;
  Rational a(20, 41);
  Rational b(3, 4);
  a > b;
  std::cout << (a > b);
  //CHECK(a > b);


  std::ostringstream ostream;
  ostream<< Rational(2, 3);
  CHECK(ostream.str() == "2/3");
};