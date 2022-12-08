//
// Created by tomer on 07/12/2022.
//

#ifndef TARGIL1_KNN_H
#define TARGIL1_KNN_H
#include "headerDistanceCalculators.h"
#include <map>
#include "factoryDistanceCalculator.h"
class KNN {
private:
    int k;
    std::string metric;
    distanceCalculator* distanceCalculatorMetric;
    std::map<std::vector<double>, std::vector<std::string>> neighbors;
    factoryDistanceCalculator FDC;
    // add container attribute to store distances
public:
    KNN(std::map<std::vector<double>, std::vector<std::string>> neighbors,
        std::string metric, int k);
    ~KNN();

    void setNeighbors( std::map<std::vector<double>, std::vector<std::string>> neighbors);
    void setK(int k);
    //make sure to delete former distance calculator
    void setMetric(std::string metric);
    int getK();
    std::map<std::vector<double>, std::vector<std::string>> getNeighbors();

    std::string getClassification(std::vector<double>);
    //might change based on design
    std::vector<std::vector<double>> getKNearestNeighbors(std::vector<double>);

};


#endif //TARGIL1_KNN_H
