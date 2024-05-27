#include<string>
#include <sstream>

class Comand {
public:
	virtual int Execute(std::vector<Comand*>& cmds);
	Comand read(std::string s);
	//std::ostream& operator<<(std::ostream& out);
	Comand(std::string cmd);

	Comand() = default;


	Comand(const Comand& c);
	Comand(Comand&& c);

	Comand& operator = (const Comand & c);
	Comand& operator = (Comand && c);

	~Comand() = default;
private: 
	std::string txt_comand;
	int comand_value;
	virtual bool writeable();
};


class OUT: public Comand {
public:
	OUT();
	bool writeable() { return false; };
	int Execute();

};

class ADD : public Comand {
public:
	ADD();
	bool writeable() { return true; };
	int Execute();
};
class SUB : public Comand {
public:
	SUB();
	bool writeable() { return true; };
	int Execute();
};
class MULL : public Comand {
public:
	MULL();
	bool writeable() { return true; };
	int Execute();
};

class DIV : public Comand {
public:
	DIV();
	bool writeable() { return true; };
	int Execute();
};


class REV : public Comand {
public:
	REV();
	bool writeable() { return false; };
	int Execute();
};