#ifndef CommandMock_h
#define CommandMock_h

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "offshoot/commands/Command.h"


class MockCommand : public offshoot::Command {
public:
	// We won't go ahead and do a comprehensive test of everything TCLAP has to offer,
	// let's hope that it works as advertised, but this one arg should at least give us a good
	// indication that we're interfacing with it correctly
	TCLAP::ValueArg<std::string> valueArg;
	
	MockCommand(std::string name) : offshoot::Command(name, ""), valueArg("v", "value", "", false, "", "string", this->cmd) {}
	MockCommand() : MockCommand("") {}

	MockCommand(std::string name, offshoot::Command::CommandOutput* output) : offshoot::Command(name, "", output), valueArg("v", "value", "", false, "", "string", this->cmd) {}
	
	// Make addSubCommand public and not mocked
	virtual void nonMockedAddSubCommand(std::shared_ptr<Command> subCommand) {
		offshoot::Command::addSubCommand(subCommand);
	}
	
	MOCK_METHOD1(run, int(std::vector<std::string>& args));
	MOCK_METHOD0(execute, int());
	
	void setName(std::string name) {
		this->name = name;
	}
};

class RunnableMockCommand : public MockCommand {
public:
	RunnableMockCommand(std::string name) : MockCommand(name) {}
	
	virtual int run(std::vector<std::string>& args) {
		return offshoot::Command::run(args);
	}
};

class MockCommandOutput : public offshoot::Command::CommandOutput {
	MOCK_METHOD3(_shortUsage, void(TCLAP::CmdLineInterface& _cmd, std::ostream& os, std::string progName));
	MOCK_METHOD1(usage, void(TCLAP::CmdLineInterface& _cmd));
	MOCK_METHOD2(failure, void( TCLAP::CmdLineInterface& _cmd, TCLAP::ArgException& e ));
};

#endif
