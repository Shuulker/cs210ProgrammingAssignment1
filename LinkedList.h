//
// Created by Samuel on 9/17/26.
//

#pragma once
#include <iostream>
#include <ostream>

#include "Node.h"
#include "List.h"

template <typename T>
class LinkedList : public List<T> {
public:
    LinkedList() : head_(nullptr), size_(0) {}

    void addFront(T* value) override {
        Node<T>* fresh = new Node<T>(value);
        fresh->next = head_;
        head_ = fresh;
        ++size_;
    }

    void deleteFront() override {
        if (head_ == nullptr) {
            std::cout << "LinkedList is empty." << std::endl;
            return;
        }
        Node<T>* doomed = head_;
        head_ = head_->next;
        delete doomed->data;
        delete doomed;
        --size_;
    }

    void addAnywhere(int position, T* value) override {
        if (position < 0 || position > size_) {
            std::cout << "Invalid position." << std::endl;
            return;
        }
        if (position == 0) {
            addFront(value);
            return;
        }
        Node<T>* prev = head_;
        for (int i = 0; i < position - 1; ++i) {
            prev = prev->next;
        }
        Node<T>* fresh = new Node<T>(value);
        fresh->next = prev->next;
        prev->next = fresh;
        ++size_;
    }

    void deleteAnywhere(int position) override {
        if (position < 0 || position >= size_) {
            std::cout << "Invalid position." << std::endl;
            return;
        }
        if (position == 0) {
            deleteFront();
            return;
        }
        Node<T>* prev = head_;
        for (int i = 0; i < position - 1; ++i) {
            prev = prev->next;
        }
        Node<T>* doomed = prev->next;
        prev->next = doomed->next;
        delete doomed->data;
        delete doomed;
        --size_;
    }

    bool search(T* value) const override {
        Node<T>* current = head_;
        while (current != nullptr) {
            if (*current->data == *value) return true;
            current = current->next;
        }
        return false;
    }

    void print() const override {
        Node<T>* current = head_;
        while (current != nullptr) {
            std::cout << *current->data << ",";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void reverse() override {
        Node<T>* prev = nullptr;
        Node<T>* current = head_;
        while (current != nullptr) {
            Node<T>* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head_ = prev;
    }

    void concat(List<T>* other) override {
        LinkedList<T>* source = dynamic_cast<LinkedList<T>*>(other);
        if (source == nullptr) {
            std::cout << "Cannot concat lists of different types." << std::endl;
            return;
        }
        if (source->head_ == nullptr) {
            return;
        }
        if (head_ == nullptr) {
            head_ = source->head_;
        } else {
            Node<T>* tail = head_;
            while (tail->next != nullptr) {
                tail = tail->next;
            }
            tail->next = source->head_;
        }
        size_ += source->size_;
        source->head_ = nullptr;
        source->size_ = 0;
    }

    ~LinkedList() override {
        while (head_ != nullptr) {
            Node<T>* doomed = head_;
            head_ = head_->next;
            delete doomed->data;
            delete doomed;
        }
    }

private:
    Node<T>* head_;
    int size_;
};
