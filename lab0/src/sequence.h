#ifndef SEQUENCE_H_
#define SEQUENCE_H_

template <typename TElement>
class Sequence {
 protected:
  int length;
  bool isEmpty;

 public:
  int GetLength();
  bool GetIsEmpty();
  TElement GetFirst();
  TElement GetLast();
  TElement Get(int index);
  Sequence<TElement> GetSubsequence(int start, int end);
  void Append(TElement item);
  void Prepend(TElement item);
  void InsertAt(int index, TElement item);
  void Remove(TElement item);
};

#endif  // SEQUENCE_H_
