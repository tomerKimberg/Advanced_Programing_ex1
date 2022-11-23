**program discription-**
This program computes the distance between two vectors (which are recived by the user) based on 5 diffrent distance algorithms:
1. Manhattan distance
2. Euclidean distance
3. Minkowski distance (we used to constant 2 in the calculations)
4. Chebyshev distance
5. Canberra distance

Being that all the algorithms require some shared operations, we have created a file containing vector functions that are used by most algorithms.
we have defined the following functions:
vectorSum- sum all the element of a vector.
vectorMax- return the max value of all the elements of the vector.
vectorPow- compute for every element of the vector, its value to the power of a given value.
vectorSubtraction- for every matching indexes on two vectors compute the result of subtracting one from the other.
vectorAbs- for every element of the vector update the value to be the absolute value of itself.
vectorAddition- for every matching indexes on two vectors compute the result of adding one from the other.
vectorDivision- for every matching indexes on two vectors compute the result of the divition of one from the other.

In order for these opertions to be well defined the following conditions must be met:
1. Operations on two vectors, compel that the vectors are the same size.
2. Vectors musn't be empty.
3. The input must be consisted of real numbers only.

We created a few functions to enforce those conditions, if one of the conditions is not met, an error message will be printed and the program will exit gracefully.

**compilation instructions-**
g++ -std=c++11 *.cpp
