BUILD = build
CXX = g++
CXXFLAGS = -std=c++17 -Wall

all: seq test

seq: libseq.so
	$(CXX) $(CXXFLAGS) src/main.cpp ./$(BUILD)/libseq.so -o $(BUILD)/seq

test: libseq.so
	$(CXX) $(CXXFLAGS) test/*.cpp ./$(BUILD)/libseq.so \
	$(shell pkg-config --cflags --libs gtest) \
	-lstdc++ \
	-lgtest_main \
	-o $(BUILD)/test
	
libseq.so:
	mkdir -p $(BUILD)
	$(CXX) $(CXXFLAGS) -fPIC -shared src/*.h src/sort/* -o $(BUILD)/libseq.so

run:
	LD_LIBRARY_PATH=$(BUILD) ./$(BUILD)/seq

test-run:
	LD_LIBRARY_PATH=$(BUILD) ./$(BUILD)/test

clean:
	rm -rf $(BUILD)
