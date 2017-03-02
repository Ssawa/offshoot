#ifndef MainCommand_h
#define MainCommand_h

#include "Command.h"

namespace offshoot {
	class MainCommand : public Command {
		
	protected:
		TCLAP::CmdLine cmd;
		
	public:
		MainCommand();
	};
}

#endif
