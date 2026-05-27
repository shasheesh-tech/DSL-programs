#include <iostream>
using namespace std;

const int SIZE = 10;

class LinearProbing {
    int table[SIZE];

public:
    LinearProbing() {
        for(int i=0;i<SIZE;i++)
            table[i] = -1;
    }

    int hashFunction(int key) {
        return key % SIZE;
    }

    void insert(int key) {
        int index = hashFunction(key);
        int start = index;

        while(table[index] != -1) {
            index = (index + 1) % SIZE;
            if(index == start) {
                cout << "Table Full\n";
                return;
            }
        }

        table[index] = key;
        cout << key << " inserted at " << index << endl;
    }

    void search(int key) {
        int index = hashFunction(key);
        int start = index;

        while(table[index] != -1) {
            if(table[index] == key) {
                cout << key << " Found at " << index << endl;
                return;
            }
            index = (index + 1) % SIZE;
            if(index == start) break;
        }
        cout << key << " Not Found\n";
    }

    void deleteKey(int key) {
        int index = hashFunction(key);
        int start = index;

        while(table[index] != -1) {
            if(table[index] == key) {
                table[index] = -2;
                cout << key << " Deleted\n";
                return;
            }
            index = (index + 1) % SIZE;
            if(index == start) break;
        }
        cout << key << " Not Found\n";
    }

    void display() {
        for(int i=0;i<SIZE;i++)
            cout << i << " : " << table[i] << endl;
    }
};

int main() {
    LinearProbing h;
    h.insert(25);
    h.insert(15);
    h.insert(35);
    h.insert(36);

    h.display();
}