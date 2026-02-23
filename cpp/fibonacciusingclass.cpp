#include <iostream>
using namespace std;

class Fibonacci {
    int n;
public:
    Fibonacci(int num) {
        n = num; // Assign value to member variable
    }

    void printSeries() {
        int a = 0, b = 1;
        cout << "Fibonacci series: ";
        for (int i = 0; i < n; ++i) {
            cout << a << " ";
            int next = a + b;
            a = b;
            b = next;
        }
        cout << endl;
    }
};

int main() {
    int num;
    cout << "Enter the number of terms: ";
    cin >> num;
    Fibonacci fib(num);
    fib.printSeries();
    return 0;
}