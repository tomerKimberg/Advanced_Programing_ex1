
#ifndef TARGIL1_CLI_H
#define TARGIL1_CLI_H
#include <vector>
#include "../Command/Command.h"
#include "../Command/Context.h"
#include "../Command/DefaultIO.h"

class CLI{
	private:
    DefaultIO* defaultIo;
	std::vector<Command*> commands;
	Context context;
    std::string menu;
    /**
     * create the menu
     */
    void createMenu();
    /**
     * check if instruction given in valid
     * @param instruction string
     * @return true or false
     */
    bool validateInstuction(std::string instruction);
    /**
     * execute the command by the given instruction
     * @param commandNum int
     * @return true if the instruction was not to close communication
     */
    bool goToCommand(int commandNum);

	public:
	/*
	*	Constructs a CLI object with a given IO
	*	input: DefaultIO
	*	output: CLI object
	*/
	CLI(DefaultIO* io);
	/*
	*	starts the CLI
	*	input: none
	*	output: none
	*/
     ~CLI();
    /**
     * run the CLI
     */
    void start();
}
;

#endif //TARGIL1_CLI_H