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
  std::vector<std::pair<int, std::string>>* result;
public:
    Context();
    ~Context();
    /**
     * getter for int* k
     * @return int*
     */
    int *getK() const;
    /**
     * getter for KNN* knn
     * @return KNN*
     */
    KNN *getKnn() const;
    /**
     * getter for GetNeighbors* gn
     * @return GetNeighbors*
     */
    GetNeighbors *getGn() const;
    /**
     * getter for vectors to classify
     * @return std::vector<std::vector<double>>*
     */
    std::vector<std::vector<double>> *getToClassify() const;
    /**
     * getter for the metric string
     * @return std::String&
     */
    const std::string &getMetric() const;
    /**
     * getter for the rersults
     * @return std::vector<std::pair<int, std::string>>*
     */
    std::vector<std::pair<int, std::string>> *getResult() const;
    /**
     * setter for k
     * @param k int
     */
    void setK(int k);
    /**
     * setter for knn
     */
    void setKnn();
    /**
     * setter for gn
     * @param extractor DataExtractor&
     */
    void setGn(DataExtractor& extractor);
    /**
     * setter for toClassify
     * @param toClassify std::vector<std::vector<double>>*
     */
    void setToClassify(std::vector<std::vector<double>> *toClassify);
    /**
     * setter for metriuc
     * @param metric std::string
     */
    void setMetric(const std::string &metric);
    /**
     * initialize the results
     */
    void initializeResult();
    /**
     * update the results
     */
    void updateResult(int, const std::string&);
    /**
     * initialize the toClassify
     */
    void initializeToClassify();
    /**
     * update the toClassify
     * @param v
     */
    void updateToClassify(std::vector<double> v);
    /**
     * initialize the gn
     */
    void initializeGetNeighbors();
    /**
     * initialize the knn
     */
    void initializeKNN();






};


#endif //TARGIL1_CONTEXT_H
