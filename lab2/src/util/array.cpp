#include "array.h"
#include "../models/student.h"

template <typename T>
ArraySequence<T>::ArraySequence(int size) : capacity(size), length(0) {
  data = new T[size];
}

template <typename T> ArraySequence<T>::~ArraySequence() { delete[] data; }

template <typename T> void ArraySequence<T>::resize() {
  int size = capacity * 2;
  T *resizedData = new T[size];
  for (int i = 0; i < length; i++) {
    resizedData[i] = data[i];
  }
  delete[] data;
  data = resizedData;
  capacity = size;
}

template <typename T> T ArraySequence<T>::Get(int index) const {
  if (index < 0 || index >= length) {
    throw std::runtime_error("Invalid index!");
  }
  return data[index];
}

template <typename T> T ArraySequence<T>::GetFirst() const { return Get(0); }

template <typename T> T ArraySequence<T>::GetLast() const {
  return Get(length - 1);
}

template <typename T>
Sequence<T> *ArraySequence<T>::GetSubsequence(int start, int end) const {
  if (start < 0 || end >= length) {
    throw std::runtime_error("Invalid index!");
  }

  if (start > end) {
    return new ArraySequence<T>();
  }

  ArraySequence<T> *subseq = new ArraySequence<T>(end - start + 1);
  for (int i = start; i <= end; i++) {
    subseq->Append(data[i]);
  }

  return subseq;
}

template <typename T> void ArraySequence<T>::Append(T item) {
  if (length >= capacity) {
    resize();
  }

  data[length++] = item;
}

template <typename T> void ArraySequence<T>::Prepend(T item) {
  if (length >= capacity) {
    resize();
  }

  for (int i = length; i > 0; i--) {
    data[i] = data[i - 1];
  }

  data[0] = item;
  length++;
}

template <typename T> void ArraySequence<T>::InsertAt(int index, T item) {
  if (index < 0 || index > length) {
    throw std::runtime_error("Invalid size!");
  }

  if (length >= capacity) {
    resize();
  }

  for (int i = index; i < length; i++) {
    data[i + 1] = data[i];
  }

  data[index] = item;
  length++;
}

template <typename T> void ArraySequence<T>::Set(int index, T item) {
  if (index < 0 || index > length) {
    throw std::runtime_error("Invalid size!");
  }

  data[index] = item;
}

template <typename T> void ArraySequence<T>::Remove(T item) {
  int index = -1;
  for (int i = 0; i < length; i++) {
    if (data[i] == item) {
      index = i;
      break;
    }
  }

  if (index == -1)
    return;

  for (int i = index; i < length; i++) {
    data[i] = data[i + 1];
  }
  length--;
}

template <typename T> int ArraySequence<T>::GetLength() const {
  return length;
}

template <typename T> bool ArraySequence<T>::GetIsEmpty() const {
  return length == 0;
}

// ArraySortedSequence

template <typename T> int ArraySortedSequence<T>::UpperBound(const T &v) const {
  int l = 0, r = data->GetLength();
  while (l < r) {
    int mid = l + (r - l) / 2;
    if (data->Get(mid) <= v)
      l = mid + 1;
    else
      r = mid;
  }
  return l;
}

template <typename T> int ArraySortedSequence<T>::GetLength() const {
  return data->GetLength();
}

template <typename T> bool ArraySortedSequence<T>::GetIsEmpty() const {
  return data->GetIsEmpty();
}

template <typename T> T ArraySortedSequence<T>::GetFirst() const {
  return data->GetFirst();
}

template <typename T> T ArraySortedSequence<T>::GetLast() const {
  return data->GetLast();
}

template <typename T> T ArraySortedSequence<T>::Get(int i) const {
  return data->Get(i);
}

template <typename T> void ArraySortedSequence<T>::Add(const T &v) {
  data->InsertAt(UpperBound(v), v);
}

template <typename T> int ArraySortedSequence<T>::IndexOf(const T &v) const {
  int l = 0, r = data->GetLength() - 1;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    T current = data->Get(mid);
    if (current == v)
      return mid;
    if (current < v)
      l = mid + 1;
    else
      r = mid - 1;
  }
  return -1;
}

template <typename T>
SortedSequence<T> *ArraySortedSequence<T>::GetSubsequence(int s, int e) const {
  if (s < 0 || e >= data->GetLength() || s > e)
    throw std::runtime_error("Invalid index!");

  auto *r = new ArraySortedSequence<T>();

  for (int i = s; i <= e; i++)
    r->data->Append(data->Get(i));

  return r;
}

template class ArraySequence<Student>;
template class ArraySortedSequence<Student>;