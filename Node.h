//
// Created by Samuel on 9/17/26.
//

# pragma once

template <typename T>
class Node {

public:
    T* data;
    Node<T>* next;
    
    explicit Node(T* value) : data(value), next(nullptr) {}
};