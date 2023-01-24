#include "Command5.h"

#define MINIMAL_PORT_NUMBER 1025
#define MAXIMAL_PORT_NUMBER 65536
#define SUBSTRACTION_MODIFIER 1
//debug
#define DEBUG_COMMAND_5 0

Command5::Command5(const std::string &description, DefaultIO *io, Context *context) : Command(description, io,
                                                                                              context) {}
void Command5::execute(){
    if(!this->checkRequirement()){
        this->io->write(ERROR_MESSAGE_REQUIRED_DATA);
        this->io->read();
        return;
    }
    if(!this->checkResult()){
        this->io->write(ERROR_MESSAGE_REQUIRED_CLASSIFICATION);
        this->io->read();
        return;
    }
    this->io->write(COMMUNICATION_MESSAGE_SERVER_READY_FOR_PATH);
    //results can be sent
    std::string message = this->io->read();
    if(INVALID_MESSAGE_PATH == message){
        //we can just return because next message will be the menu from the server
        return;
    }
    bool portValid = false;
    int portNum = -1;
    SocketConnection resultsConnection(portNum);
    srand(time(NULL));
    do{
        portNum = rand() % (MAXIMAL_PORT_NUMBER - MINIMAL_PORT_NUMBER + SUBSTRACTION_MODIFIER) + MINIMAL_PORT_NUMBER;

        SocketConnection newConnection(portNum);
        if(newConnection.bind() >= 0 && 0 == newConnection.listen()){
            portValid = true;
            resultsConnection = newConnection;
        }
    }while(!portValid);
    this->io->write(std::to_string(portNum));
    //read received message from server
    this->io->read();
    sendResultsToClient(resultsConnection);    
}
//private functions
bool Command5::checkRequirement(){
    if(this->context->getGn()){
        return true;
    }
    return false;
}   
bool Command5::checkResult(){
    if(this->context->getResult()) {
        if (!this->context->getResult()->empty()) {
            return true;
        }
    }
    return false;
}
std::string Command5::sendResults(){
    std::string result;
    for(std::pair<int,std::string> temp : *this->context->getResult()){
        result += std::to_string(temp.first);
        result += '\t';
        result += temp.second;
        result += '\n';
    }
    return result;
}                                                                                           
void Command5::sendResultsToClient(SocketConnection resultsConnection){
    SocketConnection connection(resultsConnection.accept());
    std::string results = this->sendResults();
    if(DEBUG_COMMAND_5){
        std::cout << results << std::endl;
    }
    connection.send(results);
    //read received message from server
    connection.read();
    connection.closeSocket();
    resultsConnection.closeSocket();
}