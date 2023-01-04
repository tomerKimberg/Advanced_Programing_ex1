#ifndef TARGIL1_ARGUMENTS_VALIDATION_H
#define TARGIL1_ARGUMENTS_VALIDATION_H
#define BAD_ARGUMENTS_NUMBER "Wrong amount of arguments were passed to the program, exiting."
#define BAD_ARGUMENT_PORT_MESSAGE "Bad port given to the program, exiting."
#define BAD_ARGUMENT_IP_MESSAGE "Bad ip given to the program, exiting."
#define ARGS_BAD_MESSAGE "Bad arguments, exiting."
#include <string>
/**
 * This function tries to convert the given string to ipv4 address and returns a boolean value according to the result
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