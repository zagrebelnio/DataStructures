#include "stack.h"
//----------------------------------------------------------------Methods of stack
template<class T>
stack<T>::stack() {
    top = nullptr;
    size = 0;
}
template<class T>
const T& stack<T>::peek() {
    try {
        if (top == nullptr) {
            throw "Стек порожній!";
        }
    }
    catch (const char* s) {
        throw s;
    }
    return top->data;
}

template<class T>
const unsigned int stack<T>::get_size() const {
    return size;
}

template<class T>
void stack<T>::push(T _data) {
    if (top == nullptr) {
        shared_ptr<Node> temp(new Node(_data));
        top = temp;
    }
    else {
        shared_ptr<Node> temp(new Node(_data));
        temp->next = top;
        top = temp;
    }
    size++;
}

template<class T>
void stack<T>::pop() {
    if (top == nullptr)
        throw range_error("Спроба видалити елемент з порожнього стеку!");
    shared_ptr<Node> temp = top;
    top = temp->next;
    temp->next = nullptr;
    temp.reset();
    size--;
}

template<class T>
void stack<T>::clear() {
    while (top) {
        pop();
    }
    size = 0;
}

template<class T>
bool stack<T>::empty() {
    if (!top)
        return true;
    return false;
}

template<class T>
typename stack<T>::iterator stack<T>::begin() {
    return iterator(this->top.get());
}

template<class T>
typename stack<T>::iterator stack<T>::end() {
    return iterator(nullptr);
}
//--------------------------------------------------------------------------Methods of iterator

template<class T>
typename stack<T>::iterator& stack<T>::iterator::operator++() {
    this->curr_ptr = curr_ptr->next.get();
    return *this;
}

template<class T>
const typename stack<T>::iterator stack<T>::iterator::operator++(int) {
    stack<T>::iterator temp(curr_ptr);
    ++(*this);
    return temp;
}

template<class T>
T stack<T>::iterator::operator*() {
    return curr_ptr->data;
}

template<class T>
T* stack<T>::iterator::operator->() {
    return &(curr_ptr->data);
}

template<class T>
bool stack<T>::iterator::operator==(const stack<T>::iterator& other) {
    return this->curr_ptr == other.curr_ptr;
}

template<class T>
bool stack<T>::iterator::operator!=(const stack<T>::iterator& other) {
    return this->curr_ptr != other.curr_ptr;
}

template class stack<int>;