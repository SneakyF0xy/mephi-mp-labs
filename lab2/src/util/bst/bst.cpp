#include "bst.h"
#include "../../models/student.h"
#include <stdexcept>

template <typename K, typename V> BST<K, V>::BST() : root(nullptr) {
  this->count = 0;
}

template <typename K, typename V> BST<K, V>::~BST() { Destroy(root); }

// IDictionary

template <typename K, typename V> int BST<K, V>::GetCount() const { return this->count; }

template <typename K, typename V> int BST<K, V>::GetCapacity() const { return -1; }

template <typename K, typename V>
void BST<K, V>::Insert(const K &key, const V &value) {
  root = Insert(root, key, value);
}

template <typename K, typename V> bool BST<K, V>::ContainsKey(const K &key) const {
  return Find(root, key) != nullptr;
}

template <typename K, typename V> V BST<K, V>::At(const K &key) const {
  Node *n = Find(root, key);
  if (!n)
    throw std::runtime_error("Key not found");
  return n->value;
}

template <typename K, typename V> void BST<K, V>::Remove(const K &key) {
  root = Remove(root, key);
}

// SortedSequnce

template <typename K, typename V> int BST<K, V>::GetLength() const { return this->count; }

template <typename K, typename V> bool BST<K, V>::GetIsEmpty() const {
  return this->count == 0;
}

template <typename K, typename V> V BST<K, V>::Get(int index) const {
  if (index < 0 || index >= this->count)
    throw std::out_of_range("Index out of bounds");
  return Select(root, index)->value;
}

template <typename K, typename V> V BST<K, V>::GetFirst() const {
  Node *n = FindMin(root);
  if (!n)
    throw std::runtime_error("Empty");
  return n->value;
}

template <typename K, typename V> V BST<K, V>::GetLast() const {
  Node *n = FindMax(root);
  if (!n)
    throw std::runtime_error("Empty");
  return n->value;
}

template <typename K, typename V> int BST<K, V>::IndexOf(const V &value) const {
  Node *cur = root;
  int index = 0;

  while (cur) {
    if (value < cur->value) {
      cur = cur->left;
    } else if (value > cur->value) {
      index += GetSize(cur->left) + 1;
      cur = cur->right;
    } else {
      return index + GetSize(cur->left);
    }
  }
  return -1;
}

template <typename K, typename V> void BST<K, V>::Add(const V &value) {
  root = Insert(root, static_cast<K>(value), value);
}

template <typename K, typename V> 
SortedSequence<V>* BST<K, V>::GetSubsequence(int start, int end) const {
  if (start < 0 || end >= this->count || start > end) {
    throw std::out_of_range("Invalid bounds for GetSubsequence");
  }
  
  BST<K, V>* subTree = new BST<K, V>();
  for (int i = start; i <= end; ++i) {
    subTree->Add(this->Get(i));
  }

  return subTree;
}

template class BST<std::string, Student>;
template class BST<int, Student>;