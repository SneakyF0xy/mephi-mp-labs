#ifndef SEQUENCE_H_
#define SEQUENCE_H_

template <typename T>
class Sequence {
 protected:
  int length;
  bool isEmpty;

 public:
  virtual ~Sequence() = default;

  virtual int GetLength() const = 0;
  virtual bool GetIsEmpty() const = 0;
  virtual T GetFirst() const = 0;
  virtual T GetLast() const = 0;
  virtual T Get(int index) const = 0;

  virtual Sequence<T>* GetSubsequence(int start, int end) const = 0;

  virtual void Append(T item) = 0;
  virtual void Prepend(T item) = 0;
  virtual void InsertAt(int index, T item) = 0;
  virtual void Set(int index, T item) = 0;
  virtual void Remove(T item) = 0;
};

#endif  // SEQUENCE_H_
