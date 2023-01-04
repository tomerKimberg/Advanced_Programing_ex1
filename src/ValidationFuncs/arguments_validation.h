#ifndef TARGIL1_ARGUMENTS_VALIDATION_H
#define TARGIL1_ARGUMENTS_VALIDATION_H
#include <string>
/**
 * This function tries to convert the given string and returns a boolean value according to the result
 * @param std::string ip the ip we want to convert
 * @return bool
*/
bool isIP(std::string ip);
/**
 * This function tries to convert the given string to port number and returns a boolean value according to the result
 * @param std::string port the port we want to convert
 * @return bool
*/
bool isPort(std::string port);
#endif //TARGIL1_ARGUMENTS_VALIDATION_H