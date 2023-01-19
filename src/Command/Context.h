//
// Created by tomer on 17/01/2023.
//

#ifndef TARGIL1_CONTEXT_H
#define TARGIL1_CONTEXT_H

#include "../KNN/KNN.h"
#include "../KNN/GetNeighbors.h"

class Context {
private:
  int* k;
  KNN* knn;
  GetNeighbors* gn;
  std::string metric;
  std::vector<std::vector<double>>* toClassify;
  std::vector<std::pair<long, std::string>>* result;
public:
    Context();
    ~Context();

    int *getK() const;

    KNN *getKnn() const;

    GetNeighbors *getGn() const;

    std::vector<std::vector<double>> *getToClassify() const;

    const std::string &getMetric() const;

    std::vector<std::pair<long, std::string>> *getResult() const;

    void setK(int k);

    void setKnn();

    void setGn(DataExtractor& extractor);

    void setToClassify(std::vector<std::vector<double>> *toClassify);

    void setMetric(const std::string &metric);

    void initializeResult();

    void updateResult(int, const std::string&);

    void initializeToClassify();

    void updateToClassify(std::vector<double> v);

    void initializeGetNeighbors();

    void initializeKNN();






};


#endif //TARGIL1_CONTEXT_H
