#include <iostream>
using namespace std;

struct Node {
    string page;
    Node *next;
};

Node *top = NULL;

void visit(string url) {
    Node *newNode = new Node;
    newNode->page = url;
    newNode->next = top;
    top = newNode;

    cout << "Current Page: " << top->page << endl;
}

void back() {
    if (top == NULL) {
        cout << "No pages in history."<<endl;
        return;
    }

    Node *temp = top;
    top = top->next;
    delete temp;

    if (top == NULL)
        cout << "No current page"<<endl;
    else
        cout << "Current Page: " << top->page << endl;
}

int main() {
    int choice;
    string url;

    while (true) {
        cout << "1. Visit Page"<<endl;
        cout << "2. Back"<<endl;
        cout << "3. Exit"<<endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter page name: ";
            cin >> url;
            visit(url);
        }
        else if (choice == 2) {
            back();
        }
        else if (choice == 3) {
            break;
        }
        else {
            cout << "Invalid choice"<<endl;
        }
    }

    return 0;
}