CC=g++
CFLAGS=-c -Wall
# PATH_mySearch=mySearch
PATH_mySort=mySort

output: main.o mySort.o
	${CC} main.o mySort.o -o output

main.o: main.cpp
	${CC} ${CFLAGS} main.cpp

# mySearch.o: ${PATH_mySearch}/mySearch.cpp ${PATH_mySearch}/mySearch.h
# 	${CC} ${CFLAGS} ${PATH_mySearch}/mySearch.cpp

mySort.o: ${PATH_mySort}/mySort.cpp ${PATH_mySort}/mySort.h
	${CC} ${CFLAGS} ${PATH_mySort}/mySort.cpp

clean:
	del *.o output.exe