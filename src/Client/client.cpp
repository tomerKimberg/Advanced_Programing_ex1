#include <sstream>
#include <arpa/inet.h>
#include "../DistanceCalculator/vector_functions.h"
#include "../ValidationFuncs/vector_validation.h"
#include "../ValidationFuncs/arguments_validation.h"
#include "../DistanceCalculator/distance_algorithms.h"
#include "..//DistanceCalculator/headerDistanceCalculators.h"
#include "..//KNN/KNN.h"
#include "..//KNN/GetNeighbors.h"
#include "../Extractors/DataExtractor.h"
#include "..//Extractors/FileExtractor.h"
#include "..//SocketConnection/SocketConnection.h"
#include "../ValidationFuncs/user_input.h"

#define CLIENT_NUMBER_OF_ARGUMENTS 3
#define CLIENT_ARGS_VARIABLE_PORT 2
#define CLIENT_ARGS_VARIABLE_IP 1

/**
 * @param int argc, amount of the program arguments
 * @param char** argv - the arguments values
 * @return bool - wether the arguments are valid or not
*/
bool validArgs(int argc, char** argv);
void run(SocketConnection client);

int main(int argc, char** argv){
    //check program arguments
    if(!validArgs(argc, argv)){
        std::cout << ARGS_BAD_MESSAGE << std::endl;
        return 1;
    }

    int port = std::stoi(argv[CLIENT_ARGS_VARIABLE_PORT]);
    struct sockaddr_in sa;
    unsigned long int ip = 0;
    inet_pton(AF_INET, argv[CLIENT_ARGS_VARIABLE_IP], &ip);
    SocketConnection client(port, ip);
    run(client);
    return 0;
}

void run(SocketConnection client) {
    bool connection = false;
    if(client.connect() == 0){
        connection = true;
    }

    while(connection){
        std::string userInput;
        getline(std::cin, userInput);
        //if input is -1, close client
        if(userInput == "-1"){
            break;
        }
        if(validUserInput(splitUserInput(userInput))) {
            if(client.send(userInput)) {
                std::string response = client.read();
                std::cout << response << std::endl;
            }
                //there was an error sending to the server, probably connection lost
            else {
                connection = false;
            }
        }
        else{
            std::cout << INVALID_INPUT_ERROR_MESSAGE << std::endl;
        }

    }
    client.closeSocket();
}
bool validArgs(int argc, char** argv){
    if(CLIENT_NUMBER_OF_ARGUMENTS != argc){
        std::cout << BAD_ARGUMENTS_NUMBER << std:: endl;
        return false;
    }
    if(!isIP(argv[CLIENT_ARGS_VARIABLE_IP])){
        std::cout << BAD_ARGUMENT_IP_MESSAGE << std:: endl;
        return false;
    }
    if(!isPort(argv[CLIENT_ARGS_VARIABLE_PORT])){
        std::cout << BAD_ARGUMENT_PORT_MESSAGE << std:: endl;
        return false;
    }
    return true;
}
