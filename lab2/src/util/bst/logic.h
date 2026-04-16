#ifndef UTIL_BST_LOGIC_H_
#define UTIL_BST_LOGIC_H_

#include "node.h"

template <typename K, typename V> class BSTLogic {
protected:
  using Node = ::Node<K, V>;

  int GetSize(Node *n) const;
  Node *FindMin(Node *n) const;
  Node *FindMax(Node *n) const;
  Node *Select(Node *node, int rank) const;
  Node *Find(Node *n, const K &key) const;
};

#endif