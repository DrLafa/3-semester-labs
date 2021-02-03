all: class main test

class: vector_dynamic.cpp
	g++ -c vector_dynamic.cpp
	ar rvs vector.a vector_dynamic.o
	rm vector_dynamic.o
main: main.cpp
	g++ -c main.cpp
	g++ -o main main.o vector.a

test: test.cpp
	g++ test.cpp vector_dynamic.cpp -o runTests -lgtest -lpthread
