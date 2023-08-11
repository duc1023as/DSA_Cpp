CC=g++
CFLAGS=-c -Wall
PATH_mySearch=mySearch

output: main.o mySearch.o
	${CC} main.o mySearch.o -o output

main.o: main.cpp
	${CC} ${CFLAGS} main.cpp

mySearch.o: ${PATH_mySearch}/mySearch.cpp ${PATH_mySearch}/mySearch.h
	${CC} ${CFLAGS} ${PATH_mySearch}/mySearch.cpp

clean:
	del *.o output.exe