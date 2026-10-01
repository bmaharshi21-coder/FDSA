#include <iostream>
using namespace std;

struct node
{
    int info;
    node *link;
};
node *head = NULL;

void insertend(int data)
{
    node *temp = new node;
    temp->info = data;
    temp->link = NULL;
    if (head == NULL)
    {
        head = temp;
        return;
    }
    node *save = head;
    while (save->link != NULL)
    {
        save = save->link;
    }
    save->link = temp;
}

void deletevalue(int data)
{
    if (head == NULL)
        return;
    if (head->info == data)
    {
        node *temp = head;
        head = head->link;
        delete temp;
        return;
    }
    node *save = head;
    while (save->link != NULL && save->link->info != data)
    {
        save = save->link;
    }
    if (save->link == NULL)
        return;
    node *temp = save->link;
    save->link = temp->link;
    delete temp;
}

void display()
{
    node *save = head;
    while (save != NULL)
    {
        cout << save->info << " ";
        save = save->link;
    }
    cout << endl;
}

void reverseprint(node *save)
{
    if (save == NULL)
        return;
    reverseprint(save->link);
    cout << save->info << " ";
}

int main()
{
    int n, data;
    cout << "Enter number of patients: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        insertend(data);
    }
    cout << "Queue: ";
    display();
    cout << "Enter token to delete: ";
    cin >> data;
    deletevalue(data);
    cout << "Queue after deletion: ";
    display();
    cout << "Reverse queue: ";
    reverseprint(head);
    return 0;
}