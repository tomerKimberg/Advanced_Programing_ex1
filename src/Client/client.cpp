#include <sstream>
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


void run(SocketConnection client);

int main(){
    SocketConnection client(12345);
    run(client);
}

void run(SocketConnection client) {
    bool connection = false;
    if(client.connect() == 0){
        connection = true;
    }

    while(connection){
        std::string userInput;
        getline(std::cin, userInput);
        if(validUserInput(splitUserInput(userInput)) || userInput == "-1") {
            if (client.send(userInput)) {
                //successfully sent close signal to server
                if(userInput == "-1"){
                    break;

                }
                //add code to receive and print result from server
                std::cout << "message was sent" << std::endl;
            }
                //there was an error sending to the server, probably connection lost
            else {
                connection = false;
            }
        }
        else{
            std::cout << "input invalid" << std::endl;
        }

    }
    client.close();

}
