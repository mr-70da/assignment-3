#include <iostream>
#include <vector>
using namespace std;

template<typename X>
class Set {
private:
    vector<X> items;

public:
    Set() {}

    void add(X element) {
        for (int i = 0; i < items.size(); i++) {
            if (items[i] == element) {
                cout << "Item already exists in the set." << endl;
                return;
            }
        }
        items.push_back(element);
    }

    void remove(X element) {
        for (auto it = items.begin(); it != items.end(); ++it) {
            if (*it == element) {
                items.erase(it);
                return;
            }
        }
    }

    int size() {
        return items.size();
    }

    bool ifexist(X element) {
        for (int i = 0; i < items.size(); i++) {
            if (items[i] == element) {
                return true;
            }
        }
        return false;
    }

    X* ptr() {
        X* array = new X[items.size()];
        for (int i = 0; i < items.size(); i++) {
            array[i] = items[i];
        }
        return array;
    }
};

int main() {
    Set<int> p;
    p.add(5);
    p.add(6);
    p.add(7);
    p.remove(6);
    cout << "Does 6 exist in the set? " << p.ifexist(6) << endl;
    cout << "Does 5 exist in the set? " << p.ifexist(5) << endl;
    cout << "Size of set: " << p.size() << endl;

    int* array = p.ptr();
    for (int i = 0; i < p.size(); ++i) {
        cout << array[i] << " ";
    }
    delete[] array;

    return 0;
}