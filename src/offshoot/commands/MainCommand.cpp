#include "MainCommand.h"
#include "ListCommand.h"

namespace offshoot {

	MainCommand::MainCommand() :
		cmd("offshoot is a fork of the OpenFrameworks maintained projectGenerator to assist in the creation of an OpenFrameworks project with a focus on working outside of the OpenFrameworks source tree and to be built without relying on OpenFrameworks as a library. Get it? 'OF'fshoot. Very clever.", ' ', VERSION) {
			
			this->addSubCommand(std::shared_ptr<Command>(new ListCommand()));
	}

	int MainCommand::execute() {
		return 0;
	}
}
