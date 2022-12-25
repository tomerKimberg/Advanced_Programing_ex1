//
// Created by tomer on 25/12/2022.
//

#ifndef TARGIL1_CLIENT_USER_INPUT_H
#define TARGIL1_CLIENT_USER_INPUT_H

#include <vector>
#include <string>
/**
 * split user input to 3 strings- vector, metric and k-neighbors
 * @param line user input
 * @return std::vector<std::string>
 */
std::vector<std::string> splitUserInput(std::string line);
/**
 * check if user input is valid
 * @param splitInput vector of strings, that are the user input split to 3 strings- vector,metric,k-neighbors
 * @return bool
 */
bool validUserInput(std::vector<std::string> splitInput);
/**
 * check if the given vector contains only real numbers
 * @param vector string
 * @return bool
 */
bool checkVector(std::string vector);
/**
 * check if the given metric system is suported by the program
 * @param vector string
 * @return bool
 */
bool checkMetric(std::string metric);
/**
 * check if the given k is a positive integer
 * @param vector string
 * @return bool
 */
bool checkKNeighbors(std::string KNeighbors);
#endif //TARGIL1_CLIENT_USER_INPUT_H
