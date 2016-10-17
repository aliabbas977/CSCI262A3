# simple makefile for banshee

CC = g++

all : traffic.o activity.o analysis.o alert.o
	$(CC) -o Traffic traffic.o activity.o analysis.o alert.o

traffic.o : traffic.h traffic.cpp
	$(CC) -c traffic.cpp

activity.o : activity.cpp
	$(CC) -c activity.cpp

analysis.o : analysis.cpp
	$(CC) -c analysis.cpp

alert.o : alert.cpp
	$(CC) -c alert.cpp

clean:
	rm Traffic *.o
