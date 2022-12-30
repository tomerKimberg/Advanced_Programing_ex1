#include <sstream>
#include "../DistanceCalculator/vector_functions.h"
#include "../ValidationFuncs/vector_validation.h"
#include "../DistanceCalculator/distance_algorithms.h"
#include "..//DistanceCalculator/headerDistanceCalculators.h"
#include "..//KNN/KNN.h"
#include "..//KNN/GetNeighbors.h"
#include "../Extractors/DataExtractor.h"
#include "..//Extractors/FileExtractor.h"
#include "..//SocketConnection/SocketConnection.h"
#define NUMBER_OF_VECTORS 1

/**
 * create a new vector, if input is invalid set valid_input to false
 * @param std::string line
 * @param bool& valid_input
 * @return std::vector<double>, creates a new vector from the string
 */
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



int main(){
    SocketConnection client(12345);
    bool connection = false;
    if(client.connect() == 0){
        connection = true;
    }

    while(connection){
        //get a vector from the user
        std::string line = "";
        bool valid_input = true;
        std::getline(std::cin, line);
        //check validation of input
        if(client.send(line)){
            std::cout << "message was sent" << std::endl;
            if(line == "-1"){
                connection = false;
            }
        }
        else{
            connection = false;
        }

    }
    client.close();
}