#include"comands.hpp"


Comand* createObject(std::string cmd) {
	//std::string comand = "";
	//int value = 0;
	//std::istringstream iss(cmd);
	//iss >> comand >> value;

	//if (comand == "OUT") {
	//	return new OUT(value);
	//}

	//if (comand == "ADD") {
	//	ADD* tmp = new ADD(value);
	//	return tmp;

	//}

	//if (comand == "SUB") {
	//	SUB* tmp = new SUB(value);
	//	return tmp;
	//}
	//if (comand == "MULL") {
	//	MULL* tmp = new MULL(value);
	//	return tmp;
	//}
	//if (comand == "DIB") {
	//	DIV* tmp = new DIV(value);
	//	return tmp;
	//}
	//if (comand == "REV") {
	//	REV* tmp = new REV(value);
	//	return tmp;
	//}

	return new Comand();
}