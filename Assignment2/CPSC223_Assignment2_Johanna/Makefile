CC = g++
CFLAGS = -std=c++11 -Wall

all: main tester

main: main.o LinkedList.h Node.h
	$(CC) $(CFLAGS) -o main main.o

tester: tester.o LinkedList.h Node.h
	$(CC) $(CFLAGS) -o tester tester.o

main.o: main.cpp LinkedList.h Node.h
	$(CC) $(CFLAGS) -c main.cpp

tester.o: tester.cpp LinkedList.h Node.h
	$(CC) $(CFLAGS) -c tester.cpp

run:
	./main

test:
	./tester

clean:
	rm -rf *.o main tester
