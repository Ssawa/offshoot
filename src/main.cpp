#include <string>
#include <iostream>
#include <tclap/CMDLine.h>


int main(int argc, char** argv) {
	try {
		TCLAP::CmdLine cmd("offshoot is a fork of the OpenFrameworks maintained projectGenerator to assists in the creation of an OpenFrameworks project with a focus on working outside of the OpenFrameworks source and to be built without relying on OpenFrameworks as a library. Get it? 'OF'fshoot. Very clever.", ' ', "0.1");
		
		TCLAP::UnlabeledValueArg<std::string> projectPathArg("projectPath", "Either a path to where you want your project to be created or a path to an existing project to be updated", false, "", "path", cmd);
		
		TCLAP::ValueArg<std::string> ofPathArg("o", "ofPath", "Path to an installation (or download) of OpenFrameworks", true, ".", "path", cmd);

		TCLAP::MultiArg<std::string> addonsArgs("a", "addon", "An addon you would like added to your project. This can either be a single word, such as \"ofxPoco\" for an addon relative to your OpenFrameworks directory addons or a relative path to a folder, such as \"../ExternalAddons/ofxTimeMeasurements\". Repeat this flag for as many addons as you would like to add.", false, "string", cmd);
		
		TCLAP::SwitchArg listSwitch("l", "list", "List the templates currently available", cmd, false);

		cmd.parse( argc, argv );
		
		if (listSwitch.getValue()) {

		} else {
			// We don't want to make projectPathArg required because it's unnecessary if we're simply listing
			// available templates. Similarly, we don't really want to make it an XOR because we don't really
			// want to make it *mutually* exclusive with listSwitch (we can just ignore it). This use situation
			// doesn't seem to be handled by tclap so we'll just do the check ourselves.
			if (projectPathArg.getValue().empty()) {
				auto exception = TCLAP::CmdLineParseException("You must specify the location of your project");
				cmd.getOutput()->failure(cmd, exception);
				exit(1);
			}
		}
		
	} catch (TCLAP::ArgException &e) {
		std::cerr << "error: " << e.error() << " for arg " << e.argId() << std::endl;
	}
}