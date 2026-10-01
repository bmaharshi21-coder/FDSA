#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter stack size: ";
    cin >> n;

    int stack[100];
    int top = -1;

    int choice, value;

    while (true) {
        cout << "1. Place Tray"<<endl;
        cout << "2. Take Tray "<<endl;
        cout << "3. Exit"<<endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter tray number: ";
            cin >> value;

            if (top == n - 1) {
                cout << " Counter is full."<<endl;
            } else {
                top++;
                stack[top] = value;
                cout << "Top Tray = " << stack[top] << endl;
            }
        }
        else if (choice == 2) {
            if (top == -1) {
                cout << "Counter is empty."<<endl;
            } else {
                top--;
                if (top == -1)
                    cout << "Stack is  empty."<<endl;
                else
                    cout << "Top Tray = " << stack[top] << endl;
            }
        }
        else if (choice == 3) {
            break;
        }
        else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}