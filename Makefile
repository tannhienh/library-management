# Manage Library

cc = g++

objects = main.o manage_borrow.o book.o borrow.o

data_files = ./Data/*

build : $(objects)
	$(cc) -o main $(objects)

debug : $(objects)
	$(cc) -g -o main $(objects)

main.o : main.cpp
	$(cc) -c main.cpp

manage_borrow.o : manage_borrow.cpp
	$(cc) -c manage_borrow.cpp

book.o : book.cpp
	$(cc) -c book.cpp
	
borrow.o : borrow.cpp
	$(cc) -c borrow.cpp

clean :
	rm main *.o

clean-data :
	rm $(data_files)