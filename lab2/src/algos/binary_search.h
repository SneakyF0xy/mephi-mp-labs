#ifndef ALGOS_BINARY_SEARCH_H_
#define ALGOS_BINARY_SEARCH_H_

#include "../util/sequence.h"

int fibonacci(int n);

enum Mode {
  HALF,
  GOLDEN_RATIO,
  FRACTION,
  FIBONACCI,
};

template <typename T>
int BinarySearch(SortedSequence<T> *seq, T key, Mode mode, int m = 1,
                 int n = 1);

#endif