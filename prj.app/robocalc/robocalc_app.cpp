#include<iostream>
#include<fstream>
#include<robocalc.hpp>




int main() {

	std::ifstream f("input.txt");
	RoboCalc r(f);
	//r.Run(f);



	return 0;
}