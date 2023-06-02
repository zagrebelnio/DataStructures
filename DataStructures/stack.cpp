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

template <typename T>
void processStack() {
    Stack<T> myStack;
    typename Stack<T>::iterator it = myStack.begin();

    int choice;
    T value;

    do {
        cout << "--------------------------------------" << endl;
        cout << "1. Перевірка стеку на пустоту" << endl;
        cout << "2. Очищення стеку" << endl;
        cout << "3. Видалення елемента з вершини стеку" << endl;
        cout << "4. Включення нового елемента у стек" << endl;
        cout << "5. Виведення вмісту стеку" << endl;
        cout << "0. Вихід" << endl;
        cout << "Ваш вибір: ";
        cin >> choice;
        cout << "--------------------------------------" << endl;

        switch (choice) {
        case 1:
            if (myStack.empty()) {
                cout << "Стек порожній." << endl;
            }
            else {
                cout << "Стек не порожній." << endl;
            }
            break;

        case 2:
            myStack.clear();
            cout << "Стек очищений." << endl;
            break;

        case 3:
            myStack.pop();
            cout << "Елемент видалений з вершини стеку." << endl;
            break;

        case 4:
            cout << "Введіть значення нового елемента: ";
            cin >> value;
            myStack.push(value);
            cout << "Елемент включений у стек." << endl;
            break;

        case 5:
            cout << "Вміст стеку: ";
            myStack.show();
            break;
        case 0:
            cout << "Програма завершена." << endl;
            break;
        default:
            cout << "Невірний вибір. Спробуйте ще раз." << endl;
            break;
        }

    } while (choice != 0);
}

template class Stack<int>;
template class Stack<double>;
template class Stack<string>;
template void processStack<int>();
template void processStack<double>();
template void processStack<string>();