#include "factoryDistanceCalculator.h"


distanceCalculator* factoryDistanceCalculator::createDistanceCalculator(std::string metric){
    //temp implementation only to test code
    return new ChebyshevDistanceCalculator;

}