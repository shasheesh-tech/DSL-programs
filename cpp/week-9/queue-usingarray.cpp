#include <iostream>
#include <queue>
using namespace std;
#define SIZE 5

class queue {
    private:
    int arr[SIZE];
    int front, rear;
    public:
    queue() {
        front = rear = -1;
    }

    void enqueue(int val) {
        if(rear == SIZE - 1) {
            cout << "Queue Overflow\n";
            return;
        }
        if(front == -1) {
            front = 0;
        }
         arr[++rear] = val;
         cout << "Inserted " << val << " Successfully\n";
    }

    void dequeue() {
        if(front == -1 || front > rear) {
            cout << "Queue underflow\n";
            return;
        } 
        cout << "Deleted element: " << arr[front++] << endl;
    }
    
    void display() {
        if(front == -1 || front > rear) {
            cout << "Queue underflow\n";
            return;
        } else {
            cout << "Queue elements: ";
            for(int i = front; i <= rear; ++i) {
                cout << arr[i] << " ";
            }
        }
    }
};

int main() {
    ::queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);

    q.dequeue();
    q.dequeue();

    q.display();
}