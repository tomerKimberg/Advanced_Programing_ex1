#include <sstream>
#include <arpa/inet.h>
#include "../DistanceCalculator/vector_functions.h"
#include "../ValidationFuncs/vector_validation.h"
#include "../ValidationFuncs/arguments_validation.h"
#include "../DistanceCalculator/distance_algorithms.h"
#include "..//DistanceCalculator/headerDistanceCalculators.h"
#include "..//KNN/KNN.h"
#include "..//KNN/GetNeighbors.h"
#include "../CommunicationProtocol.h"
#include "../Extractors/DataExtractor.h"
#include "..//Extractors/FileExtractor.h"
#include "..//SocketConnection/SocketConnection.h"
#include "../ValidationFuncs/user_input.h"

#define CLIENT_NUMBER_OF_ARGUMENTS 3
#define CLIENT_ARGS_VARIABLE_PORT 2
#define CLIENT_ARGS_VARIABLE_IP 1
//menu options
#define CLIENT_EXIT_MENU_OPTION 8
#define UPLOAD_FILES_OPTION 1
#define CHANGE_K_METRIC_OPTION 2
#define CLASSIFY_OPTION 3
#define RECEIVE_RESULTS_OPTION 4
#define RECEIVE_RESULTS_TO_FILE_OPTION 5
//client only messages
#define INVALID_INPUT_ERROR_MESSAGE "invalid input"
#define RESULT_STANDARD_OUTPUT_POSTFIX "Done."
//debug
#define CLIENT_DEBUG 0

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
/**
 * @param int the option to be executed from the menu
 * @param SocketConnection the connection to the server
 * executes the relevant menu function - only executes if menuOption is corresponding to a valid *defined* menu option
*/
void executeMenuOption(int menuOption, SocketConnection server);
void run(SocketConnection server);
//menu options
/**
 * @param SocketConnection the connection to the server
 * upload two files, train file and test file to the server via socket
*/
void uploadFiles(SocketConnection server);
/**
 * @param SocketConnection the connection to the server
 * receive the current k and metric, and update them if necessary
*/
void updateKAndMetric(SocketConnection server);

/**
 * @param SocketConnection the connection to the server
 * print the message that the server sends after classification and responds with received message
*/
void handleClassify(SocketConnection server);
/**
 * @param SocketConnection the connection to the server
 * @param std::istream the stream that the response will be written to.
 * read a response from server and send it to the stream
*/
void writeServerResultsToStream(SocketConnection server, std::ostream& stream);

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
        std::string response = server.read();
        if(INVALID_MESSAGE_MENU_OPTION == response){
            server.send(COMMUNICATION_MESSAGE_RECEIVED); 
            continue;
        }
        int menuOption = 0;
        try{
            menuOption = std::stoi(response);
        }catch(...){
            std::cout << ERROR_MESSAGE_SERVER_UNEXPECTED_RESPONSE;
            continue;
        }
        if(CLIENT_EXIT_MENU_OPTION == menuOption){
            break;
        }
        executeMenuOption(menuOption, server);
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
    std::string menu = server.read();
    std::cout << menu;
}
void sendInputToServer(SocketConnection server){
    std::string userInput;        
    getline(std::cin, userInput);
    server.send(userInput);
}
void executeMenuOption(int menuOption, SocketConnection server){  
    //received menu
    server.send(COMMUNICATION_MESSAGE_RECEIVED); 
    switch(menuOption){
        case UPLOAD_FILES_OPTION:
            uploadFiles(server);
            break;
        case CHANGE_K_METRIC_OPTION:
            updateKAndMetric(server);
            break;
        case CLASSIFY_OPTION:
            handleClassify(server);
            break;
        case RECEIVE_RESULTS_OPTION:
            writeServerResultsToStream(server, std::cout);
            server.send(COMMUNICATION_MESSAGE_RECEIVED); 
            std::cout << RESULT_STANDARD_OUTPUT_POSTFIX << std::endl;
            break;
        case RECEIVE_RESULTS_TO_FILE_OPTION:
            std::cout << "option 5" << std::endl;
            break;
    }
}
void uploadFiles(SocketConnection server){
    const int FILES_TO_UPLOAD = 2;
    //read first message from server
    std::string message = server.read();
    std::cout << message;
    for(int i = 0; i < FILES_TO_UPLOAD; i++){        
        std::string path = ""; 
        getline(std::cin, path);
        if(!isPath(path)){
            server.send(INVALID_MESSAGE_PATH);
            if(CLIENT_DEBUG){
                std::cout << INVALID_INPUT_ERROR_MESSAGE << std::endl;
            }            
            return;
        }
        FileExtractor fileExtractor(path);
        std::string data = "";
        while (fileExtractor.hasNext()) {
            data += fileExtractor.getData();
            data += DELIMETER_CHAR;//and \n for StringExtractor
        }
        if(CLIENT_DEBUG){
            std::cout << "file to send to server:" << std::endl;
            std::cout << data << std::endl;
        }
        server.send(data);
        message = server.read();
        std::cout << message;
    }
    //read recieved upload message
    server.send(COMMUNICATION_MESSAGE_RECEIVED); 
}
void updateKAndMetric(SocketConnection server){
    //receive the current k and metric
    std::string message = server.read();
    std::cout << message;
    std::string KAndMetric = K_METRIC_DONT_CHANGE; 
    getline(std::cin, KAndMetric);
    //send communication received to buffer between message and menu
    server.send(KAndMetric);
    message = server.read();
    //if the message isn't an ok message, we need to print it
    if(COMMUNICATION_MESSAGE_RECEIVED != message){
        std::cout << message;
    }
    server.send(COMMUNICATION_MESSAGE_RECEIVED); 
}
void handleClassify(SocketConnection server){
    //read first message from server
    std::string message = server.read();
    std::cout << message;
    server.send(COMMUNICATION_MESSAGE_RECEIVED); 
}
void writeServerResultsToStream(SocketConnection server, std::ostream& stream){
    stream << server.read();
}
