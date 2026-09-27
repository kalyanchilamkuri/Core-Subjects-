// Constructor overloading 

// constructor overloading means writing multiple constructors in the same class , each having a different number or type of parameters
// the compiler chooses the right constructor based on the arguements you provide during object creation

// *)we can’t overload constructors with the same parameter list. That causes a compiler error.
// *)constructor must differ by number of paremeters or type of parameters or order of parameters5

#include <bits/stdc++.h>
using namespace std;

class Complex {
    int a, b;

public:
    // Constructor with two parameters
    Complex(int x, int y) {
        a = x;
        b = y;
    }

    // Constructor with one parameter
    Complex(int x) {
        a = x;
        b = 0;
    }

    // Default constructor
    Complex() {
        a = 0;
        b = 0;
    }

    void printNumber() {
        cout << "Your Number is " << a << " + " << b << " i " << endl;
    }
};

int main() {
    Complex c1(4, 6);  // Calls constructor with 2 parameters
    c1.printNumber();  // Output: 4 + 6i

    Complex c2(5);     // Calls constructor with 1 parameter
    c2.printNumber();  // Output: 5 + 0i

    Complex c3;        // Calls default constructor
    c3.printNumber();  // Output: 0 + 0i

    return 0;
}


