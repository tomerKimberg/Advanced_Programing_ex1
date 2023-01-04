#include <string>
#include <iostream>
#include <arpa/inet.h>

#define BAD_AF_PARAMETER "bad address for af parameter in inet_pton"

bool isIP(std::string ip){
    //buffer for destination of inet_pton
    unsigned char buf[sizeof(struct sockaddr)];
    int validIp = inet_pton(AF_INET, ip.c_str(), buf);
    if(validIp == 0){
        return false; // inet_pton returns 0 on unsuccessful conversion
    }
    if(validIp == -1){
        std::cout << BAD_AF_PARAMETER << std::endl;
        return false;
    }
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
    result = isIP("abc");
    std::cout << "result for test2, " << test2 << " is: " << result << std::endl;
    std::string test3 = "127.0.0.1";
    result = isIP("127.0.0.1");
    std::cout << "result for test3, " << test3 << " is: " << result << std::endl;
    std::string test4 = "1.1.1.1";
    result = isIP("1.1.1.1");
    std::cout << "result for test4, " << test4 << " is: " << result << std::endl;
    std::string test5 = "255.255.255.255";
    result = isIP("255.255.255.255");
    std::cout << "result for test5, " << test5 << " is: " << result << std::endl;
    std::cout <<"***finish tests*****" << std::endl;
}