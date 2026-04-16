#include "modify.h"
#include "../../models/student.h"
#include <string>

template <typename K, typename V>
Node<K, V> *BSTModify<K, V>::Insert(Node *n, const K &key, const V &value) {
  if (!n) {
    count++;
    return new Node(key, value);
  }

  if (key < n->key)
    n->left = Insert(n->left, key, value);
  else if (key > n->key)
    n->right = Insert(n->right, key, value);
  else
    n->value = value;

  n->size = 1 + GetSize(n->left) + GetSize(n->right);
  return n;
}

template <typename K, typename V>
Node<K, V> *BSTModify<K, V>::Remove(Node *n, const K &key) {
  if (!n)
    return nullptr;

  if (key < n->key) {
    n->left = Remove(n->left, key);
  } else if (key > n->key) {
    n->right = Remove(n->right, key);
  } else {
    if (!n->left) {
      Node *r = n->right;
      delete n;
      count--;
      return r;
    }
    if (!n->right) {
      Node *l = n->left;
      delete n;
      count--;
      return l;
    }

    Node *min = FindMin(n->right);
    n->key = min->key;
    n->value = min->value;
    n->right = Remove(n->right, min->key);
  }

  n->size = 1 + GetSize(n->left) + GetSize(n->right);
  return n;
}

template <typename K, typename V> void BSTModify<K, V>::Destroy(Node *n) {
  if (!n)
    return;
  Destroy(n->left);
  Destroy(n->right);
  delete n;
}

template class BSTModify<std::string, Student>;
template class BSTModify<int, Student>;