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

  ~ArraySequence() override { delete[] data; }

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
  TElement Get(int index) const override {
    if (index < 0 || index >= this->length) {
      throw std::runtime_error("Invalid index!");
    }
    return data[index];
  }

  TElement GetFirst() const override { return Get(0); }

  TElement GetLast() const override { return Get(this->length - 1); }

  Sequence<TElement>* GetSubsequence(int start, int end) const override {
    if (start < 0 || end >= this->length) {
        throw std::runtime_error("Invalid index!");
    }

    if (start > end) {
      return new ArraySequence<TElement>();
    }

    ArraySequence<TElement>* subseq = new ArraySequence<TElement>(end - start + 1);
    for (int i = start; i <= end; i++) {
        subseq->Append(data[i]);
    }
    return subseq;
  }

  void Append(TElement item) override {
    if (this->length >= capacity) {
      resize();
    }

    data[this->length++] = item;
  }

  void Prepend(TElement item) override {
    if (this->length >= capacity) {
      resize();
    }

    for (int i = this->length; i > 0; i--) {
      data[i] = data[i - 1];
    }
    data[0] = item;
    this->length++;
  }

  void InsertAt(int index, TElement item) override {
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

  void Set(int index, TElement item) override {
    if (index < 0 || index > this->length) {
      throw std::runtime_error("Invalid size!");
    }

    data[index] = item;
  }

  void Remove(TElement item) override {
    int index = -1;
    for (int i = 0; i < this->length; i++) {
      if (data[i] == item) {
        index = i;
        break;
      }
    }

    if (index == -1) return;

    for (int i = index; i < this->length; i++) {
      data[i] = data[i + 1];
    }
  }

  int GetLength() const override { return this->length; }

  bool GetIsEmpty() const override { return this->length == 0; }
};

#endif  // ARRAY_H_
