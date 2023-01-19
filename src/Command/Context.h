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
  std::vector<int,std::string>* result;
public:
    Context();
    ~Context();

    int *getK() const;

    KNN *getKnn() const;

    GetNeighbors *getGn() const;

    const std::string &getMetric() const;

    std::vector<int, std::string> *getResult() const;

    void setK(int k);

    void setKnn();

    void setGn(DataExtractor& extractor);

    void setMetric(const std::string &metric);

    void setResult(std::vector<int, std::string> *result);
};


#endif //TARGIL1_CONTEXT_H
