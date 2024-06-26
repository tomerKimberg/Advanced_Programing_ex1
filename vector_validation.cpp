
#include <vector>
#include <string>
#include <regex>
#include "vector_validation.h"
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
 * check if a string is a real number
 * @param string
 * @return true- this is a real number, else returns false
 */
bool checkRealNumber(std::string string){
    bool pointFlag = false;
    bool signFlag = false;
    int stringLen = string.length();
    // '.' can't show up on the first or last char.
    if(string.at(0) == '.' || string.at(stringLen-1) == '.'){
        return false;
    }
    for(int i = 0; i < stringLen ; i++){
        if(std::isdigit(string.at(i))){
            continue;
        }
        //being that '.' is not the first char, check the char before is digit
        if(string.at(i) == '.' && !pointFlag && isdigit(string.at(i-1))){
            pointFlag = true;
            continue;
        }
        //'-' can only show up once, and on the start of the string
        if(string.at(i) == '-'  && !signFlag && i == 0){
            signFlag = true;
            continue;
        }
        return false;
    }
    return true;
}
/**
 * make sure the vectors are at same length and are not empty
 * @param v1
 * @param v2
 * @return true if vectors are valid, else false
 */
bool vector_validation(const std::vector<double>& v1,  const std::vector<double>& v2){
    if(v1.size() == v2.size() && !v1.empty()){
        return true;
    }
    return false;

}