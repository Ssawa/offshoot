#include "Command.h"

namespace offshoot {

	void Command::addSubCommand(Command subCommand) {
		this->subcommands.insert(std::pair<std::string, Command>(subCommand.name, subCommand));
	}
}
