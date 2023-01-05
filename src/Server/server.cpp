#include <sstream>
#include "../DistanceCalculator/vector_functions.h"
#include "../ValidationFuncs/user_input.h"
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
#define SERVER_MESSAGE_INDEX_VECTOR 0
#define SERVER_MESSAGE_INDEX_METRIC 1
#define SERVER_MESSAGE_INDEX_K 2
#define BIND_ERROR_MESSAGE "error binding given port, exiting."


/**
 * @param int argc, amount of the program arguments
 * @param char** argv - the arguments values
 * @return bool - wether the arguments are valid or not
*/
bool validArgs(int argc, char** argv);
/**
 * function runs the server, handles connection changes and recieving and sending data
 * @param SocketConnection - the connetion to the server
 * @param std::map<std::vector<double>, std::vector<std::string>> - the neighbors object
 * @return none 
*/
void runServer(SocketConnection server, std::map<std::vector<double>, std::vector<std::string>> neighbors);
/**
 * create a new vector, if input is invalid set valid_input to false
 * @param std::string line
 * @param bool& valid_input
 * @return std::vector<double>, creates a new vector from the string
 */
std::vector<double> vectorFromString(std::string line, bool& valid_input);


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
    if(server.listen() == 0) {
        //create an DataExtractor pointer using FileExtractor
        FileExtractor fileExtractor(argv[SERVER_ARGS_VARIABLE_PATH]);
        DataExtractor* extractor = &fileExtractor;
        //create neighbors from the data of our file
        GetNeighbors get(extractor);       
        std::map<std::vector<double>, std::vector<std::string>> neighbors = get.getNeighborsInMap();
        runServer(server, neighbors);
    }
    else{
        std::cout << "problem listening" << std::endl;
    }        
    server.closeSocket();
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
    if(!isPath(argv[SERVER_ARGS_VARIABLE_PATH])){
        std::cout << BAD_ARGUMENT_PATH_MESSAGE << std:: endl;
        return false;
    }
    return true;
}
std::vector<double> vectorFromString(std::string line, bool& valid_input)
{
    std::stringstream stringstream;
    stringstream.str(line);
    std::string number;
    std::vector<double> inputVector;
    while(stringstream >> number && valid_input)
    {
        if (checkRealNumber(number)){
            inputVector.push_back(std::stod(number));
        }
        else{
            valid_input = false;
        }
    }
    return inputVector;   
}

void runServer(SocketConnection server, std::map<std::vector<double>, std::vector<std::string>> neighbors){
    bool acceptedConnection = false;
    while(true){
        SocketConnection connection(server.accept());
        if (connection.getSock() > 0) {
            acceptedConnection = true;
        }
        while (acceptedConnection) {
            std::string message = connection.receive();
            std::string response = "";
            //message is empty only if socket was closed
            if (message.empty()){
                acceptedConnection = false;
                connection.closeSocket();
                break;
            }
            std::vector<std::string> splittedMessage = splitUserInput(message);
            if(!validUserInput(splittedMessage)){
                response = INVALID_INPUT_ERROR_MESSAGE;
            }else{
                bool validVector = true;
                std::vector<double> inputVector = vectorFromString(splittedMessage[SERVER_MESSAGE_INDEX_VECTOR], validVector);
                if(!validVector){
                    response = INVALID_INPUT_ERROR_MESSAGE;
                    acceptedConnection = false;
                    break;
                }
                int neighborsNum = std::stoi(splittedMessage[SERVER_MESSAGE_INDEX_K]);
                //create a KNN object, and get the classification of the input vector
                KNN knn(neighbors, splittedMessage[SERVER_MESSAGE_INDEX_METRIC], neighborsNum);
                response = knn.getClassification(inputVector);
            }
            connection.send(response);
        }
    }
}