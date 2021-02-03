all: main test

main: main.cpp
	g++ main.cpp dialog.cpp Table.cpp Departament.cpp Radiostation.cpp Telecom.cpp Printing.cpp -o main

test: test.cpp
	g++ test.cpp Departament.cpp Telecom.cpp Radiostation.cpp Printing.cpp -o runTests -lgtest -lpthread
