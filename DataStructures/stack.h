#pragma once
#include <iostream>
#include <stdexcept>
#include <Windows.h>

using namespace std;

template<class T>
class Stack {
    class Node {
    public:
        T data;
        Node* next;
        explicit Node(T _data) : data(_data), next(nullptr) {}
        ~Node() {
            delete next;
        }
    };
    Node* top;
    unsigned int size;
public:
    class iterator {
        Node* curr_ptr;
    public:
        iterator() = default;
        explicit iterator(Node* ptr) : curr_ptr(ptr) {}
        iterator& operator++();
        T operator*();
        T* operator->();
        bool operator!=(const iterator&);

        friend class Stack<T>;
    };
    Stack();
    void push(T);
    void pop();
    void clear();
    bool empty();
    void show();
    Stack<T>::iterator begin();
    Stack<T>::iterator end();
};

template <typename T>
void processStack();