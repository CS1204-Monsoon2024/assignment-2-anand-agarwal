#include <iostream>
#include <list>
using namespace std;

class HashTable {
private:
    int capacity;          // Number of buckets
    list<int> *table;      // Pointer to the array of lists (chaining for collision handling)

    // Hash function to map values to key
    int hashFunction(int key) {
        return key % capacity;
    }

public:
    // Constructor
    HashTable(int size) {
        capacity = size;
        table = new list<int>[capacity];
    }

    // Insert a key into the hash table
    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
        return;

    }

    // Remove a key from the hash table
    void remove(int key) {
        int index = hashFunction(key);
        auto it = table[index].begin();
        while (it != table[index].end()) {
            if (*it == key) {
                it = table[index].erase(it);
                cout << "Removed " << key << " from index " << index << endl;
                return;
            } else {
                ++it;
            }
        }
    }

    // Search for a key in the hash table
    bool search(int key) {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (*it == key) {
                cout << "Key " << key << " found at index " << index << endl;
                return true;
            }
        }
        cout << "Key " << key << " not found" << endl;
        return false;
    }

    // Print the hash table
    void printTable() {
        for (int i = 0; i < capacity; i++) {
            cout << "Bucket " << i << ": ";
            for (auto x : table[i])
                cout << x << " ";
            cout << endl;
        }
    }

    // Destructor to free up memory
    ~HashTable() {
        delete[] table;
    }
};
