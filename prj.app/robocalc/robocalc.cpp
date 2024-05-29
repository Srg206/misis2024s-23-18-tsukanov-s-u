#include "robocalc.hpp"



RoboCalc::RoboCalc(std::istream& in){
	std::string line;
	std::vector<Comand*> cmds;
	while (std::getline(in, line)) {


		createObject(line);


		//auto cur_cmd= createObject(line);
		
		//cur_cmd;



		//if (cur_cmd->writeable()) {
		//	cmds.push_back(cur_cmd);
		//}
		//else {
		//	//cur_cmd->Execute(cmds,0);
		//}
	}
	for (auto x : cmds) {
		delete x;
	}

}
