#include <iostream>
#include <list>
#include <vector>
#include <cmath>

using namespace std;

class HashTable {
private:
    int capacity;          //key 
    std::vector<int> table;
    int size; 
    int max;
    double load_factor=0.8;    //size 

    // Hash function to map values to key
    int hashFunction(int key) {
        return key % capacity;
    }

public:
    // Constructor
     HashTable(int size) : capacity(size), table(size,-1), size(0){
        max=capacity/2;

     }

    // Insert a key into the hash table
    void insert(int value) {
        int i=0;
        int key;
        if ((size%capacity)>0.8){
            resize();
        }

        while (i<max){
            key= (hashFunction(value)+i * i)%capacity;
           if (table[key]==-1){
              table[key]=value;
              size++;
              return;
            }
            else if (table[key]==value){
                cout << "Duplicate key insertion is not allowed" << endl;
                return;
            }
            i++;

        }
        cout << "Max probing limit reached!" << endl;
        return;


    }

    // Remove a key from the hash table
    void remove(int value) {
        int key;
        int i=0;
        while ( i < max){
            key= (hashFunction(value)+i * i)%capacity;
            if (table[key]==-1){
                cout << "Element not found" << endl;
                return;
            }
            if (table[key]==value){
                table[key]=-1;
                size--;
                return;
            }
            i++;
        }
        cout << "Element not found" << endl;
        return;


        
    }

    // Search for a key in the hash table
    bool search(int value){
        int i=0;
        int key;
        while (i<max){
            key= (hashFunction(value)+i * i)%capacity;
            if (table[key]==-1){
                return -1; 
            }
            if (table[key]==value){
                return key;
            }
            i++;



        }
        return -1;

    }
    
    void resize() {
        std::vector<int> old_table = table;
        int new_capacity = next_prime(capacity * 2);
        std::vector<int> new_table(new_capacity, -1);
        table = new_table;  // Update table to new resized one
        capacity = new_capacity;
        size = 0;  // Reset size and reinsert elements

        for (int value : old_table) {
            if (value != -1) {
                insert(value);
            }
        }
        return;
    }
        
    bool is_prime(int num){
        if (num<=1){
            return false;
        }
        for (int i=2; i<=sqrt(num); i++){
            if (num%i==0){
               return false;
            }
        }
        return true;

    }

    int next_prime(int n){
        while (is_prime(n)==false){
            n+=1;

        }
        return n;

    }

    // Print the hash table
    void printTable() {
        for (int i = 0; i < capacity; i++) {
            if (table[i]==-1){
                cout << "-" << " ";
            }
            else{
                 cout << "table[i]" << " ";
            }
            return;
        }
    }
};
