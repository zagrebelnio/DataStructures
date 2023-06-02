#include "stack.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    try {
        
        int dataType;
        cout << "Введіть тип даних стеку (1. int, 2. double, 3. string): ";
        cin >> dataType;
        
        switch (dataType) {
        case 1:
            processStack<int>();
            break;
        case 2:
            processStack<double>();
            break;
        case 3:
            processStack<string>();
            break;
        default:
            cout << "Введено некоректне значення." << endl;
            break;
        }
    }
    catch (const exception& e) {
        cout << "Сталася помилка: " << e.what() << endl;
    }
    catch (const char* s) {
        cout << "Сталася помилка: " << s << endl;
    }
    return 0; 
}