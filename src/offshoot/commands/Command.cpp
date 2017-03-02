#include "Command.h"

namespace offshoot {
	
	void Command::addSubCommand(std::shared_ptr<Command> subCommand) {
		this->subcommands.insert(std::pair<std::string, std::shared_ptr<Command> >(subCommand->getName(), subCommand));
	}
	
	std::string Command::getName() {
		return this->name;
	}
	
	/*
		Parse the given arguments and run the command, calling subcommands
		if detected.
	 */
	int Command::start(int argc, char**argv) {
		// Just makes dealing with the args easier. TCLAP actually does this
		// itself so we just save it from doing the work.
		std::vector<std::string> args;
		for (int i = 0; i < argc; i++) {
			args.push_back(argv[i]);
		}
		
		return this->run(args);
	}
	
	/*
		Process the arguments and determine if we need to execute the command
	    ourselves or pass on to a subcommand.
	 */
	int Command::run(std::vector<std::string>& args) {
		return 1;
	}
}
