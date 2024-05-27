#include "robocalc.hpp"



RoboCalc::RoboCalc(std::istream& in){
	std::string line;
	std::vector<Comand*> cmds;
	while (std::getline(in, line)) {
		Comand* cur_cmd(line);
		cur_cmd->Execute(cmds);
	}

}
