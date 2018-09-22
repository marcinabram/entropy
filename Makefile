all: compile

compile:
	g++ -Wall -std=c++17 demo.cpp src/entropy.cpp -o demo.x

run:
	./demo.x signal.dat 2

compile_and_run: compile run

test:
	g++ -Wall -std=c++14 tests/entropy_test.cpp src/entropy.cpp \
	-o tests.x -lgtest -pthread
	./tests.x
