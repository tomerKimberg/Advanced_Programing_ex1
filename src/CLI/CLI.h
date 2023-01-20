
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
    void createMenu(){
        this->menu += "Welcome to the KNN Classifier Server. Please choose an option:\n";
        for(Command* c : this->commands){
            this->menu += c->getDescription();
        }
        this->menu += "8. exit\n";
    }
    bool validateInstuction(std::string instruction){
        if(std::isdigit(instruction[0]) && instruction.size() == 1){
            int temp = std::stoi(instruction);
            if(1<=temp && temp <=5 || temp == 8){
                return true;
            }
        }
        return false;

    }
    bool goToCommand(int commandNum){
        if(commandNum == 8){
            return false;
        }
        else{
            this->commands.at(commandNum-1)->execute();
        }
        return true;
    }

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

    void start();
}
;

#endif //TARGIL1_CLI_H