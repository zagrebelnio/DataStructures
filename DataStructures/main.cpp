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
            cout << "1. �������� ����� �� �������" << endl;
            cout << "2. �������� �����" << endl;
            cout << "3. ��������� �������� � ������� �����" << endl;
            cout << "4. ��������� ������ �������� � ����" << endl;
            cout << "5. ��������� ����� �����" << endl;
            cout << "0. �����" << endl;
            cout << "��� ����: ";
            cin >> choice;
            cout << "--------------------------------------" << endl;

            switch (choice) {
            case 1:
                if (myStack.empty()) {
                    cout << "���� �������." << endl;
                }
                else {
                    cout << "���� �� �������." << endl;
                }
                break;

            case 2:
                myStack.clear();
                cout << "���� ��������." << endl;
                break;

            case 3:
                myStack.pop();
                cout << "������� ��������� � ������� �����." << endl;
                break;

            case 4:
                cout << "������ �������� ������ ��������: ";
                cin >> value;
                myStack.push(value);
                cout << "������� ��������� � ����." << endl;
                break;

            case 5:
                cout << "���� �����: ";
                for (stack<int>::iterator it = myStack.begin(); it != myStack.end(); ++it) {
                    cout << *it << " ";
                }
                cout << endl;
                break;
            case 0:
                cout << "�������� ���������." << endl;
                break;
            default:
                cout << "������� ����. ��������� �� ���." << endl;
                break;
            }

        } while (choice != 0);
    }
    catch (const exception& e) {
        cout << "������� �������: " << e.what() << endl;
    }
    catch (const char* s) {
        cout << "������� �������: " << s << endl;
    }
    return 0; 
}