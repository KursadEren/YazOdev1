all: build run


build:
	g++ -I ./include/ -o ./lib/Reading.o -c ./src/Reading.cpp
	g++ -I ./include/ -o ./lib/NumberList.o -c ./src/NumberList.cpp
	
	g++ -I ./include/ -o ./bin/main ./lib/Reading.o ./lib/NumberList.o ./src/main.cpp

run:
	./bin/main.exe