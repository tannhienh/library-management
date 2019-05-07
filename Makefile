# Library Management
# Compiler: GNU C++

cc = g++

objects = main.o manage_library.o book.o borrow.o

source = main.cpp manage_library.cpp book.cpp borrow.cpp

data_files = ./Data/*

build : $(objects)
	$(cc) -o main $(objects)

debug : 
	$(cc) -g -o main $(source)

main.o : main.cpp
	$(cc) -c main.cpp

manage_library.o : manage_library.cpp
	$(cc) -c manage_library.cpp

book.o : book.cpp
	$(cc) -c book.cpp
	
borrow.o : borrow.cpp
	$(cc) -c borrow.cpp

clean :
	rm main $(objects)

clean-data :
	rm $(data_files)