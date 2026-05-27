#include <iostream>
using namespace std;

const int SIZE = 10;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class SeparateChaining {
    Node* table[SIZE];

public:
    SeparateChaining() {
        for(int i = 0; i < SIZE; i++)
            table[i] = NULL;
    }

    int hashFunction(int key) {
        return key % SIZE;
    }

    void insert(int key) {
        int index = hashFunction(key);
        Node* newNode = new Node(key);

        if(table[index] == NULL) {
            table[index] = newNode;
        }
        else {
            Node* temp = table[index];
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }

        cout << key << " inserted at index " << index << endl;
    }

    void search(int key) {
        int index = hashFunction(key);
        Node* temp = table[index];

        while(temp != NULL) {
            if(temp->data == key) {
                cout << key << " Found at index " << index << endl;
                return;
            }
            temp = temp->next;
        }

        cout << key << " Not Found" << endl;
    }

    void deleteKey(int key) {
        int index = hashFunction(key);
        Node* temp = table[index];
        Node* prev = NULL;

        while(temp != NULL && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        if(temp == NULL) {
            cout << key << " Not Found" << endl;
            return;
        }

        if(prev == NULL)
            table[index] = temp->next;
        else
            prev->next = temp->next;

        delete temp;

        cout << key << " Deleted from index " << index << endl;
    }

    void display() {
        cout << "\nHash Table:\n";
        for(int i = 0; i < SIZE; i++) {
            cout << i << " -> ";
            Node* temp = table[i];

            while(temp != NULL) {
                cout << temp->data << " -> ";
                temp = temp->next;
            }

            cout << "NULL" << endl;
        }
    }
};

int main() {
    SeparateChaining h;

    h.insert(25);
    h.insert(15);
    h.insert(35);
    h.insert(36);

    h.display();

    h.search(15);
    h.deleteKey(15);

    h.display();
}