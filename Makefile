#Makefile for Business-Card-Reader

all: MyExceptions.h driver.o cardReader.o stringBST.o
	g++ -ansi -Wall MyExceptions.h driver.o cardReader.o stringBST.o -o driver.out

stringBST.o: stringBST.cpp
	g++ -ansi -Wall -c stringBST.cpp

cardReader.o: cardReader.cpp
	g++ -ansi -Wall -c cardReader.cpp

driver.o: driver.cpp
	g++ -ansi -Wall -c driver.cpp

run:
	./driver.out $(STRING) $(STRING)

clean:
	rm -rf *.o
	rm -f *.out
	rm -f *~*.h.gch *#[
