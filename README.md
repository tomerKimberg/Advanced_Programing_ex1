**program discription-**
This program computes the distance between two vectors (which are recived by the user) based on 5 diffrent distance algorithems:
1. Manhattan distance
2. Euclidean distance
3. Minkowski distance
4. Chebyshev distance
5. Canberra_distance

Being that all the algorithems require some shared operations, we have created a file containing vector functions that are used by most algorithems.
we have defined the following vector function-
vectorSum- sum all the element of a vector.
vectorMax- return the max value of all the elements of the vector.
vectorPow- compute for every element of the vector, its value to the power of a givven value.
vectorSubtraction- for every matching indexes on two vectors compute the result of subtracting one from the other.
vectorAbs- for every element of the vector update the value to be the absolute value of itself.
vectorAddition- for every matching indexes on two vectors compute the result of adding one from the other.
vectorDivision- for every matching indexes on two vectors compute the result of the divition of one from the other.

In-order for these oppertions to be well defined the following conditions must be met-
1. opperations on two vector, compel that the vectors are the same size.
2. vectors musn't be empty
3. must contain only real number.

for that we have created functions to determine that these condition are met,
if not, the program we print an error message and terminate gracfully.

**compilation instructions-**
g++ -std=c++11 *.cpp
