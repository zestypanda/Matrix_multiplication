CXX = g++
CXXFLAGS = -std=c++0x -Wall

ifeq ($(DEBUG), 1)
	CXXFLAGS += -O0 -pedantic
else
	CXXFLAGS += -O3
endif

all: test_v1 test_v2

test_v1: test.cpp bin/matrix_mul_v1.o
	$(CXX) $(CXXFLAGS) -o bin/$@ $^ 

test_v2: test.cpp bin/matrix_mul_v2.o
	$(CXX) $(CXXFLAGS) -o bin/$@ $^ 

bin/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $^ 


clean:
	rm -r ./bin/*
