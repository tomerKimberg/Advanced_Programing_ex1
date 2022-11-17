#include <iostream>
#include <vector>
#include <sstream>
#include <regex>
#include "vector_functions.h"
#include "distance_algorithms.h"
#define number_of_vectors 2
#define BAD_INPUT_MESSAGE "You entered an invalid input, please try to run the program again."

/**
 *
 * @param std::string line
 * @return bool, true if the string is a valid vector string or false if it's not.
 */
bool input_valid(std::string line)
{
    const std::regex input_regex("^(?:\\s|\\d|(?:\\d\\.\\d)|(?:\\-\\d)|(?:\\-\\d.\\d))+$");
    return std::regex_match(line, input_regex);
}
/**
 *
 * @param std::string line
 * @return std::vector<double>, creates a new vector from the string
 */
std::vector<double> vectorFromString(std::string line)
{
    std::stringstream stringStream;
    stringStream.str(line);
    double inputValue = 0;
    std::vector<double> inputVector;
    while(stringStream >> inputValue)
    {
        inputVector.push_back(inputValue);
    }
    return inputVector;   
}
/**
 * make sure the vectors are at same length and are not empty
 * @param v1
 * @param v2
 * @return true if vectors are valid, else false
 */
bool vector_validation(const std::vector<double>& v1,  const std::vector<double>& v2){
    if(v1.capacity() == v2.capacity() && !v1.empty()){
        return true;
    }
    return false;

}
/*
input: vector<double>
output: none
this function prints the vector with spaces between the values
*/
void printVector(const std::vector<double> vectorToPrint)
{
    for (double d: vectorToPrint)
    {
        std::cout << d << " ";
    }
    std::cout << std::endl;
}
/**
 * takes two lines of input, creates vectors from them and prints the distance between the vectors in 5 different ways
 */
void measureDistance(){
    std::string line = "";
    std::vector<double> inputVectors[2];
    for(int i = 0; i < number_of_vectors; i++){
        std::getline(std::cin, line);
        if (!input_valid(line)){
            std::cout << BAD_INPUT_MESSAGE << std::endl;
            return;
        }
        inputVectors[i] = vectorFromString(line);
    }
    printVector(inputVectors[0]);
    printVector(inputVectors[1]);
    printVector(vectorAddition(inputVectors[0], inputVectors[1]));
    std::vector<double> test = vectorDivision(firstVector, secondVector);
    std::cout << "here" << std::endl;
    std::cout << Canberra_distance(firstVector, secondVector) << std::endl;
    printVector(test);
    test = vectorSubtraction(firstVector, secondVector);
    printVector(test);
    test.push_back(5);
}

int main()
{
    measureDistance();
}