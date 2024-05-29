#include "robocalc.hpp"



RoboCalc::RoboCalc(std::istream& in){
	std::string line;
	std::vector<Command*> cmds;
	while (std::getline(in, line)) {

		Command* cur_cmd= createObject(line);
		
		//std::cout << typeid(*cur_cmd).name() << cur_cmd->writeable()<<  std::endl;
		if (cur_cmd->writeable()) {
			cmds.push_back(cur_cmd);
		}
		else {
			cur_cmd->Execute(cmds);
		}
	}
	for (auto x : cmds) {
		delete x;
	}

}
