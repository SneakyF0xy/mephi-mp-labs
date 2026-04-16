BUILD = build
CXX = g++
CXXFLAGS = -std=c++17 -Wall -fopenmp

all: seq examples

seq: libseq.so
	$(CXX) $(CXXFLAGS) src/main.cpp -o $(BUILD)/seq

examples: $(BUILD)/example_1_1 $(BUILD)/example_1_2 $(BUILD)/example_1_3 $(BUILD)/example_1_4 $(BUILD)/example_1_5

$(BUILD)/example_1_1:
	$(CXX) $(CXXFLAGS) src/example_1_1.cpp -o $(BUILD)/example_1_1

$(BUILD)/example_1_2:
	$(CXX) $(CXXFLAGS) src/example_1_2.cpp -o $(BUILD)/example_1_2

$(BUILD)/example_1_3:
	$(CXX) $(CXXFLAGS) src/example_1_3.cpp -o $(BUILD)/example_1_3

$(BUILD)/example_1_4:
	$(CXX) $(CXXFLAGS) src/example_1_4.cpp -o $(BUILD)/example_1_4

$(BUILD)/example_1_5:
	$(CXX) $(CXXFLAGS) src/example_1_5.cpp -o $(BUILD)/example_1_5

test:
	mkdir -p $(BUILD)
	$(CXX) $(CXXFLAGS) test/array_test.cpp test/list_test.cpp ./$(BUILD)/libseq.so -lgtest -lgtest_main -pthread -o $(BUILD)/test

run:
	LD_LIBRARY_PATH=$(BUILD) ./$(BUILD)/seq

test-run:
	LD_LIBRARY_PATH=$(BUILD) ./$(BUILD)/test

clean:
	rm -rf $(BUILD)