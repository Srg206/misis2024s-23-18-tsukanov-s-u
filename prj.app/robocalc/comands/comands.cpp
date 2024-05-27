#include"comands.hpp"

Comand::Comand(std::string cmd) {
	std::string comand="";
	int value=0;
	std::istringstream iss(cmd);
	iss >> comand >> value;
	
	if (comand == "OUT") {
		OUT(value);
	}	

	if (comand == "ADD") {
		ADD(value);

	}

	if (comand == "SUB") {
		SUB(value);
	}
	if (comand == "MULL") {
		MULL(value);
	}
	if (comand == "DIB") {
		DIV(value);
	}
	if (comand == "REV") {
		REV(value);
	}
}
