#include <string>
#include <iostream>
#include <fstream>
#include <arpa/inet.h>
#include <cmath>

#define MAX_PORT_VALUE 65535
#define BAD_AF_PARAMETER "bad address for af parameter in inet_pton"

bool isIP(std::string ip){
    //buffer for destination of inet_pton
    unsigned char buf[INET_ADDRSTRLEN];
    int validIp = inet_pton(AF_INET, ip.c_str(), buf);
    if(validIp == 0){
        return false; // inet_pton returns 0 on unsuccessful conversion
    }
    if(validIp == -1){
        std::cout << BAD_AF_PARAMETER << std::endl; // keep printing because this is something that should never happen
        return false;
    }
    return true;
}
bool isPort(std::string portStr){
    int port = 0;
    try{
        port = std::stoi(portStr);
    }catch(...){
        //conversion to number failed
        return false;
    }   
    //number after conversion is out of range
    if(port <= 0 || port > MAX_PORT_VALUE){        
        return false;
    }
    //handle combined input of numbers and string because on input like 64$6, stoi will return 64
    if(port < pow(10, portStr.length() - 1)){
        return false;
    }
    return true;
}
bool isPath(std::string path){
    std::ifstream fileStream;
    fileStream.open(path);
    if(fileStream.fail()){
        return false;
    }
    fileStream.close();
    return true;
}
/**
 * this function tests various inputs for the function isIP
 * @param none
 * @return: none
*/
void testisIP(){
    std::cout <<"***tests for isIP function*****" << std::endl;
    bool result = false;
    std::string test1 = "11111111";
    result = isIP(test1);
    std::cout << "result for test1, " << test1<< " is: " << result << std::endl;
    std::string test2 = "abc";
    result = isIP(test2);
    std::cout << "result for test2, " << test2 << " is: " << result << std::endl;
    std::string test3 = "127.0.0.1";
    result = isIP(test3);
    std::cout << "result for test3, " << test3 << " is: " << result << std::endl;
    std::string test4 = "1.1.1.1";
    result = isIP(test4);
    std::cout << "result for test4, " << test4 << " is: " << result << std::endl;
    std::string test5 = "255.255.255.255";
    result = isIP(test5);
    std::cout << "result for test5, " << test5 << " is: " << result << std::endl;
    std::cout <<"***finish tests*****" << std::endl;
}
/**
 * this function tests various inputs for the function isPort
 * @param none
 * @return: none
*/
void testisPort(){
    std::cout <<"***tests for isPort function*****" << std::endl;
    bool result = false;
    std::string test1 = "-5";
    result = isPort(test1);
    std::cout << "result for test1, " << test1<< " is: " << result << std::endl;
    std::string test2 = "abc";
    result = isPort(test2);
    std::cout << "result for test2, " << test2 << " is: " << result << std::endl;
    std::string test3 = "1";
    result = isPort(test3);
    std::cout << "result for test3, " << test3 << " is: " << result << std::endl;
    std::string test4 = "65535";
    result = isPort(test4);
    std::cout << "result for test4, " << test4 << " is: " << result << std::endl;
    std::string test5 = "65536";
    result = isPort(test5);
    std::cout << "result for test5, " << test5 << " is: " << result << std::endl;
    std::string test6 = "64$6";
    result = isPort(test6);
    std::cout << "result for test6, " << test6 << " is: " << result << std::endl;
    std::cout <<"***finish tests*****" << std::endl;

}
