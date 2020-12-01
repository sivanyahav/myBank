CC=gcc 
FLAGS= -Wall -g
AR=ar

all:main

main: main.o myBank.o
	$(CC) $(FLAGS) main.o myBank.o -o main

main.o: main.c myBank.h
	$(CC) $(FLAGS) -c main.c

myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -c myBank.c

.PHONY: clean all

clean: 
	rm -f main *.o
