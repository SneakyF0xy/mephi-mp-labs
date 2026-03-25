#ifndef LIST_H_
#define LIST_H_

#include <stdexcept>
#include "sequence.h"

template <typename T>
struct Node {
    T element;
    Node* next;
    Node* prev;
    explicit Node(T e) : element(e), next(nullptr), prev(nullptr) {}
};

template <typename T>
class ListSequence : public Sequence<T> {
    Node<T>* head;
    Node<T>* tail;

public:
    ListSequence() : head(nullptr), tail(nullptr) { this->length = 0; }

    ~ListSequence() {
        if (head == nullptr) return;
        Node<T>* current = head;
        for (int i = 0; i < this->length; ++i) {
            Node<T>* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = tail = nullptr;
        this->length = 0;
    }

    T Get(int index) const override {
        if (index < 0 || index >= this->length) {
            throw std::runtime_error("Invalid index");
        }
        Node<T>* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->element;
    }

    T GetFirst() const override {
        if (!head) throw std::runtime_error("List is empty");
        return head->element;
    }

    T GetLast() const override {
        if (!tail) throw std::runtime_error("List is empty");
        return tail->element;
    }

    Sequence<T>* GetSubsequence(int start, int end) const override {
        if (start < 0 || end >= this->length || start > end) {
            return new ListSequence<T>();
        }
        ListSequence<T>* result = new ListSequence<T>();
        Node<T>* current = head;
        for (int i = 0; i < start; ++i) {
            current = current->next;
        }
        for (int i = start; i <= end; ++i) {
            result->Append(current->element);
            current = current->next;
        }
        return result;
    }

    void Append(T item) override {
        Node<T>* node = new Node<T>(item);
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

    void Prepend(T item) override {
        Node<T>* node = new Node<T>(item);
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

    void InsertAt(int index, T item) override {
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
        Node<T>* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        Node<T>* newNode = new Node<T>(item);
        newNode->prev = current->prev;
        newNode->next = current;
        current->prev->next = newNode;
        current->prev = newNode;
        this->length++;
    }

    void Set(int index, T item) override {
        if (index < 0 || index >= this->length) {
            throw std::runtime_error("Invalid index");
        }
        Node<T>* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        current->element = item;
    }

    void Remove(T item) override {
        if (this->length == 0) return;
        Node<T>* current = head;
        for (int i = 0; i < this->length; ++i) {
            if (current->element == item) {
                break;
            }
            current = current->next;
        }
        if (current->element != item) return;
        if (this->length == 1) {
            delete current;
            head = tail = nullptr;
        } else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            if (current == head) head = current->next;
            if (current == tail) tail = current->prev;
            delete current;
        }
        this->length--;
    }

    int GetLength() const override { return this->length; }
    bool GetIsEmpty() const override { return this->length == 0; }
};

#endif