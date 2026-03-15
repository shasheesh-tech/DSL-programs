#include <iostream>
using namespace std;
#define size 5
class Stack {
    int st[size];
    int top;
public:
    Stack(){
        top=-1;
    }
    bool isFull() {
        return top == size - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }
        st[++top] = value;
        cout << value << " pushed\n";
    }
    void pop(){
        if (isEmpty()){
            cout << "Stack Underflow\n";
            return;
     }
        cout<<st[top--] <<" popped\n";
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return;
        }
        cout << "Top element: " << st[top] << endl;
    }
    void display(){
        cout<<"stack elements are :\n";
         if(isEmpty()){
        cout<<"Stack is Empty\n";
        return;
    }
    for(int i = top; i >= 0; i--){
        cout << st[i] << " ";
    }
    cout << endl;
    }
};

int main() {
int op;
 Stack s;


cout << "1.Push"<<endl<< "2.Pop"<<endl<< "3.Peek"<<endl<< "4.isFull"<<endl<< "5.isEmpty"<<endl<< "6.Display"<<endl<< "7.Exit"<<endl;
cin >> op;

    if (s.isEmpty())
        cout << "Stack is Empty\n";

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    s.peek();


    if (s.isFull())
        cout << "Stack is Full\n";
    else
        cout << "Stack is Not Full\n";

    s.pop();
        s.display();

}
