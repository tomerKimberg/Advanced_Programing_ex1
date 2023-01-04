# *****************************************************
# Variables to control Makefile operation

CC = g++
CFLAGS = -c -std=c++11


# ****************************************************
# Targets needed to bring the executable up to date
all:
	mkdir -p "../../obj/obj_client"
	$(CC) $(CFLAGS) *.cpp
	mv *.o ../../obj/obj_client