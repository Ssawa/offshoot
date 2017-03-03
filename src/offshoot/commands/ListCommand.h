#ifndef ListCommand_h
#define ListCommand_h

#include "Command.h"

namespace offshoot {
	class ListCommand : public Command {
		
	protected:
		int execute();

	public:
		
		TCLAP::ValueArg<std::string> ofPathArg;
		
		ListCommand();

	};
}

#endif
