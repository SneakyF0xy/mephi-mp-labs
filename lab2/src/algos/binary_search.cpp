#include "binary_search.h"
#include "../models/student.h"

int fibonacci(int n) {
  if (n <= 1)
    return n;
  return fibonacci(n - 1) + fibonacci(n - 2);
}

template <typename T>
int BinarySearch(SortedSequence<T> *seq, T key, Mode mode, int m, int n) {
  int l = 0;
  int r = seq->GetLength() - 1;

  double ratio;
  switch (mode) {
  case HALF:
    ratio = 0.5;
    break;
  case GOLDEN_RATIO:
    ratio = 0.6180339887;
    break;
  case FRACTION:
    ratio = (double)m / n;
    break;
  case FIBONACCI:
    ratio = (double)fibonacci(m - 1) / fibonacci(m);
    break;
  default:
    ratio = 0.5;
  }

  while (l <= r) {
    int mid = l + (r - l) * ratio;
    T current = seq->Get(mid);

    if (current == key)
      return mid;
    if (current < key)
      l = mid + 1;
    else
      r = mid - 1;
  }
  return -1;
}

template int BinarySearch<Student>(SortedSequence<Student>*, Student, Mode, int, int);