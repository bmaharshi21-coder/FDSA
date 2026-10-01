#include <iostream>
using namespace std;
struct SNode {
    string name;
    SNode* next;
    SNode(string n) {
        name = n;
        next = NULL;
    }
};
class SinglyCircular {
    SNode* head;
public:
    SinglyCircular() {
        head = NULL;
    }
    void join(string name, int pos) {
        SNode* newNode = new SNode(name);
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            return;
        }
        if (pos == 1) {
            SNode* temp = head;

            while (temp->next != head) {
                temp = temp->next;
            }
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
            return;
        }
        SNode* temp = head;
        for (int i = 1; i < pos - 1 && temp->next != head; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    void leave(string name) {
        if (head == NULL)
            return;
        if (head->name == name) {
            if (head->next == head) {
                delete head;
                head = NULL;
                return;
            }
            SNode* last = head;
            while (last->next != head) {
                last = last->next;
            }
            SNode* temp = head;
            head = head->next;
            last->next = head;
            delete temp;
            return;
        }
        SNode* temp = head;
        while (temp->next != head && temp->next->name != name) {
            temp = temp->next;
        }
        if (temp->next != head) {
            SNode* del = temp->next;
            temp->next = del->next;
            delete del;
        }
    }
    void display() {
        if (head == NULL) {
            cout << "Empty";
            return;
        }
        SNode* temp = head;
        do {
            cout << temp->name << "->";
            temp = temp->next;
        } while (temp != head);
    }
};
struct DNode {
    string name;
    DNode* next;
    DNode* prev;
    DNode(string n) {
        name = n;
        next = NULL;
        prev = NULL;
    }
};
class DoublyCircular {
    DNode* head;
public:
    DoublyCircular() {
        head = NULL;
    }
    void join(string name, int pos) {
        DNode* newNode = new DNode(name);
        if (head == NULL) {
            head = newNode;
            head->next = head;
            head->prev = head;
            return;
        }
        if (pos == 1) {
            DNode* last = head->prev;
            newNode->next = head;
            newNode->prev = last;
            last->next = newNode;
            head->prev = newNode;
            head = newNode;
            return;
        }
        DNode* temp = head;
        for (int i = 1; i < pos - 1 && temp->next != head; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }
    void leave(string name) {
        if (head == NULL)
            return;
        DNode* temp = head;
        do {
            if (temp->name == name)
                break;
            temp = temp->next;
        } while (temp != head);
        if (temp->name != name)
            return;
        if (temp->next == temp) {
            delete temp;
            head = NULL;
            return;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        if (temp == head) {
            head = temp->next;
        }
        delete temp;
    }
    void display() {
        if (head == NULL) {
            cout << "Empty";
            return;
        }
        DNode* temp = head;
        do {
            cout << temp->name << "<->";
            temp = temp->next;
        } while (temp != head);
    }
};
int main() {
    SinglyCircular s;
    DoublyCircular d;
    int choice;
    do {
        cout << "\n1. Join Student"<<endl;
        cout << "2. Leave Student"<<endl;
        cout << "3. Display Circle"<<endl;
        cout << "4. Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1) {
            string name;
            int position;
            cout << "Enter student name: ";
            cin >> name;
            cout << "Enter position: ";
            cin >> position;
            s.join(name, position);
            d.join(name, position);
            cout << "\nSingly Circular: "<<endl;
            s.display();
            cout << "\nDoubly Circular: "<<endl;
            d.display();
        }
        else if (choice == 2) {
            string name;
            cout << "Enter student name: ";
            cin >> name;
            s.leave(name);
            d.leave(name);
            cout << "\nSingly Circular: "<<endl;
            s.display();
            cout << "\nDoubly Circular: "<<endl;
            d.display();
        }
        else if (choice == 3) {
            cout << "\nSingly Circular: "<<endl;
            s.display();
            cout << "\nDoubly Circular: "<<endl;
            d.display();
        }
        else if (choice == 4) {
            cout << "\nProgram ended."<<endl;
        }
        else {
            cout << "\nInvalid choice."<<endl;
        }
    } while (choice != 4);
    return 0;
}