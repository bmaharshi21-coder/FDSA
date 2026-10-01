#include <iostream>
using namespace std;
struct node
{
    int info;
    node *link;
};

node *head = NULL;

void insertfront(int data)
{
    node *temp = new node;
    temp->info = data;
    temp->link = head;
    head = temp;
}

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

void insertpos(int data, int pos)
{
    if (pos == 1)
    {
        insertfront(data);
        return;
    }

    node *save = head;

    for (int i = 1; i < pos - 1 && save != NULL; i++)
    {
        save = save->link;
    }

    if (save == NULL)
    {
        cout << "Invalid position" << endl;
        return;
    }

    node *temp = new node;
    temp->info = data;
    temp->link = save->link;
    save->link = temp;
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

int main()
{
    int data, pos;

    cout << "Enter critical patient token: ";
    cin >> data;
    insertfront(data);
    display();

    cout << "Enter routine patient token: ";
    cin >> data;
    insertend(data);
    display();

    cout << "Enter priority patient token: ";
    cin >> data;

    cout << "Enter position: ";
    cin >> pos;

    insertpos(data, pos);
    display();

    return 0;
}