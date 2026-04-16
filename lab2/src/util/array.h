#ifndef UTIL_ARRAY_H_
#define UTIL_ARRAY_H_

#include "sequence.h"
#include <stdexcept>

template <typename T> class ArraySequence : public Sequence<T> {
  T *data;
  int capacity;
  int length;

public:
  explicit ArraySequence(int size = 4);
  ~ArraySequence() override;

private:
  void resize();

public:
  T Get(int index) const override;
  T GetFirst() const override;
  T GetLast() const override;
  Sequence<T> *GetSubsequence(int start, int end) const override;
  void Append(T item) override;
  void Prepend(T item) override;
  void InsertAt(int index, T item) override;
  void Set(int index, T item) override;
  void Remove(T item) override;
  
  int GetLength() const override;
  bool GetIsEmpty() const override;
};

template <typename T> class ArraySortedSequence : public SortedSequence<T> {
  ArraySequence<T>* data;
  int UpperBound(const T &v) const;

public:
  ArraySortedSequence() : data(new ArraySequence<T>()) {}
  ~ArraySortedSequence() { delete data; }
  
  int GetLength() const override;
  bool GetIsEmpty() const override;
  T GetFirst() const override;
  T GetLast() const override;
  T Get(int i) const override;
  int IndexOf(const T &v) const override;
  void Add(const T &v);
  SortedSequence<T> *GetSubsequence(int s, int e) const override;
};

#endif