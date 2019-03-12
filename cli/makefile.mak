CC = g++ $(CCFLAGS)

CCFLAGS = -std=c++11

all: tca

tca: main.o functionPoint.o cocomo.o
	$(CC) main.o functionPoint.o cocomo.o -o tca.exe

main.o: src/main.cpp include/functionPoint.h include/cocomo.h
	$(CC) -c src/main.cpp

functionPoint.o: src/functionPoint.cpp include/functionPoint.h
	$(CC) -c src/functionPoint.cpp

cocomo.o: src/cocomo.cpp include/cocomo.h
	$(CC) -c src/cocomo.cpp
