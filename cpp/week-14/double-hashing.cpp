#include <iostream>
using namespace std;

const int SIZE = 10;

class DoubleHashing {
    int table[SIZE];

public:
    DoubleHashing() {
        for(int i = 0; i < SIZE; i++)
            table[i] = -1;
    }

    int h1(int key) {
        return key % SIZE;
    }

    int h2(int key) {
        return 7 - (key % 7);
    }

    void insert(int key) {
        int index = h1(key);
        int step = h2(key);
        int i = 0;

        while(table[(index + i * step) % SIZE] != -1 && table[(index + i * step) % SIZE] != -2)
            i++;

        int pos = (index + i * step) % SIZE;
        table[pos] = key;

        cout << key << " inserted at index " << pos << endl;
    }

    void search(int key) {
        int index = h1(key);
        int step = h2(key);
        int i = 0;

        while(table[(index + i * step) % SIZE] != -1 && i < SIZE) {
            int pos = (index + i * step) % SIZE;

            if(table[pos] == key) {
                cout << key << " Found at index " << pos << endl;
                return;
            }
            i++;
        }

        cout << key << " Not Found" << endl;
    }

    void deleteKey(int key) {
        int index = h1(key);
        int step = h2(key);
        int i = 0;

        while(table[(index + i * step) % SIZE] != -1 && i < SIZE) {
            int pos = (index + i * step) % SIZE;

            if(table[pos] == key) {
                table[pos] = -2;
                cout << key << " Deleted from index " << pos << endl;
                return;
            }
            i++;
        }

        cout << key << " Not Found" << endl;
    }

    void display() {
        cout << "\nHash Table:\n";
        for(int i = 0; i < SIZE; i++)
            cout << i << " : " << table[i] << endl;
    }
};

int main() {
    DoubleHashing h;

    h.insert(25);
    h.insert(15);
    h.insert(35);
    h.insert(36);

    h.display();

    h.search(15);
    h.deleteKey(15);

    h.display();
}