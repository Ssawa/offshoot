#include "Command.h"
#include "Poco/Path.h"

namespace offshoot {
	
	Command::Command(std::string name, std::string description) : Command(name, description, new CommandOutput(this)) {
	};
	
	// THE POINTER THAT IS PASSED IN HERE WILL BE CLEANED UP BY OUR DESTRUCTOR, SO DON'T COUNT ON IT STICKING AROUND
	Command::Command(std::string name, std::string description, CommandOutput* output) : name(name), cmd(description, ' ', VERSION) {
		this->output = output;
		this->cmd.setOutput(this->output);
	}
	
	Command::~Command() {
		delete this->output;
	}
	
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
		
		// Clean up our first argument so that it looks cleaner in the usage window (only the executable name, not the full path)
		// Poco is kind of growing on me, by the way. It's not nearly as monolithic as Boost and does pretty much what you need.
		// Unfortunatly I believe Boost's filesystem API is going to be integrated into C++17 so we're backing the wrong pony a bit.
		Poco::Path programPath = Poco::Path(args[0]);
		args[0] = programPath.getFileName();
		
		// Our first argument is the program path, and TCLAP expects it to be there
		if (args.size() > 1) {
			std::string possibleCommand = args[1];
			auto subCommand = this->subcommands.find(possibleCommand);
			if (subCommand != this->subcommands.end()) {
				// Append to the program name so that it appears properly under Usage
				args[0] += " " + possibleCommand;

				// This is what makes me slightly ansy. Should we just use a stupid linked-list?
				args.erase(args.begin() + 1);
				return subCommand->second->run(args);
			}
			
		}
		this->cmd.parse(args);
		return this->execute();
	}
	
	// Here we copy, paste, and tweak, a few functions from TCLAP so it might look a little
	// hairy. We're just trying to make it so that the subcommands get listed
	// for the help and error returns.
	
	void Command::CommandOutput::usage(TCLAP::CmdLineInterface& _cmd )
	{
		std::cout << std::endl << "USAGE: " << std::endl << std::endl;
		
		TCLAP::StdOutput::_shortUsage( _cmd, std::cout );
		
		std::cout << std::endl << std::endl << "Where: " << std::endl << std::endl;
		
		_longUsage( _cmd, std::cout );
		
		std::cout << std::endl;

		this->printSubcommands(std::cout);
	}
	
	void Command::CommandOutput::failure( TCLAP::CmdLineInterface& _cmd,
										 TCLAP::ArgException& e )
	{
		std::string progName = _cmd.getProgramName();
		
		std::cerr << "PARSE ERROR: " << e.argId() << std::endl
		<< "             " << e.error() << std::endl << std::endl;
		
		if ( _cmd.hasHelpAndVersion() )
		{
			std::cerr << "Brief USAGE: " << std::endl;
			
			TCLAP::StdOutput::_shortUsage( _cmd, std::cerr );
			
			std::cout << std::endl;
			
			this->printSubcommands(std::cout);

			std::cerr << std::endl << "For complete USAGE and HELP type: "
			<< std::endl << "   " << progName << " --help"
			<< std::endl << std::endl;
		}
		else
			usage(_cmd);
		
		throw TCLAP::ExitException(1);
	}
	
	void Command::CommandOutput::printSubcommands(std::ostream& os) {
		auto subCommands = this->command->subcommands;
		if (!subCommands.empty()) {
			std::cout << std::endl;

			os << "Subcommands:" << std::endl;
			for (auto const& it : subCommands) {
				os << std::endl;
				std::string progName = this->command->cmd.getProgramName() + " " + it.second->getName();
				it.second->output->_shortUsage(it.second->cmd, os, progName);
			}
			
			std::cout << std::endl;
		}
	}
	
	void Command::CommandOutput::_shortUsage( TCLAP::CmdLineInterface& _cmd, std::ostream& os, std::string progName )
	{
		std::list<TCLAP::Arg*> argList = _cmd.getArgList();
		TCLAP::XorHandler xorHandler = _cmd.getXorHandler();
		std::vector< std::vector<TCLAP::Arg*> > xorList = xorHandler.getXorList();
		
		std::string s = progName + " ";
		
		// first the xor
		for ( int i = 0; static_cast<unsigned int>(i) < xorList.size(); i++ )
		{
			s += " {";
			for ( TCLAP::ArgVectorIterator it = xorList[i].begin();
				 it != xorList[i].end(); it++ )
				s += (*it)->shortID() + "|";
			
			s[s.length()-1] = '}';
		}
		
		// then the rest
		for (TCLAP::ArgListIterator it = argList.begin(); it != argList.end(); it++)
			if ( !xorHandler.contains( (*it) ) )
				s += " " + (*it)->shortID();
		
		// if the program name is too long, then adjust the second line offset
		int secondLineOffset = static_cast<int>(progName.length()) + 2;
		if ( secondLineOffset > 75/2 )
			secondLineOffset = static_cast<int>(75/2);
		
		spacePrint( os, s, 75, 3, secondLineOffset );
	}
	
	int Command::error(std::string message) {
		try {
			auto exception = TCLAP::CmdLineParseException(message);
			cmd.getOutput()->failure(cmd, exception);
			return 1;		
		} catch (TCLAP::ExitException) {
			return 1;
		}
	}

	int Command::requireSubcommand() {
		return this->error("You must specify a subcommand.");
	}
	
}
