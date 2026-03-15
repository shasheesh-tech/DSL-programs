#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class CLL{

private:
    Node* head = NULL;

public:

    void insertBeginning(int value)
    {
        Node* newNode = new Node;
        newNode->data = value;

        if(head == NULL)
        {
            head = newNode;
            newNode->next = head;
            cout<<"List was empty. Inserted successfully\n";
            return;
        }

        Node* temp = head;

        while(temp->next != head)
        {
            temp = temp->next;
        }

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    void search(int key)
    {
        if(head == NULL)
        {
            cout<<"List is empty\n";
            return;
        }

        Node* temp = head;
        int pos = 1;

        do
        {
            if(temp->data == key)
            {
                cout<<"Element found at position "<<pos<<endl;
                return;
            }

            temp = temp->next;
            pos++;

        } while(temp != head);

        cout<<"Element not found\n";
    }

    void display()
    {
        if(head == NULL)
        {
            cout<<"List is empty\n";
            return;
        }

        Node* temp = head;

        do
        {
            cout<<temp->data<<" ";
            temp = temp->next;

        } while(temp != head);

        cout<<endl;
    }
};

int main()
{
    CLL cll;

    cll.insertBeginning(10);
    cll.insertBeginning(20);
    cll.insertBeginning(30);

    cll.display();

    cll.search(20);
}