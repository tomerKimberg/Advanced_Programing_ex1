//
// Created by tomer on 25/12/2022.
//

#include <sstream>
#include "client_user_input.h"
#include "vector_validation.h"

std::vector<std::string> splitUserInput(std::string line){
    std::vector<std::string> res;
    unsigned int lineLen = line.length();
    std::string kNeighbors;
    /*
     * get input only with spaces between vector to metric and metric to k
     */
    int index;
    for(int times = 0 ; times < 2 ; times++) {
        index = line.find_last_of(" ");
        if (index < 0) {
            return res;
        }
        kNeighbors = line.std::string::substr(index + 1, lineLen - index );
        lineLen = index;
        line = line.std::string::substr(0, lineLen);
        res.insert(res.begin(), kNeighbors);
    }
    kNeighbors = line.std::string::substr(0, index);
    res.insert(res.begin(), kNeighbors);

    /*
     * get input without spaces but with the right format vector_metric_k
     */
    //int i, j;
    //j = lineLen - 1;
    //i = j;
    //for(; i >= 0 ; i--){
    //    std::string temp = "";
    //    temp += line.at(i);
    //    if(isdigit(temp.at(0))){
    //        kNeighbors.insert(0,temp);
    //    }
    //    else{
    //        if(temp == " "){
    //            i--;
    //        }
    //        break;
    //    }
    //}
    //res.insert(res.begin(), kNeighbors);
    //kNeighbors = "";
    //j = i;
    //for(; i >= 0 ; i--){
    //    std::string temp = "";
    //    temp += line.at(i);
    //    if(std::isalpha(temp.at(0))){
    //        kNeighbors.insert(0,temp);
    //    }
    //    else{
//
    //        break;
    //    }
    //}
    //res.insert(res.begin(), kNeighbors);
//
    //kNeighbors = line.std::string::substr(0, i + 1);
    //res.insert(res.begin(), kNeighbors);
    return res;

}

bool validUserInput(std::vector<std::string> splitInput){
    if(splitInput.size() == 3) {
        return checkVector(splitInput.at(0))
               && checkMetric(splitInput.at(1))
               && checkKNeighbors(splitInput.at(2));
    }
    else{
        return false;
    }

}

bool checkVector(std::string vector){
    std::stringstream stringstream;
    stringstream.str(vector);
    std::string number;

    while(stringstream >> number)
    {
        if (checkRealNumber(number)){
            continue;
        }
        else{
            return false;

        }
    }
    return true;
}
bool checkMetric(std::string metric){
    if(
        metric == "AUC"
     || metric == "MAN"
     || metric == "CHB"
     || metric == "CAN"
     || metric == "MIN"
    ){ return true;}
    else{
        return false;
    }

}
bool checkKNeighbors(std::string KNeighbors){
    for(char temp : KNeighbors){
        if(!std::isdigit(temp)){
            return false;
        }
    }
    return true;
}