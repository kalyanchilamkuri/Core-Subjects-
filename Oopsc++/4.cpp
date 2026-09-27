
// c++ objects memory allocation and using arrays in classes

#include <bits/stdc++.h>
using namespace std;

class Shop {
    int itemId[100];
    int itemPrice[100];
    int counter;// to track how many items have beed added
public:
    void initCounter(void) {   // function to set the counter to 0
        counter = 0;     
    }

    void setPrice(void);     // Declare function input ids and price for a new item
    void displayPrice(void); // Declare function used to display
};

// Define setPrice() function
void Shop::setPrice(void) {
    cout << "Enter Id of your Item: ";
    cin >> itemId[counter];
    cout << "Enter Price of your Item: ";
    cin >> itemPrice[counter];
    counter++;
}

// Define displayPrice() function
void Shop::displayPrice(void) {
    for (int i = 0; i < counter; i++) {
        cout << "The Price of item with Id " << itemId[i] << " is " << itemPrice[i] << endl;
    }
}

int main() {
    Shop dukaan;
    dukaan.initCounter();    // Must initialize counter to 0 before using

    dukaan.setPrice();       // 1st item
    dukaan.setPrice();       // 2nd item
    dukaan.setPrice();       // 3rd item

    dukaan.displayPrice();   // Show all items

    return 0;
}





// if we use constructor instead of initCounter().


#include <bits/stdc++.h>
using namespace std;

class Shop {
    int itemId[100];
    int itemPrice[100];
    int counter;

public:
    // Constructor automatically initializes counter to 0
    Shop() {
        counter = 0;
    }

    void setPrice();      // Declare function
    void displayPrice();  // Declare function
};

// Define setPrice() function
void Shop::setPrice() {
    cout << "Enter Id of your Item: ";
    cin >> itemId[counter];

    cout << "Enter Price of your Item: ";
    cin >> itemPrice[counter];

    counter++;
}

// Define displayPrice() function
void Shop::displayPrice() {
    for (int i = 0; i < counter; i++) {
        cout << "The Price of item with Id " << itemId[i]
             << " is " << itemPrice[i] << endl;
    }
}

int main() {
    Shop dukaan;            // Constructor is called automatically here

    dukaan.setPrice();      // Add 1st item
    dukaan.setPrice();      // Add 2nd item
    dukaan.setPrice();      // Add 3rd item

    dukaan.displayPrice();  // Show all items

    return 0;
}
