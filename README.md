
# **Program description**

In this repository we create a client and a server which communicate between them to get classifications of vectors. The client sends the train and test data to the server, customises the K and metric and runs the classification. The server can return the answers to the screen or to a file, depending on the client's request. The server instructs the client in case of invalid input or any other error.
### What is KNN?
KNN is an artificial intelligence algorithm used to classify a given vector.
KNN recieves a dataset of vectors and classfications, and an unclassified vector.
KNN finds the closes K vectors to the given vector, and returns the most common classification among those closest "neighbors".

### How is the distance measured?

Our program offers 5 different distance algorithms for the user to choose from:
1. Manhattan distance
2. Euclidean distance
3. Minkowski distance (we used 2 as the P constant)
4. Chebyshev distance
5. Canberra distance

like in the first exercise, most of those algorithms share some operations, so we calculate them using multiple vector operation functions, vectorSum, vectorMax, vectorPow, vectorSubtraction, vectorAbs, vectorAddition and vectorDivision

In order for these operations to be well defined the following conditions must be met:
1. Operations on two vectors, compel that the vectors are the same size.
2. Vectors musn't be empty.
3. The input must be consisted of real numbers only.

 If not all the conditions are met, including bad program arguments (more on that later), the server will notify the client gracefully.

### Some technical details

Our project uses an object oriented approch, all the distance functions are inheriting from the abstract class, `Distance function`. to create the database for the KNN, we used a class called `GetNeighbors`, that returns a map of vectors, for the KNN to use. The `KNN` object will apply the KNN algorithm on our vector, and the server will send it according to the client's request.
We use a wrapper class for all the socket communication using a class called `SocketConnection`. In the server we implemented the Commander design pattern by using a CLI object that manages all of the server `Command`s.


# **Compilation and running instructions**

This project includes a makefile, to compile the project, run it with the make command.
```
make
```
After compilation, two new files will be created, server.out and client.out.
To run the server, we need 1 program argument:
1. port - the port that the server will bind to
execution example:
```
./server.out 12345
```
To run the client, we need 2 program argument:
1. ip - the ip of the computer that the server uses
2. port - the port of our server
execution example:
```
./client.out 127.0.0.1 12345
```
The client will the receive the following menu from the server:

1 upload an unclassified csv data file

2 algorithm settings

3 classify data

4 display results

5 download results

8 exit

To pick the option you want, type the option number and press enter.
- in option 1, you will be asked to uplaod two filesm one with a classified data and the second with the vectors that you wish to classify.
- in option 2, the current K and metric will be displayed. The default is k = 5 and metric = AUC.
- in option 3, the server will classify the data in the train file that you uploaded in option 1.
- in option 4, the results will be printed to your screen
- in option 5, you will need to give a path to a file, and the client will save the results to that file
- option 8 will close the client


### metrics

METRIC - is one of the following five distance metrics
-  AUC - for Auclidean distance
- MAN - for Manhattan distance
- CHB - for Chebyshev distance
- CAN - for Canberra distance
- MIN - for Monkowski distance (with a constant of 2)
