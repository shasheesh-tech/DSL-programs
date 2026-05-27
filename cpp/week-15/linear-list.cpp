#include <iostream>
using namespace std;

class Node {
public:
    int key;
    string value;
    Node* next;

    Node(int k, string v) {
        key = k;
        value = v;
        next = NULL;
    }
};

class LinearDictionary {
    Node* head;

public:
    LinearDictionary() {
        head = NULL;
    }

    void insert(int k, string v) {
        Node* newNode = new Node(k, v);

        if(head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }

        cout << "Inserted: " << k << " -> " << v << endl;
    }

    void search(int k) {
        Node* temp = head;

        while(temp != NULL) {
            if(temp->key == k) {
                cout << "Found: " << temp->key << " -> " << temp->value << endl;
                return;
            }
            temp = temp->next;
        }

        cout << "Key not found" << endl;
    }

    void deleteKey(int k) {
        Node* temp = head;
        Node* prev = NULL;

        while(temp != NULL && temp->key != k) {
            prev = temp;
            temp = temp->next;
        }

        if(temp == NULL) {
            cout << "Key not found" << endl;
            return;
        }

        if(prev == NULL)
            head = temp->next;
        else
            prev->next = temp->next;

        delete temp;
        cout << "Deleted key " << k << endl;
    }

    void display() {
        Node* temp = head;
        cout << "\nDictionary:\n";
        while(temp != NULL) {
            cout << temp->key << " -> " << temp->value << endl;
            temp = temp->next;
        }
    }
};

int main() {
    LinearDictionary d;

    d.insert(101,"prabhu");
    d.insert(102,"kishan");
    d.insert(103,"head");

    d.display();

    d.search(102);
    d.deleteKey(102);

    d.display();
}