
#ifndef TARGIL1_CLI_H
#define TARGIL1_CLI_H
#include <vector>
#include "../Command/Command.h"
#include "../Command/Context.h"
#include "../Command/DefaultIO.h"

class CLI{
	private:
	std::vector<Command> commands;
	Context context;
	public:
	/*
	*	Constructs a CLI object with a given IO
	*	input: DefaultIO
	*	output: CLI object
	*/
	CLI(DefaultIO io);
	/*
	*	starts the CLI
	*	input: none
	*	output: none
	*/
	void start();
}

#endif //TARGIL1_CLI_H