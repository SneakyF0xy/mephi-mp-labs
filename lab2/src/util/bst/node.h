#ifndef UTIL_BST_NODE_H_
#define UTIL_BST_NODE_H_

template <typename K, typename V> struct Node {
  K key;
  V value;
  Node *left;
  Node *right;
  int size;

  Node(K k, V v) : key(k), value(v), left(nullptr), right(nullptr), size(1) {}
};

#endif