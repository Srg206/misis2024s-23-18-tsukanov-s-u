#include<iostream>
#include<fstream>
#include<vector>
#include<comands/comands.hpp>

class RoboCalc {


public:
	RoboCalc()=default;
	RoboCalc(std::istream & in);

	RoboCalc(const RoboCalc& r);
	RoboCalc(RoboCalc&& r);

	RoboCalc& operator= (const RoboCalc& r);
	RoboCalc& operator= (RoboCalc&& r);

	~RoboCalc() = default;



	std::ostream& operator<<(std::ostream& out);
	int Run(std::string path);



private:
	std::vector<Comand> cmdList;



};