#include<string>
#include <sstream>
#include <vector>

class Comand {
public:
	Comand() = default;
	Comand(std::string cmd);
	Comand(int v) : comand_value(v) {};
	virtual ~Comand() = default;

	virtual void Execute(std::vector<Comand*>& cmds, int skip);
	virtual void Execute(std::vector<Comand*>& cmds);
	void set_value(int v) { comand_value = v; };
	int get_value() { return comand_value; };
	virtual bool writeable();


private: 
	int comand_value;
};


Comand* createObject(std::string cmd);


class OUT: public Comand {
public:
	OUT(int v) : Comand(v) {};
	bool writeable() override { return false; };
	void Execute(std::vector<Comand*>& cmds) override;
};

class ADD : public Comand {
public:
	ADD(int v) : Comand(v) {};
	bool writeable() { return true; };
	void Execute(std::vector<Comand*>& cmds, int frst) override;
};
class SUB : public Comand {
public:
	SUB(int v) : Comand(v) {};
	bool writeable() { return true; };
	void Execute(std::vector<Comand*>& cmds, int frst);
};
class MULL : public Comand {
public:
	MULL(int v) : Comand(v) {};
	bool writeable() { return true; };
	void Execute(std::vector<Comand*>& cmds, int frst);
};

class DIV : public Comand {
public:
	DIV(int v) : Comand(v) {};
	bool writeable() { return true; };
	void Execute(std::vector<Comand*>& cmds, int frst);
};
class REV : public Comand {
public:
	REV(int v) : Comand(v) {};
	bool writeable() { return false; };
	void Execute(std::vector<Comand*>& cmds);
};