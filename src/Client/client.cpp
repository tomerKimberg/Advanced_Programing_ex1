#include "../distanceCalculator/vector_functions.h"
#include "../validationFuncs/vector_validation.h"
#include "../distanceCalculator/distance_algorithms.h"
#include "..//distanceCalculator/headerDistanceCalculators.h"
#include "..//KNN/KNN.h"
#include "..//KNN/GetNeighbors.h"
#include "../Extractors/DataExtractor.h"
#include "..//Extractors/FileExtractor.h"
#include "..//SocketConnection/SocketConnection.h"


int main(){
    SocketConnection client(12345);
    bool connection = false;
    if(client.connect() == 0){
        connection = true;
    }

    while(connection){
        std::string userInput;
        std::cin >> userInput;
        if(client.send(userInput)){
            std::cout <<"message was sent" <<std::endl;
            if(userInput == "-1"){
                connection = false;
            }
        }
        else{
            connection = false;
        }

    }
    client.close();
}