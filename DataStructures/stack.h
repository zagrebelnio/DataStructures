#pragma once
#include <iostream>
#include <memory>
#include <stdexcept>
#include <Windows.h>

using namespace std;

template<class T>
class stack {
    struct Node {
        T data;
        shared_ptr<Node> next;
        explicit Node(T _data) : data(_data) {}
        ~Node() {
            next.reset();
        }
    };
    shared_ptr<Node> top;
    unsigned int size;
public:
    class iterator {
        Node* curr_ptr;
    public:
        iterator() = default;
        explicit iterator(Node* ptr) : curr_ptr(ptr) {}
        iterator& operator++();
        const iterator operator++(int);
        T operator*();
        T* operator->();
        bool operator==(const iterator&);
        bool operator!=(const iterator&);

        friend class stack<T>;
    };
    stack();
    void push(T);
    void pop();
    void clear();
    bool empty();
    const unsigned int get_size() const;
    const T& peek();
    stack<T>::iterator begin();
    stack<T>::iterator end();
};
