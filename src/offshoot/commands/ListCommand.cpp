#include "ListCommand.h"


namespace offshoot {
	
	ListCommand::ListCommand() :
		Command("list", "List the templates associated with an installation of OpenFrameworks"),
		ofPathArg("o", "ofPath", "Path to an installation (or download) of OpenFrameworks", true, ".", "path", this->cmd) {}
	
	int ListCommand::execute() {
		return 0;
	}
}
