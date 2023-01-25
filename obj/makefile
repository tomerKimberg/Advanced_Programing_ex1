# *****************************************************
# Variables to control Makefile operation

CC = g++
CFLAGS = -std=c++11 -lpthread

# ****************************************************
# Targets needed to bring the executable up to date
all:
	$(CC) $(CFLAGS) *.o
	mv *.out ../

server:
	$(CC) $(CFLAGS) *.o obj_server/*.o -o server.out
	mv server.out ../

client:
	$(CC) $(CFLAGS) *.o obj_client/*.o -o client.out
	mv client.out ../
clean:
	rm *.o
	rm obj_client/*.o
	rm obj_server/*.o
