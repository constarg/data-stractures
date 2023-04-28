header_loc = -I ./include
object_files = ./build/listoffiles.o ./build/listofwords.o

GCC = g++
c_flags = -Wall

all: ${object_files}
	mkdir -p ./bin/
	${GCC} ${c_flags} ${header_loc} ./src/main.cc ${object_files} -o ./bin/exercise1

./build/listoffiles.o: ./src/listoffiles.cc
	mkdir -p ./build/
	${GCC} ${c_flags} ${header_loc} -c ./src/listoffiles.cc -o ./build/listoffiles.o

./build/listofwords.o: ./src/listofwords.cc
	mkdir -p ./build/
	${GCC} ${c_flags} ${header_loc} -c ./src/listofwords.cc -o ./build/listofwords.o

clean:
	rm -rf ./build/*