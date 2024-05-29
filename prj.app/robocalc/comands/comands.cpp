#include"comands.hpp"


Command* createObject(std::string cmd) {
	std::string comand = "";
	int value = 0;
	std::istringstream iss(cmd);
	iss >> comand >> value;

	if (comand == "OUT") {
		return new OUT(value);
	}

	if (comand == "ADD") {
		ADD* tmp = new ADD(value);
		return tmp;

	}

	if (comand == "SUB") {
		SUB* tmp = new SUB(value);
		return tmp;
	}
	if (comand == "MUL") {
		MUL* tmp = new MUL(value);
		return tmp;
	}
	if (comand == "DIB") {
		DIV* tmp = new DIV(value);
		return tmp;
	}
	if (comand == "REV") {
		REV* tmp = new REV(value);
		return tmp;
	}

	return nullptr;
}

int Command::Execute(std::vector<Command*>& cmds, int frst) 
{
	return 0;
}

void Command::Execute(std::vector<Command*>& cmds)
{
}

bool Command::writeable()
{
	return false;
}


void OUT::Execute(std::vector<Command*>& cmds)
{
	int tmp = get_value();
	for (auto x : cmds) {
		tmp = x->Execute(cmds, tmp);
	}
	std::cout << tmp << std::endl;
}

void REV::Execute(std::vector<Command*>& cmds)
{
	cmds.resize(std::ssize(cmds) - get_value());
}

int ADD::Execute(std::vector<Command*>& cmds, int frst)
{
	return frst+get_value();
}

int SUB::Execute(std::vector<Command*>& cmds, int frst)
{
	return frst - get_value();
}


int MUL::Execute(std::vector<Command*>& cmds, int frst)
{
	return frst * get_value();
}


int DIV::Execute(std::vector<Command*>& cmds, int frst)
{
	if (get_value() == 0) {
		std::cout << "Could not div on Zero !!!!!" << std::endl;
	}
	return frst / get_value();
}




