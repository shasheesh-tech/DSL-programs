#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

// Stack class
class Stack {
private:
    Node* top;   // acts as head

public:
    // Constructor
    Stack() {
        top = NULL;
    }

    // Push operation
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;

        cout << "Pushed successfully!\n";
    }

    // Pop operation
    void pop() {
        if (top == NULL) {
            cout << "Stack Underflow!\n";
            return;
        }

        Node* temp = top;
        cout << "Popped element: " << temp->data << endl;

        top = top->next;
        delete temp;
    }

    // Peek operation
    void peek() {
        if (top == NULL) {
            cout << "Stack is empty!\n";
        } else {
            cout << "Top element: " << top->data << endl;
        }
    }

    // Display stack
    void display() {
        if (top == NULL) {
            cout << "Stack is empty!\n";
            return;
        }

        Node* temp = top;
        cout << "Stack elements:\n";

        while (temp != NULL) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};

// Main function
int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\n--- STACK MENU ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                s.push(value);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                s.peek();
                break;

            case 4:
                s.display();
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}