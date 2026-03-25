#include "list.h"
#include "array.h"
#include <random>

class RandomSequenceGenerator {
private:
    std::mt19937 gen{std::random_device{}()};
    std::uniform_int_distribution<int> dist{1, 100000};

public:
    ArraySequence<int> generateArray(int size) {
        ArraySequence<int> arr;
        for (int i = 0; i < size; ++i) {
            arr.Append(dist(gen));
        }
        return arr;
    }
    
    ListSequence<int> generateList(int size) {
        ListSequence<int> lst;
        for (int i = 0; i < size; ++i) {
            lst.Append(dist(gen));
        }
        return lst;
    }
};