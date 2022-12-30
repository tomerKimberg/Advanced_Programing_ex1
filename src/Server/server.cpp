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
    SocketConnection server(12345);
    server.bind();
    bool firstConnection = false;

    if(server.listen() == 0) {
        SocketConnection connection(server.accept());
        if (connection.getSock() > 0) {
            firstConnection = true;
        }


        while (firstConnection) {
            std::string message = connection.receive();
            std::cout << message << std::endl;
            if (message == "-1") {
                firstConnection = false;
                connection.close();
            }
        }
    }
    else{
        std::cout << "problem listening" << std::endl;
    }
    server.close();
}