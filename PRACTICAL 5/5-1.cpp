#include <iostream>
using namespace std;

struct Node
{
    string song;
    Node *prev;
    Node *next;

    Node(string s)
    {
        song = s;
        prev = NULL;
        next = NULL;
    }
};

class Playlist
{
    Node *head;

public:
    Playlist()
    {
        head = NULL;
    }

    void addBeginning(string s)
    {
        Node *newNode = new Node(s);

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

   
    void addEnd(string s)
    {
        Node *newNode = new Node(s);

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    
    void insertAfter(string key, string s)
    {
        if (head == NULL)
        {
            cout << "Playlist is Empty."<<endl;
            return;
        }

        Node *temp = head;

        while (temp != NULL && temp->song != key)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "Song not found!"<<endl;
            return;
        }

        Node *newNode = new Node(s);

        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL)
        {
            temp->next->prev = newNode;
        }

        temp->next = newNode;

        cout << "Song inserted successfully."<<endl;
    }

  
    void deleteFirst()
    {
        if (head == NULL)
        {
            cout << "Playlist is Empty."<<endl;
            return;
        }

        Node *temp = head;

        cout << "Deleted Song: " << temp->song << endl;

        head = head->next;

        if (head != NULL)
        {
            head->prev = NULL;
        }

        delete temp;
    }

    
    void countSongs()
    {
        int count = 0;
        Node *temp = head;

        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }

        cout << "Total Songs = " << count << endl;
    }

  
    void display()
    {
        if (head == NULL)
        {
            cout << "Playlist is Empty."<<endl;
            return;
        }

        Node *temp = head;

        cout << "Playlist : ";

        while (temp != NULL)
        {
            cout << temp->song;

            if (temp->next != NULL)
            {
                cout << " -> ";
            }

            temp = temp->next;
        }

        cout << endl;
    }
};

int main()
{
    Playlist p;

    int choice;
    string song, key;

    do
    {
        cout << "\n====== MUSIC PLAYLIST ======\n";
        cout << "1. Add Song at Beginning"<<endl;
        cout << "2. Add Song at End"<<endl;
        cout << "3. Insert Song After Given Song"<<endl;
        cout << "4. Delete First Song"<<endl;
        cout << "5. Count Songs"<<endl;
        cout << "6. Display Playlist"<<endl;
        cout << "7. Exit"<<endl;
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Song Name: ";
            cin >> song;
            p.addBeginning(song);
            p.display();
            break;

        case 2:
            cout << "Enter Song Name: ";
            cin >> song;
            p.addEnd(song);
            p.display();
            break;

        case 3:
            cout << "Enter Existing Song: ";
            cin >> key;
            cout << "Enter New Song: ";
            cin >> song;
            p.insertAfter(key, song);
            p.display();
            break;

        case 4:
            p.deleteFirst();
            p.display();
            break;

        case 5:
            p.countSongs();
            break;

        case 6:
            p.display();
            break;

        case 7:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 7);

    return 0;
}