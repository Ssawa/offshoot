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
		virtual int execute() = 0;
		
	public:
		Command(std::string name, std::string description) : name(name), cmd(description, ' ', VERSION) {
			
		}
		
		std::string getName();
		
		virtual int start(int argc, char** argv);
		virtual int run(std::vector<std::string>& args);
		
		void setTCLAPExceptionHandling(const bool state);
	};
}

#endif
