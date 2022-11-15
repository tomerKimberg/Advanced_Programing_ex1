#include <iostream>
#include <vector>
#include <sstream>
#include "vector_functions.h"
#include "distance_algorithms.h"

/*
input: none
output: vector<double>
this function reads a line of the following format: "1.3 2 3 4 5" and creates a vector from it
*/
std::vector<double> getVectorFromInput()
{
    std::string line = "";
    std::getline(std::cin, line);
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

int main()
{
    std::vector<double> firstVector = getVectorFromInput();
    std::vector<double> secondVector = getVectorFromInput();
    if(vector_validation(firstVector, secondVector)) {
        printVector(firstVector);
        printVector(secondVector);
        printVector(vectorAddition(firstVector, secondVector));
        std::vector<double> test = vectorDivision(firstVector, secondVector);
        std::cout << "here" << std::endl;
        std::cout << Canberra_distane(firstVector, secondVector) << std::endl;
        printVector(test);
        test = vectorSubtraction(firstVector, secondVector);
        printVector(test);
        test.push_back(5);
    }
    else{
        std::cout << "the input by the user was invalid!" << std::endl;
    }
}