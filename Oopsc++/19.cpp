#include <bits/stdc++.h>
using namespace std;

// Key OOP Concepts Demonstrated
// Access Specifiers (private, public)
// Public Inheritance
// Encapsulation (private data accessed via getters/setters)
// Data hiding (data1 hidden from Derived)
// Function calls between base and derived classes

// Base class
class Base {
    int data1;  // private by default and not accessible in derived class
public:
    int data2;

    void setData(); //sets data1 and data2
    int getData1();
    int getData2();
};

// Definitions of Base member functions
void Base::setData() {
    data1 = 10;  // private so must be set inside base's function
    data2 = 20;
}

// getters for accessing private and public variables
int Base::getData1() {
    return data1;
}

int Base::getData2() {
    return data2;
}

// Derived class
// public members of base stay publicly in derived 
// protected stay protected
// private -> not sirectly accessible
class Derived : public Base {
    int data3;
public:
    void process();
    void display();
};

// Definitions of Derived member functions
void Derived::process() {
    data3 = data2 * getData1();  // data2 is public, getData1() returns private data1
}

void Derived::display() {
    cout << "Value of data1 is " << getData1() << endl;
    cout << "Value of data2 is " << data2 << endl;
    cout << "Value of data3 is " << data3 << endl;
}

// main function
int main() {
    Derived der;
    der.setData();     // sets data1 and data2
    der.process();     // calculates data3 = data2 * data1
    der.display();     // prints all values
    return 0;
}


// *)If you remove getData1() and still want Derived to use data1, what are the possible ways to do it?
// Make data1 protected in Base:
// protected: int data1;
// → Then Derived can directly access it.

// *)Make Derived a friend of Base:
// friend class Derived;
// → Gives full access to private members.




