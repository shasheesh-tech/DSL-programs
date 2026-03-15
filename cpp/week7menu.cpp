#include <iostream>
using namespace std;

#define size 5
class Stack {
    int st[size];
    int top;

public:
    Stack(){
        top = -1;
    }

    bool isFull(){
        return top == size - 1;
    }

    bool isEmpty(){
        return top == -1;
    }

    void push(int value){
        if (isFull()){
            cout << "Stack overflow\n";
            return;
        }
        top++;
        st[top] = value;
        cout << value << " pushed\n";
    }

    void pop() {
        if (isEmpty()){
            cout << "Stack Underflow\n";
            return;
        }
        cout << st[top] << " popped\n";
        top--;
    }

    void peek(){
        if (isEmpty()){
            cout << "Stack is Empty\n";
            return;
        }
        cout<<"Top element: "<<st[top]<<endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return;
        }

        cout << "Stack elements are:\n";
        for (int i = top; i >= 0; i--) {
            cout<<st[i]<< " ";
        }
        cout<<endl;
    }
};

int main() {
    Stack s;
    int choice, value;

    while (1) {
        cout << "\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice){
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
            return 0;
        default:
            cout << "Invalid Choice\n";
        }
    }
}