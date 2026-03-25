#ifndef MERGE_H_
#define MERGE_H_

#pragma once
#include "sorter.h"


template <typename T>
class MergeSorter : public ISorter<T> {
 public:
  Sequence<T>* Sort(Sequence<T>* seq);

 private:
  Sequence<T>* mergeSort(Sequence<T>* seq);
  Sequence<T>* merge(Sequence<T>* left, Sequence<T>* right);
};


template <typename T>
Sequence<T>* MergeSorter<T>::Sort(Sequence<T>* seq) {
  if (seq == nullptr || seq->GetLength() <= 1) {
    return seq;
  }
  return mergeSort(seq);
}


template <typename T>
Sequence<T>* MergeSorter<T>::mergeSort(Sequence<T>* seq) {
  int n = seq->GetLength();
  if (n <= 1) return seq;

  int mid = n / 2;

  Sequence<T>* left  = seq->GetSubsequence(0, mid - 1);
  Sequence<T>* right = seq->GetSubsequence(mid, n - 1);

  Sequence<T>* sortedLeft  = mergeSort(left);
  Sequence<T>* sortedRight = mergeSort(right);

  Sequence<T>* merged = merge(sortedLeft, sortedRight);

  if (left  != sortedLeft)  delete left;
  if (right != sortedRight) delete right;
  delete sortedLeft;
  delete sortedRight;

  return merged;
}


template <typename T>
Sequence<T>* MergeSorter<T>::merge(Sequence<T>* left, Sequence<T>* right) {
  Sequence<T>* result = left->GetSubsequence(0, -1);

  int i = 0;
  int j = 0;

  while (i < left->GetLength() && j < right->GetLength()) {
    if (left->Get(i) <= right->Get(j)) {
      result->Append(left->Get(i++));
    } else {
      result->Append(right->Get(j++));
    }
  }

  while (i < left->GetLength())  result->Append(left->Get(i++));
  while (j < right->GetLength()) result->Append(right->Get(j++));

  return result;
}

#endif  // MERGE_H_