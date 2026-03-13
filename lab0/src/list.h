#ifndef LIST_H_
#define LIST_H_

#include <stdexcept>

#include "sequence.h"

template <typename TElement>
struct Node {
  TElement element;
  Node* next;
  Node* prev;
  explicit Node(TElement e) : element(e), next(nullptr), prev(nullptr) {}
};

template <typename TElement>
class ListSequence : public Sequence<TElement> {
  Node<TElement>* head;
  Node<TElement>* tail;

 public:
  ListSequence() : head(nullptr), tail(nullptr) { this->length = 0; }

  ~ListSequence() {
    if (this->length == 0) return;

    Node<TElement>* current = head;
    for (int i = 0; i < this->length; i++) {
      Node<TElement>* nextNode = current->next;
      delete current;
      current = nextNode;
    }
  }

  TElement Get(int index) {
    if (index < 0 || index >= this->length) {
      throw std::runtime_error("Invalid index!");
    }

    Node<TElement>* current;

    if (index <= this->length / 2) {
      current = head;
      for (int i = 0; i < index; i++) {
        current = current->next;
      }
    } else {
      current = tail;
      for (int i = this->length - 1; i > index; i--) {
        current = current->prev;
      }
    }

    return current->element;
  }

  TElement GetFirst() {
    if (!head) throw std::runtime_error("List is empty");
    return head->element;
  }

  TElement GetLast() {
    if (!tail) throw std::runtime_error("List is empty");
    return tail->element;
  }

  ListSequence<TElement> GetSubsequence(int start, int end) {
    if (start < 0 || end >= this->length || start > end) {
      throw std::runtime_error("Invalid range");
    }

    ListSequence<TElement> result;
    Node<TElement>* current = head;

    for (int i = 0; i < start; i++) {
      current = current->next;
    }

    for (int i = start; i <= end; i++) {
      result.Append(current->element);
      current = current->next;
    }
    return result;
  }

  void Append(TElement item) {
    Node<TElement>* node = new Node<TElement>(item);
    if (!head) {
      head = tail = node;
      node->next = node->prev = node;
    } else {
      node->prev = tail;
      node->next = head;
      tail->next = node;
      head->prev = node;
      tail = node;
    }
    this->length++;
  }

  void Prepend(TElement item) {
    Node<TElement>* node = new Node<TElement>(item);
    if (!head) {
      head = tail = node;
      node->next = node->prev = node;
    } else {
      node->next = head;
      node->prev = tail;
      head->prev = node;
      tail->next = node;
      head = node;
    }
    this->length++;
  }

  void InsertAt(int index, TElement item) {
    if (index < 0 || index > this->length) {
      throw std::runtime_error("Invalid index");
    }

    if (index == 0) {
      Prepend(item);
      return;
    }
    if (index == this->length) {
      Append(item);
      return;
    }

    Node<TElement>* current = head;
    for (int i = 0; i < index; i++) {
      current = current->next;
    }

    Node<TElement>* newNode = new Node<TElement>(item);
    newNode->prev = current->prev;
    newNode->next = current;

    current->prev->next = newNode;
    current->prev = newNode;

    this->length++;
  }

  void Remove(TElement item) {
    if (this->length == 0) return;

    Node<TElement>* current = head;
    bool found = false;

    for (int i = 0; i < this->length; i++) {
      if (current->element == item) {
        found = true;
        break;
      }
      current = current->next;
    }

    if (!found) return;

    if (this->length == 1) {
      head = tail = nullptr;
    } else {
      current->prev->next = current->next;
      current->next->prev = current->prev;

      if (current == head) head = current->next;
      if (current == tail) tail = current->prev;
    }

    delete current;
    this->length--;
  }

  int GetLength() { return this->length; }

  bool IsEmpty() { return this->length == 0; }
};

#endif  // LIST_H_