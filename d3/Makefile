.PHONY: clean

CXX ?= test ionice g++
#CXX ?= g++
#CXX ?= clang++

CXXFLAGS ?= -O2 -std=c++17 -Wfatal-errors -pedantic -Wall -Wconversion

# All test sources
TEST_SRC := $(wildcard *_test.cpp)

# All test executables
TEST_EXE := $(TEST_SRC:.cpp=)

# All .cpp files except *_test.cpp
SRC := $(filter-out $(TEST_SRC), $(wildcard *.cpp))

# All .cpp files except the ones with a main function
DEP_SRC := $(filter-out main.cpp, $(SRC))


all: main

test: $(TESTS)

numbers_test: numbers_test.cpp
	$(CXX) $(CXXFLAGS) $(DEP_SRC) $^ -o $@

vectorfield_test: vectorfield_test.cpp
	$(CXX) $(CXXFLAGS) $(DEP_SRC) $^ -o $@

turtle_test: turtle_test.cpp
	$(CXX) $(CXXFLAGS) $(DEP_SRC) $^ -o $@

main: $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $@

clean:
	rm -f main $(TESTS)
