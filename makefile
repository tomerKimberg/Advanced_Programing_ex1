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
	$(MAKE) -C src/Command
	$(MAKE) -C src/CLI
	$(MAKE) -C src/Server
	$(MAKE) -C src/Client
	$(MAKE) -C obj server
	$(MAKE) -C obj client

server:
	$(MAKE) -C src/Extractors
	$(MAKE) -C src/DistanceCalculator
	$(MAKE) -C src/KNN
	$(MAKE) -C src/SocketConnection
	$(MAKE) -C src/ValidationFuncs
	$(MAKE) -C src/Server
	$(MAKE) -C obj server

client:
	$(MAKE) -C src/Extractors
	$(MAKE) -C src/DistanceCalculator
	$(MAKE) -C src/KNN
	$(MAKE) -C src/SocketConnection
	$(MAKE) -C src/ValidationFuncs
	$(MAKE) -C src/Client
	$(MAKE) -C obj client



clean:
	$(MAKE) -C obj clean
	rm server.out
	rm client.out
