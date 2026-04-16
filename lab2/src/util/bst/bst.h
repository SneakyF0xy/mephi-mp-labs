#ifndef UTIL_BST_BST_H_
#define UTIL_BST_BST_H_

#include "../../util/dictionary.h"
#include "../../util/sequence.h"
#include "modify.h"

template <typename K, typename V>
class BST : public IDictionary<K, V>,
            public SortedSequence<V>,
            protected BSTModify<K, V> {
private:
  using Node = ::Node<K, V>;
  using BSTModify<K, V>::Insert;
  using BSTModify<K, V>::Remove;
  using BSTModify<K, V>::Destroy;
  using BSTModify<K, V>::Find;
  using BSTModify<K, V>::FindMin;
  using BSTModify<K, V>::FindMax;
  using BSTModify<K, V>::Select;
  using BSTModify<K, V>::GetSize;

  Node *root;
  
public:
  BST();
  ~BST();
  int GetCount() const override;
  int GetCapacity() const override;
  void Insert(const K &key, const V &value) override;
  bool ContainsKey(const K &key) const override;
  V At(const K &key) const override;
  void Remove(const K &key) override;

  int GetLength() const override;
  bool GetIsEmpty() const override;
  V Get(int index) const override;
  V GetFirst() const override;
  V GetLast() const override;
  int IndexOf(const V &value) const override;
  void Add(const V &value) override;
  SortedSequence<V> *GetSubsequence(int start, int end) const;
};

#endif