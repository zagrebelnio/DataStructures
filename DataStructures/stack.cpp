#include "stack.h"

//----------------------------------------------------------------Methods of stack
template<class T>
Stack<T>::Stack() {
    top = nullptr;
    size = 0;
}

template<class T>
void Stack<T>::push(T _data) {
    if (top == nullptr) {
        Node* temp = new Node(_data);
        top = temp;
    }
    else {
        Node* temp = new Node(_data);
        temp->next = top;
        top = temp;
    }
    size++;
}

template<class T>
void Stack<T>::pop() {
    if (top == nullptr)
        throw range_error("Спроба видалити елемент з порожнього стеку!");
    Node* temp = top;
    top = temp->next;
    temp->next = nullptr;
    delete temp;
    size--;
}

template<class T>
void Stack<T>::clear() {
    while (top) {
        pop();
    }
    size = 0;
}

template<class T>
bool Stack<T>::empty() {
    if (!top)
        return true;
    return false;
}

template <class T>
void Stack<T>::show() {
    for (iterator it = begin(); it != end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

template<class T>
typename Stack<T>::iterator Stack<T>::begin() {
    return iterator(this->top);
}

template<class T>
typename Stack<T>::iterator Stack<T>::end() {
    return iterator(nullptr);
}

//----------------------------------------------------------------Methods of iterator

template<class T>
typename Stack<T>::iterator& Stack<T>::iterator::operator++() {
    this->curr_ptr = curr_ptr->next;
    return *this;
}

template<class T>
T Stack<T>::iterator::operator*() {
    return curr_ptr->data;
}

template<class T>
T* Stack<T>::iterator::operator->() {
    return &(curr_ptr->data);
}

template<class T>
bool Stack<T>::iterator::operator!=(const Stack<T>::iterator& other) {
    return this->curr_ptr != other.curr_ptr;
}

template class Stack<int>;