# Manage Library

cc = g++

objects = main.o book.o borrow.o

data_files = ./Data/*

main : $(objects)
	$(cc) -o main *.o

main.o : main.cpp
	$(cc) -c main.cpp

book.o : book.cpp
	$(cc) -c book.cpp
	
borrow.o : borrow.cpp
	$(cc) -c borrow.cpp

clean :
	rm main $(objects)

clean-data :
	rm $(data_files)