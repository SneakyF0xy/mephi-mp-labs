BUILD = build
CXX = g++
CXXFLAGS = -std=c++17 -O2

.PHONY: all seq test test-visible run test-run clean

all: seq test

seq:
	mkdir -p $(BUILD)
	$(CXX) $(CXXFLAGS) src/util/*.cpp src/util/bst/*.cpp src/algos/*.cpp src/main.cpp -o $(BUILD)/seq

test:
	mkdir -p $(BUILD)
	$(CXX) $(CXXFLAGS) src/util/*.cpp src/util/bst/*.cpp src/algos/*.cpp test/*.cpp -lgtest -lgtest_main -pthread -o $(BUILD)/test
run: seq
	./$(BUILD)/seq

test-run: test
	./$(BUILD)/test

test-visible-run: test-visible
	./$(BUILD)/test-visible

clean:
	rm -rf $(BUILD)