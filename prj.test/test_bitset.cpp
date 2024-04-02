#include"../prj.lab/bitset/bitset.hpp"
#include<chrono>
#include <bitset> 
#include<iostream>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Constructors") {


    BitSet a;
    BitSet b;
    a.Resize(100000000);
    b.Resize(73);
    b.fill(1);
    auto start = std::chrono::steady_clock::now();
   // BitSet c(a);//3985000 ns


    BitSet c(std::move(a)); //4400 ns
    auto end = std::chrono::steady_clock::now();

    std::cout << "Elapsed time in nanoseconds: "
        << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()
        << " ns" << std::endl;
}
TEST_CASE("Resize") {
    //BitSet a;
    //a.Resize(15);


    //a.Resize(100000000);
    //a.fill(false);
    ////a.print();
    //a.Resize(10);
    //a.fill(true);
    //a.print();
}

TEST_CASE("Get/Set index") {
    BitSet a;
    a.Resize(10);
    a.fill(false);
    a.print();


    a.Get(4);


    a.Set(3, 1);
    a.Set(3, 1);
    a.Set(7, 1);
    a.Set(8, 1);
//    a.Set(13, 1);

    a.print();
}

TEST_CASE("operators") {
    srand(time(0));
    BitSet a;
    BitSet b;
    a.Resize(50);
    b.Resize(60);

    a.fill(0);
    b.fill(0);

    a.Set(32, 1);
    a.Set(1, 1);
    
    b.Set(32, 1);
    b.Set(1, 1);

    for (int i = 0; i < 1000; i++) {
        int a_id = (abs(rand()) % 49)+1;
        int b_id = (abs(rand()) % 59)+1;

        bool val_a = abs(rand() % 2);
        bool val_b = abs(rand() % 2);
        a.Set(a_id, val_a);
        b.Set(b_id, val_b);
    }

    a.print();
    //b.print();


    BitSet c = ~a;
    c.print();

    a.print();
    
}

TEST_CASE("BiA") {

    BitSet bits;
    bits.Resize(500);
    srand(time(0));

    bits.Set(81, 1);


    for (int i = 1; i < 1000; i++) {
        //bits[(rand()+1) % 500] = rand() & 2;
        uint32_t _ind = (rand() % 500)+1;
        int val = rand()%2;
        //bits.Set(_ind, val);
        bits[_ind] = val;
        //bool(bits[_ind]) = val;
        //std::cout <<_ind <<" - " << val <<"   " << i << std::endl;
  
    }
    std::cout << std::endl;
    //bits.print();
    
    
    //std::cout<<bits[3]<<std::endl;

}

