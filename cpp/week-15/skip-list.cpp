#include <iostream>
#include <cstdlib>
using namespace std;

const int MAXLVL = 3;
const float P = 0.5;

class Node {
public:
    int key;
    string value;
    Node** forward;

    Node(int k, string v, int level) {
        key = k;
        value = v;
        forward = new Node*[level + 1];
        for(int i = 0; i <= level; i++)
            forward[i] = NULL;
    }
};

class SkipList {
    int level;
    Node* header;

public:
    SkipList() {
        level = 0;
        header = new Node(-1, "", MAXLVL);
    }

    int randomLevel() {
        int lvl = 0;
        while((float)rand()/RAND_MAX < P && lvl < MAXLVL)
            lvl++;
        return lvl;
    }

    void insert(int key, string value) {
        Node* update[MAXLVL+1];
        Node* current = header;

        for(int i = level; i >= 0; i--) {
            while(current->forward[i] != NULL && current->forward[i]->key < key)
                current = current->forward[i];
            update[i] = current;
        }

        current = current->forward[0];

        if(current == NULL || current->key != key) {
            int rlevel = randomLevel();

            if(rlevel > level) {
                for(int i = level+1; i <= rlevel; i++)
                    update[i] = header;
                level = rlevel;
            }

            Node* n = new Node(key, value, rlevel);

            for(int i = 0; i <= rlevel; i++) {
                n->forward[i] = update[i]->forward[i];
                update[i]->forward[i] = n;
            }

            cout << "Inserted: " << key << " -> " << value << endl;
        }
    }

    void search(int key) {
        Node* current = header;

        for(int i = level; i >= 0; i--) {
            while(current->forward[i] && current->forward[i]->key < key)
                current = current->forward[i];
        }

        current = current->forward[0];

        if(current && current->key == key)
            cout << "Found: " << current->key << " -> " << current->value << endl;
        else
            cout << "Key not found" << endl;
    }

    void deleteKey(int key) {
        Node* update[MAXLVL+1];
        Node* current = header;

        for(int i = level; i >= 0; i--) {
            while(current->forward[i] && current->forward[i]->key < key)
                current = current->forward[i];
            update[i] = current;
        }

        current = current->forward[0];

        if(current && current->key == key) {
            for(int i = 0; i <= level; i++) {
                if(update[i]->forward[i] != current)
                    break;
                update[i]->forward[i] = current->forward[i];
            }

            while(level > 0 && header->forward[level] == NULL)
                level--;

            delete current;
            cout << "Deleted key " << key << endl;
        }
        else
            cout << "Key not found" << endl;
    }

    void display() {
        cout << "\nSkip List Level 0:\n";
        Node* node = header->forward[0];
        while(node != NULL) {
            cout << node->key << " -> " << node->value << endl;
            node = node->forward[0];
        }
    }
};

int main() {
    SkipList s;

    s.insert(101,"shasheesh");
    s.insert(102,"narendar");
    s.insert(103,"satyarth");

    s.display();

    s.search(102);
    s.deleteKey(102);

    s.display();
}