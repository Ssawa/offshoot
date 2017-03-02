#include "ListCommand.h"


namespace offshoot {
	
	ListCommand::ListCommand() :
		cmd("List the templates associated with an installation of OpenFrameworks", ' ', VERSION),
		ofPathArg("o", "ofPath", "Path to an installation (or download) of OpenFrameworks", true, ".", "path") {
			
		this->cmd.add(this->ofPathArg);
	}
}
