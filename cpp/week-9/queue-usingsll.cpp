#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Queue {
    Node* front;
    Node* rear;

    public:
    Queue() {
        front = rear = NULL;
    }

    void enqueue(int val) {
        Node* newNode = new Node(val);
        if(newNode == NULL) {
            cout << "Queue Overflow";
            return;
        } if(rear == NULL) {
              front = rear = newNode;
              cout << "Inserted successfully\n";
        } else {
        rear -> next = newNode;
        rear = rear -> next;
        cout << "Inserted successfully\n";
        }
    }

    void dequeue() {
        if(front == NULL) {
            cout << "Queue is Empty";
            return;
        }
        Node* temp = front;
        front = front -> next;
        
        cout << "Deleted " << temp -> data << " successfully\n";
        delete temp;
    }

    void display() {
        if(front == NULL) {
            cout << "Queue is Empty\n";
            return;
        }
        Node* temp = front;
        cout <<  "Queue elements:\n";
        while(temp != NULL) {
            cout << temp -> data << "->";
            temp = temp -> next;
        } cout << "NULL\n";
    }
};

int main() {
    Queue q;
    
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.dequeue();

    q.display();
}