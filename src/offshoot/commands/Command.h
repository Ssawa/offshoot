#ifndef Command_h
#define Command_h

#include <memory>
#include <string>
#include <vector>
#include <map>
#include <tclap/CMDLine.h>


namespace offshoot {
	const std::string VERSION = "0.1";
	
	class Command {
		
	protected:
		std::string name;
		TCLAP::CmdLine cmd;

		std::map<std::string, std::shared_ptr<Command> > subcommands;
		
		virtual void addSubCommand(std::shared_ptr<Command> subCommand);
		
	public:
		Command() : cmd("Abstract Command - You should never see this", ' ', VERSION) {
			
		}
		
		~Command() {
			
		}
		
		std::string getName();
		
		virtual int start(int argc, char** argv);
		virtual int run(std::vector<std::string>& args);
	};
}

#endif
