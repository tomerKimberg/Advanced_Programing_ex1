
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