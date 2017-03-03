#include "offshoot/commands/MainCommand.h"


int main(int argc, char** argv) {
	try {
		
		offshoot::MainCommand().start(argc, argv);
		
	} catch (TCLAP::ArgException &e) {
		
		std::cerr << "error: " << e.error() << " for arg " << e.argId() << std::endl;
	}
}