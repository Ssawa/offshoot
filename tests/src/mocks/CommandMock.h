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
	
	MockCommand() : valueArg("v", "value", "", false, "", "string", this->cmd) {
	}
	
	MockCommand(std::string name) : valueArg("v", "value", "", false, "", "string", this->cmd) {
		this->name = name;
	}
	
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

#endif
