#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "offshoot/commands/Command.h"
#include "mocks/CommandMock.h"

// Test that our start method calls run with a properly parsed vector
TEST(offshoot_Command, StartMethod) {
	
	MockCommand cmd;
	
	// This will throw a warning because we're using C style strings which is annoying
    // but I'm not sure if there's a way around it if that's what main functions give us.
	char* arguments[3] = {"program_path", "arg1", NULL};

	std::vector<std::string> expected = {"program_path", "arg1"};
	
	EXPECT_CALL(cmd, run(expected));
	
	cmd.start(3, arguments);
}

// Test that our run method calls execute when there are no subcommands called
// and arguments are parsed correctly
TEST(offshoot_Command, RunMethodNoSubCommandPassing) {
	
	MockCommand cmd;
	cmd.nonMockedAddSubCommand(std::shared_ptr<MockCommand>(new MockCommand("blah")));
	
	cmd.setTCLAPExceptionHandling(false);
	
	std::vector<std::string> args = {"program_path", "-v", "Hello"};
	EXPECT_CALL(cmd, execute());
	cmd.offshoot::Command::run(args);
	ASSERT_EQ(cmd.valueArg.getValue(), "Hello");
}

// Test that the parser fails when it's supposed to when there aren't any subcommands
// called
TEST(offshoot_Command, RunMethodNoSubCommandBadParse) {
	MockCommand cmd;
	cmd.nonMockedAddSubCommand(std::shared_ptr<MockCommand>(new MockCommand("blah")));
	
	cmd.setTCLAPExceptionHandling(false);
	
	std::vector<std::string> args = {"program_path", "notBlah"};
	
	ASSERT_THROW(cmd.offshoot::Command::run(args), TCLAP::CmdLineParseException);
}

// Test that our run method calls the proper subcommand and parses the arguments
// correctly
TEST(offshoot_Command, RunMethodSubCommandPassing) {
	
	MockCommand cmd;
	auto subcmd1 = std::shared_ptr<RunnableMockCommand>(new RunnableMockCommand("foo"));
	auto subcmd2 = std::shared_ptr<RunnableMockCommand>(new RunnableMockCommand("bar"));
	cmd.nonMockedAddSubCommand(subcmd1);
	cmd.nonMockedAddSubCommand(subcmd2);

	cmd.setTCLAPExceptionHandling(false);
	std::vector<std::string> args = {"program_path", "foo", "-v", "Hello"};
	
	EXPECT_CALL(*subcmd1, execute());
	EXPECT_CALL(cmd, execute()).Times(0);
	EXPECT_CALL(*subcmd2, execute()).Times(0);
	
	cmd.offshoot::Command::run(args);
	
	ASSERT_EQ(subcmd1->valueArg.getValue(), "Hello");
}

// Test that the parser fails when it's supposed to when it uses a subcommand
TEST(offshoot_Command, RunMethodSubCommandBadParse) {
	MockCommand cmd;
	auto subcmd1 = std::shared_ptr<RunnableMockCommand>(new RunnableMockCommand("foo"));
	auto subcmd2 = std::shared_ptr<RunnableMockCommand>(new RunnableMockCommand("bar"));
	cmd.nonMockedAddSubCommand(subcmd1);
	cmd.nonMockedAddSubCommand(subcmd2);
	
	subcmd1->setTCLAPExceptionHandling(false);
	std::vector<std::string> args = {"program_path", "foo", "Hello"};
	
	ASSERT_THROW(cmd.offshoot::Command::run(args), TCLAP::CmdLineParseException);
}

// Test that the CommandOutput is correct
TEST(offshoot_CommandOutput, ) {
	struct SubCommand1 : offshoot::Command {
		TCLAP::ValueArg<std::string> arg;
		SubCommand1() : offshoot::Command("sub1", ""), arg("t", "test", "", true, "", "string", this->cmd) {}
	};
	
	struct SubCommand2 : offshoot::Command {
		TCLAP::UnlabeledValueArg<std::string> arg;
		SubCommand2() : offshoot::Command("sub2", ""), arg("test", "", true, "", "string", this->cmd) {}
	};
	
	struct MainCommand : offshoot::Command {
		MainCommand() : offshoot::Command("", "") {
			addSubCommand(std::shared_ptr<SubCommand1>(new SubCommand1()));
			addSubCommand(std::shared_ptr<SubCommand2>(new SubCommand2()));
		}
		
		offshoot::Command::CommandOutput* getOutput() {
			return this->output;
		}
	};
	
	MainCommand cmd;
	std::stringstream expected;
	expected << "Subcommands:" << std::endl << std::endl << "   not_set_yet sub1  -t <string> [--] [--version] [-h]" << std::endl << std::endl << "   not_set_yet sub2  [--] [--version] [-h] <string>" << std::endl;
	
	std::stringstream stream;
	cmd.getOutput()->printSubcommands(stream);
	ASSERT_EQ(stream.str(), expected.str());
}
