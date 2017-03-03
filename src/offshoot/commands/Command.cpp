#include "Command.h"

namespace offshoot {
	
	void Command::addSubCommand(std::shared_ptr<Command> subCommand) {
		this->subcommands.insert(std::pair<std::string, std::shared_ptr<Command> >(subCommand->getName(), subCommand));
	}
	
	std::string Command::getName() {
		return this->name;
	}
	
	void Command::setTCLAPExceptionHandling(const bool state) {
		this->cmd.setExceptionHandling(state);
	}
	
	/*
		Start the command process. This should only be called with the original
		argument list as it was passed into the program
	 */
	int Command::start(int argc, char**argv) {

		// We're going to have to be shuffling around near the beginning of the sequence (in order to remove the requested
		// subcommands) so perhaps a list is best suited for us. However we should only have to do this operation a few times and
		// we'll need to convert to a vector anyway when we hand off to TCLAP which would, assumingly, mean we'd have to
		// walk and reallocate the whole linked-list, which would be much slower. Right? I don't know. Premature optimization
		// just to even think this much about it. How many arguments can there possibily be that it would make a difference?
		std::vector<std::string> args;
		for (int i = 0; i < argc; i++) {
			// I believe that NULL is *supposed* to be at the end of the passed in args but I haven't seen it empirically yet
			// (and it doesn't seem to be accounted for by TCLAP either). But I guess it doesn't hurt to be safe.
			if (argv[i] != NULL){
				args.push_back(argv[i]);
			}
		}
		
		return this->run(args);
	}
	
	/*
		Process the arguments and determine if we need to execute the command
	    ourselves or pass on to a subcommand.
	 */
	int Command::run(std::vector<std::string>& args) {
		
		// Our first argument is the program path, and TCLAP expects it to be there
		if (args.size() > 1) {
			std::string possibleCommand = args[1];
			auto subCommand = this->subcommands.find(possibleCommand);
			if (subCommand != this->subcommands.end()) {
				// This is what makes me slightly ansy. Should we just use a stupid linked-list?
				args.erase(args.begin() + 1);
				return subCommand->second->run(args);
			}
			
		}
		this->cmd.parse(args);
		return this->execute();
	}
}
