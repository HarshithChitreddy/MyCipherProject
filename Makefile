all: cipher

cipher: main.o block.o stream.o utility.o
	g++ -o cipher main.o block.o stream.o utility.o

main.o: main.cpp block.h stream.h utility.h
	g++ -c main.cpp

block.o: block.cpp block.h utility.h
	g++ -c block.cpp

stream.o: stream.cpp stream.h
	g++ -c stream.cpp

utility.o: utility.cpp utility.h
	g++ -c utility.cpp

clean:
	rm -f *.o cipher
