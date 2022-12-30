# *****************************************************
# Variables to control Makefile operation

CC = g++
CFLAGS = -std=c++11

# ****************************************************
# Targets needed to bring the executable up to date
all:
	$(MAKE) -C src/Extractors
	$(MAKE) -C src/DistanceCalculator
	$(MAKE) -C src/KNN
	$(MAKE) -C src/SocketConnection
	$(MAKE) -C src/ValidationFuncs
	$(MAKE) -C src/Server
	$(MAKE) -C obj server
	rm -f ./obj/server.o
	$(MAKE) -C src/Client
	$(MAKE) -C obj client
	rm -f ./obj/client.o

server:
	$(MAKE) -C src/Extractors
	$(MAKE) -C src/DistanceCalculator
	$(MAKE) -C src/KNN
	$(MAKE) -C src/SocketConnection
	$(MAKE) -C src/ValidationFuncs
	$(MAKE) -C src/Server
	$(MAKE) -C obj

client:
	$(MAKE) -C src/Extractors
	$(MAKE) -C src/DistanceCalculator
	$(MAKE) -C src/KNN
	$(MAKE) -C src/SocketConnection
	$(MAKE) -C src/ValidationFuncs
	$(MAKE) -C src/Server
	$(MAKE) -C obj



clean:
	rm *.out
	cd obj
	rm *.o
	cd ../
