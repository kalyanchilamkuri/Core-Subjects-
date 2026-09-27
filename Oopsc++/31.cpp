#include <bits/stdc++.h>
using namespace std;

class shop {
    int id;
    float price;
public:
    void setData(int a, float b) {
        id = a;
        price = b;
    }

    void getData(void) {
        cout << "Code of this item is " << id << endl
             << "Price of this item is " << price << endl;
    }
};

int main() {
    int size = 3;
    shop* ptr = new shop[size];     // base pointer to array
    shop* ptrTemp = ptr;            // temp pointer to not lose original address

    int p, i;
    float q;

    // Input loop
    for (i = 0; i < size; i++) {
        cout << "Enter ID and price of item " << i + 1 << ": ";
        cin >> p >> q;
        ptrTemp->setData(p, q);
        ptrTemp++;
    }

    // Reset pointer to base address
    ptrTemp = ptr;

    // Output loop
    for (i = 0; i < size; i++) {
        cout << "Item number: " << i + 1 << endl;
        ptrTemp->getData();
        ptrTemp++;
    }

    delete[] ptr;  // free the dynamically allocated memory
    return 0;
}
