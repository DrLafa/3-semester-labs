all: class main
	
class: vector_dynamic.cpp
	g++ -c vector_dynamic.cpp
	ar rvs vector.a vector_dynamic.o
	rm vector_dynamic.o
main: main.cpp
	g++ -c main.cpp
	g++ -o main main.o vector.a
