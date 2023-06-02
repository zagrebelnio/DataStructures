#include "stack.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    try {
        
        stack<int> myStack;
        stack<int>::iterator it = myStack.begin();
        
        int choice, value;

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
                for (stack<int>::iterator it = myStack.begin(); it != myStack.end(); ++it) {
                    cout << *it << " ";
                }
                cout << endl;
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
    catch (const exception& e) {
        cout << "Сталася помилка: " << e.what() << endl;
    }
    catch (const char* s) {
        cout << "Сталася помилка: " << s << endl;
    }
    return 0; 
}