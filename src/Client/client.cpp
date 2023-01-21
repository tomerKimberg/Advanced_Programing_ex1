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
/**
 * @param SocketConnection - the connection that the menu will come from
 *   recieves data using SocketConnection and prints it on std::cout
*/
void printMenu(SocketConnection server);
/**
 * @param SocketConnection - the connection that the input will be sent through
 * reads input from std::cin ands sends it through the socket
 */
void sendInputToServer(SocketConnection server);
void run(SocketConnection server);

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
    SocketConnection server(port, ip);
    run(server);
    return 0;
}

void run(SocketConnection server) {
    bool connection = false;
    if(server.connect() == 0){
        connection = true;
    }

    while(connection){
        printMenu(server);
        sendInputToServer(server);
    }
    server.closeSocket();
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
void printMenu(SocketConnection server){
    std::cout << server.receive() << std::endl;
}
void sendInputToServer(SocketConnection server){
    std::string userInput;        
    getline(std::cin, userInput);
    server.send(userInput);
}
