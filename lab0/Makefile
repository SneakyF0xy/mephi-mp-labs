BUILD = build
CXX = g++
CXXFLAGS = -std=c++17 -Wall

all: seq test

seq: libseq.so
	$(CXX) $(CXXFLAGS) src/main.cpp ./$(BUILD)/libseq.so -o $(BUILD)/seq

test: libseq.so
	$(CXX) $(CXXFLAGS) test/array_test.cpp test/list_test.cpp ./$(BUILD)/libseq.so -lgtest -lgtest_main -pthread -o $(BUILD)/test

libseq.so:
	mkdir -p $(BUILD)
	$(CXX) $(CXXFLAGS) -fPIC -shared src/sequence.cpp -o $(BUILD)/libseq.so

run:
	LD_LIBRARY_PATH=$(BUILD) ./$(BUILD)/seq

test-run:
	LD_LIBRARY_PATH=$(BUILD) ./$(BUILD)/test

clean:
	rm -rf $(BUILD)
