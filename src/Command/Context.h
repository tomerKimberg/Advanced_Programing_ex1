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
  GetNeigbors* ng;
  std::string* metric;
  std::vector<int,std::string>* result;

};


#endif //TARGIL1_CONTEXT_H
