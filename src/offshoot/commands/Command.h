#ifndef Command_h
#define Command_h

#include <string>
#include <map>
#include <tclap/CMDLine.h>


namespace offshoot {
	class Command {
	private:
		std::string name;
		TCLAP::CmdLine cmd;
		std::map<std::string, Command> subcommands;
		
	protected:
		virtual void addSubCommand(Command subCommand);
	};
}

#endif
