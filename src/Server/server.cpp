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

#define SERVER_NUMBER_OF_ARGUMENTS 3
#define SERVER_ARGS_VARIABLE_PORT 2
#define SERVER_ARGS_VARIABLE_PATH 1
#define BIND_ERROR_MESSAGE "error binding given port, exiting."


/**
 * @param int argc, amount of the program arguments
 * @param char** argv - the arguments values
 * @return bool - wether the arguments are valid or not
*/
bool validArgs(int argc, char** argv);

int main(int argc, char** argv){
    //check program arguments
    if(!validArgs(argc, argv)){
        std::cout << ARGS_BAD_MESSAGE << std::endl;
        return 1;
    }
    int port = std::stoi(argv[SERVER_ARGS_VARIABLE_PORT]);
    SocketConnection server(port);
    if(server.bind() < 0){
        std::cout << BIND_ERROR_MESSAGE << std::endl;
        return 1;
    }
    bool firstConnection = false;

    if(server.listen() == 0) {
        while(true){
            SocketConnection connection(server.accept());
            if (connection.getSock() > 0) {
                firstConnection = true;
            }
            while (firstConnection) {
                std::string message = connection.receive();
                std::cout << message << std::endl;
                //message is empty only if socket was closed
                if (message.empty()) {
                    firstConnection = false;
                    connection.close();
                }
            }
        }
    }
    else{
        std::cout << "problem listening" << std::endl;
    }
        
    server.close();
    return 0;
}

bool validArgs(int argc, char** argv){
    if(SERVER_NUMBER_OF_ARGUMENTS != argc){
        std::cout << BAD_ARGUMENTS_NUMBER << std:: endl;
        return false;
    }
    if(!isPort(argv[SERVER_ARGS_VARIABLE_PORT])){
        std::cout << BAD_ARGUMENT_PORT_MESSAGE << std:: endl;
        return false;
    }
    return true;
}