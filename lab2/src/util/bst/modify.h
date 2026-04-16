#ifndef UTIL_BST_MODIFY_H_
#define UTIL_BST_MODIFY_H_

#include "logic.h"

template <typename K, typename V> class BSTModify : public BSTLogic<K, V> {
protected:
  using Node = ::Node<K, V>;
  using BSTLogic<K, V>::GetSize;
  using BSTLogic<K, V>::FindMin;

  int count;

  Node *Insert(Node *n, const K &key, const V &value);
  Node *Remove(Node *n, const K &key);
  void Destroy(Node *n);
};

#endif