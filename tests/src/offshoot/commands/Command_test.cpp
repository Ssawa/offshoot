#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "offshoot/commands/Command.h"


TEST(offshoot_Command, StartMethod) {
	
	class MockCommand : public offshoot::Command {
	public:
		MOCK_METHOD1(run, int(std::vector<std::string>& args));
	};
	
	auto cmd = MockCommand();
	
	// This will throw a warning because we're using C style strings which is annoying
    // but I'm not sure if there's a way around it if that's what main functions give us.
	char* arguments[3] = {"as", "add", "dd"};
	cmd.start(3, arguments);
}
