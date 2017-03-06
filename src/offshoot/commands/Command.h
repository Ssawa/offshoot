#ifndef Command_h
#define Command_h

#include <memory>
#include <string>
#include <vector>
#include <map>
#include <tclap/CMDLine.h>


namespace offshoot {
	const std::string VERSION = "0.1";
	
	class Command {
	public:
		
		// I know that nested classes are supported by C++ but do they make
		// anybody else feel a bit uneasy? It might just be my residual guilt
		// for this weird circular dependency. Also it looks ugly and confusing.
		struct CommandOutput : public TCLAP::StdOutput {
			Command* command;

			CommandOutput(Command* command) : command(command){}
			
			void printSubcommands(std::ostream& os);
			virtual void _shortUsage(TCLAP::CmdLineInterface& _cmd, std::ostream& os, std::string progName);
			virtual void usage(TCLAP::CmdLineInterface& _cmd);
			virtual void failure( TCLAP::CmdLineInterface& _cmd, TCLAP::ArgException& e );
		};
		
		Command(std::string name, std::string description, CommandOutput* output);
		Command(std::string name, std::string description);
		~Command();
		
		std::string getName();
		
		virtual int start(int argc, char** argv);
		virtual int run(std::vector<std::string>& args);
		
		void setTCLAPExceptionHandling(const bool state);
		
		int error(std::string message);
		
		int requireSubcommand();

		
	protected:
		std::string name;
		TCLAP::CmdLine cmd;
		CommandOutput* output;

		std::map<std::string, std::shared_ptr<Command> > subcommands;
		
		virtual void addSubCommand(std::shared_ptr<Command> subCommand);
		virtual int execute() { return 0; }
	};
	


}

#endif
