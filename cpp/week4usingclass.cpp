#include <iostream>
using namespace std;


// struct Node {
//     int data;
//     Node* next;
// };
class Node{
    public:
int data;
Node* next;
Node(int value){
    data=value;
next=NULL;
}
};
class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = NULL;
    }
    void insertBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        cout << "Inserted at Beginning Successfully\n";
    }
    void insertEnd(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            cout << "List was empty. Node inserted as first node.\n";
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        cout << "Inserted at End Successfully\n";
    }

    void insertAtPosition(int value, int pos) {
        if (pos == 1) {
            insertBeginning(value);
            return;
        }

        Node* newNode = new Node(value);

        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Invalid Position\n";
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Inserted at Position " << pos << " Successfully\n";
    }

    void deleteBeginning() {
        if (head == NULL) {
            cout << "List is Empty\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Deleted from Beginning Successfully\n";
    }

    void deleteEnd() {
        if (head == NULL) {
            cout << "List is Empty\n";
            return;
        }

        if (head->next == NULL) {
            delete head;
            head = NULL;
            cout << "Last node deleted. List is now empty.\n";
            return;
        }

        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
        cout << "Deleted from End Successfully\n";
    }

    void deleteAtPosition(int pos) {
        if (head == NULL) {
            cout << "List is Empty\n";
            return;
        }

        if (pos == 1) {
            deleteBeginning();
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp->next != NULL; i++) {
            temp = temp->next;
        }

        if (temp->next == NULL) {
            cout << "Invalid Position\n";
            return;
        }

        Node* delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
        cout << "Deleted from Position " << pos << " Successfully\n";
    }

    void search(int key) {
        Node* temp = head;
        int position = 1;

        while (temp != NULL) {
            if (temp->data == key) {
                cout << "Element found at position: " << position << endl;
                return;
            }
            temp = temp->next;
            position++;
        }

        cout << "Element not found in the list\n";
    }
    void display() {
        if (head == NULL) {
            cout << "List is Empty\n";
            return;
        }

        Node* temp = head;
        cout << "Linked List: ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    SinglyLinkedList list;
    int choice, value, pos;

    do {
        cout << "\n===== SINGLY LINKED LIST ADT MENU =====\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete at Position\n";
        cout << "7. Search Element\n";
        cout << "8. Display List\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.insertBeginning(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                list.insertEnd(value);
                break;

            case 3:
                cout << "Enter value and position: ";
                cin >> value >> pos;
                list.insertAtPosition(value, pos);
                break;

            case 4:
                list.deleteBeginning();
                break;

            case 5:
                list.deleteEnd();
                break;

            case 6:
                cout << "Enter position: ";
                cin >> pos;
                list.deleteAtPosition(pos);
                break;

            case 7:
                cout << "Enter element to search: ";
                cin >> value;
                list.search(value);
                break;

            case 8:
                list.display();
                break;

            case 9:
                cout << "Exiting Program...\n";
                break;

            default:
                cout << "Invalid Choice! Try Again.\n";
        }

    } while (choice != 9);

    return 0;
}