#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

class hashTable {
    private:
        int size;
        vector<list<pair<int, float>>> table; 
        vector<int> a;

    int hash(int key){
        int sum = 0;
        int n = 0;

        while (key > 0){
            int digit = key % 10;
            sum += a[n++] * digit;
            key /= 10;
        }
        return sum % size;
    }

    public:
        hashTable(int s){
        size = s;
        table.resize(size);
        a.resize(7);

        srand(time(NULL));

        for (int i = 0; i < 7; i++){
            a[i] = rand() % 7;
        }
    }

    void insert(int key, float value){
        int i = hash(key);
        auto& p = table[i];

        for (auto itr = p.begin(); itr != p.end(); itr++){
            if (itr->first == key) {
                itr->second = value;
                return;
            }
        }
        p.emplace_back(key, value);
    }

    float search(int key) {
        int i = hash(key);
        auto& p = table[i];

        for (auto itr = p.begin(); itr != p.end(); itr++) {
            if (itr->first == key) {
                return itr->second;
            }
        }
        return -1;
    }
};


int main() {
    hashTable hash1(7);

    hash1.insert(45, 2.13);
    hash1.insert(120, 18.9);

    cout << hash1.search(45) << endl;
    cout << hash1.search(120) << endl;

    return 0;
}