#include "FactoryDistanceCalculator.h"


DistanceCalculator* FactoryDistanceCalculator::createDistanceCalculator(std::string metric){

    if(metric == "CAN"){
        return new CanberraDistanceCalculator;
    } else if(metric == "CHB"){
        return new ChebyshevDistanceCalculator;
    } else if(metric == "AUC"){
        return new EuclideanDistanceCalculator;
    } else if(metric == "MAN"){
        return new ManhattanDistanceCalculator;
    } else if(metric == "MIN"){
        return new MinkowskiDistanceCalculator;
    }
    //if non of the strings match, return nullptr
    return nullptr;

}