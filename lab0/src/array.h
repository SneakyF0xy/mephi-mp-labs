#ifndef ARRAY_H_
#define ARRAY_H_

#include <stdexcept>

#include "sequence.h"

template <typename TElement>
class ArraySequence : public Sequence<TElement> {
  TElement* data;
  int capacity;

 public:
  explicit ArraySequence(int size = 4) : capacity(size) {
    data = new TElement[size];
    this->length = 0;
  }

  ~ArraySequence() { delete[] data; }

 private:
  void resize() {
    int size = capacity * 2;

    TElement* resizedData = new TElement[size];
    for (int i = 0; i < this->length; i++) {
      resizedData[i] = data[i];
    }

    delete[] data;
    data = resizedData;
    capacity = size;
  }

 public:
  TElement Get(int index) {
    if (index < 0 || index >= this->length) {
      throw std::runtime_error("Invalid index!");
    }
    return data[index];
  }

  TElement GetFirst() { return Get(0); }

  TElement GetLast() { return Get(this->length - 1); }

  ArraySequence<TElement> GetSubsequence(int start, int end) {
    if (start > end || start < 0 || end >= this->length) {
      throw std::runtime_error("Invalid index!");
    }

    ArraySequence<TElement> subsequnce(end - start + 1);
    for (int i = start; i <= end; i++) {
      subsequnce.Append(data[i]);
    }
    return subsequnce;
  }

  void Append(TElement item) {
    if (this->length >= capacity) {
      resize();
    }

    data[this->length++] = item;
  }

  void Prepend(TElement item) {
    if (this->length >= capacity) {
      resize();
    }

    for (int i = this->length; i > 0; i--) {
      data[i] = data[i - 1];
    }
    data[0] = item;
    this->length++;
  }

  void InsertAt(int index, TElement item) {
    if (index < 0 || index > this->length) {
      throw std::runtime_error("Invalid size!");
    }

    if (this->length >= capacity) {
      resize();
    }

    for (int i = index; i < this->length; i++) {
      data[i + 1] = data[i];
    }
    data[index] = item;
    this->length++;
  }

  void Remove(TElement item) {
    int index = -1;
    for (int i = 0; i < this->length; i++) {
      if (data[i] == item) {
        index = i;
        break;
      }
    }

    if (index == -1) return;

    delete data[index];
    for (int i = index; i < this->length; i++) {
      data[i] = data[i + 1];
    }
  }

  int GetLength() { return this->length; }

  bool IsEmpty() { return this->length == 0; }
};

#endif  // ARRAY_H_
