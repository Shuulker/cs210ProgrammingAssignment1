//
// Created by Samuel on 9/17/26.
//

#include <iostream>
#include <ostream>
#include "List.h"

template <typename T>
class ArrayList : public List<T> {
public:
    ArrayList():size_(0) {}

    void addFront(T* value) override {
        if (size_ >= CAPACITY) {
            std::cout << "ArrayList is full." << std::endl;
            return;
        }
        for (int i = size_; i > 0; --i) {
            data_[i] = data_[i - 1];
        }
        data_[0] = value;
        ++size_;
    }
    void deleteFront() override {
        if (size_ == 0) {
            std::cout << "ArrayList is empty." << std::endl;
            return;
        }
        delete data_[0];
        for (int i = 0; i < size_ - 1; ++i) {
            data_[i] = data_[i + 1];
        }
        --size_;
    }

    void addAnywhere(int position, T* value) override {
        if (position < 0 || position > size_) {
            std::cout << "Invalid position." << std::endl;
            return;
        }
        if (size_ >= CAPACITY) {
            std::cout << "ArrayList is full." << std::endl;
            return;
        }
        for (int i = size_; i > position; --i) {
            data_[i] = data_[i - 1];
        }
        data_[position] = value;
        ++size_;
    }

    void deleteAnywhere(int position) override {
        if (position < 0 || position >= size_) {
            std::cout << "Invalid position." << std::endl;
            return;
        }
        delete data_[position];
        for (int i = position; i < size_ - 1; ++i) {
            data_[i] = data_[i + 1];
        }
        --size_;
    }

    bool search(T* value) const override {
        for (int i = 0; i < size_; ++i) {
            if (*data_[i] == *value) return true;
        }
        return false;
    }

    void print() const override {
        for (int i = 0; i < size_; ++i) {
            std::cout << *data_[i] << ",";
        }
        std::cout << std::endl;
    }

    void concat(List<T>* other) override {
        ArrayList<T>* source = dynamic_cast<ArrayList<T>*>(other);
        if (source == nullptr) {
            std::cout << "Cannot concat lists of different types." << std::endl;
            return;
        }
        if (size_ + source->size_ > CAPACITY) {
            std::cout << "Not enough capacity to concat." << std::endl;
            return;
        }
        for (int i = 0; i < source->size_; ++i) {
            data_[size_ + i] = source->data_[i];
        }
        size_ += source->size_;
        source->size_ = 0;
    }

    void reverse() override {
        for (int i = 0, j = size_ - 1; i < j; ++i, --j) {
            T* temp = data_[i];
            data_[i] = data_[j];
            data_[j] = temp;
        }
    }

    ~ArrayList() override {
        for (int i = 0; i < size_; ++i) {
            delete data_[i];
        }
    }

private:
    static const int CAPACITY = 20;
    T* data_[CAPACITY];
    int size_;
};
