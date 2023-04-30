header_loc = -I ./include
object_files = ./build/listoffiles.o ./build/listofwords.o

GCC = g++
c_flags = -Wall

all: requirements ${object_files} 
	${GCC} ${c_flags} ${header_loc} ./src/main.cc ${object_files} -o ./bin/exercise1

requirements: 
	mkdir -p ./build/
	mkdir -p ./bin/
	cp -r ./input ./bin/input/

./build/listoffiles.o: ./src/listoffiles.cc
	${GCC} ${c_flags} ${header_loc} -c ./src/listoffiles.cc -o ./build/listoffiles.o

./build/listofwords.o: ./src/listofwords.cc
	${GCC} ${c_flags} ${header_loc} -c ./src/listofwords.cc -o ./build/listofwords.o

clean:
	rm -rf ./build/*