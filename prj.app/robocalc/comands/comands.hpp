#include<string>
#include <sstream>
#include <vector>
#include <iostream>

class Command {
public:
	Command() = default;
	Command(std::string cmd);
	Command(int v) : comand_value(v) {};
	virtual ~Command() = default;

	virtual int Execute(std::vector<Command*>& cmds, int frst);
	virtual void Execute(std::vector<Command*>& cmds);
	void set_value(int v) { comand_value = v; };
	int get_value() { return comand_value; };
	virtual bool writeable();


private: 
	int comand_value;
};


Command* createObject(std::string cmd);


class OUT: public Command {
public:
	OUT(int v) : Command(v) {};
	bool writeable() override { return false; };
	void Execute(std::vector<Command*>& cmds) override;
};

class ADD : public Command {
public:
	ADD(int v) : Command(v) {};
	bool writeable()override { return true; };
	int Execute(std::vector<Command*>& cmds, int frst) override;
};
class SUB : public Command {
public:
	SUB(int v) : Command(v) {};
	bool writeable()override { return true; };
	int Execute(std::vector<Command*>& cmds, int frst) override;
};
class MUL : public Command {
public:
	MUL(int v) : Command(v) {};
	bool writeable()override { return true; };
	int Execute(std::vector<Command*>& cmds, int frst) override;
};

class DIV : public Command {
public:
	DIV(int v) : Command(v) {};
	bool writeable()override { return true; };
	int Execute(std::vector<Command*>& cmds, int frst) override;
};
class REV : public Command {
public:
	REV(int v) : Command(v) {};
	bool writeable()override { return false; };
	void Execute(std::vector<Command*>& cmds) override;
};