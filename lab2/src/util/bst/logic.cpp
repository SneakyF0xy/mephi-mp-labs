#include "logic.h"
#include "../../models/student.h"
#include <string>

template <typename K, typename V> int BSTLogic<K, V>::GetSize(Node *n) const {
  return n ? n->size : 0;
}

template <typename K, typename V> Node<K, V> *BSTLogic<K, V>::FindMin(Node *n) const {
  while (n && n->left)
    n = n->left;
  return n;
}

template <typename K, typename V> Node<K, V> *BSTLogic<K, V>::FindMax(Node *n) const {
  while (n && n->right)
    n = n->right;
  return n;
}

template <typename K, typename V>
Node<K, V>* BSTLogic<K, V>::Select(Node *node, int rank) const {
  if (!node)
    return nullptr;

  int leftSize = GetSize(node->left);

  if (rank == leftSize)
    return node;
  if (rank < leftSize)
    return Select(node->left, rank);
  return Select(node->right, rank - leftSize - 1);
}

template <typename K, typename V>
Node<K, V>* BSTLogic<K, V>::Find(Node *n, const K &key) const {
  if (!n || n->key == key)
    return n;
  if (key < n->key)
    return Find(n->left, key);
  return Find(n->right, key);
}

template class BSTLogic<std::string, Student>;
template class BSTLogic<int, Student>;