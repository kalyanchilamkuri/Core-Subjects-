// ------------------------------------polymorphism------------------------------------------------

// polymorphism => one name multiple forms
// the same function name or operator behaves differently depending on the context or object. 

// example

// -> for a circle => draw means draw a circle 
// -> for a square => draw means draw a square
// -> for a triangle => draw means draw a triangle

// compiler-time polymorphism  ===   static/Early binding  ===  function overloading and operator overloading  ===  compile time 
// run-time polymorphism  ===  dynamic/late binding ===  virtual functions === run time

// ---------------compile time polymorphism 

// a) function overloading 
// same function name but different parameter lists 

#include <iostream>
using namespace std;

class Print {
public:
    void show(int x) { cout << "Integer: " << x << endl; }
    void show(double y) { cout << "Double: " << y << endl; }
    void show(string s) { cout << "String: " << s << endl; }
};

int main() {
    Print p;
    p.show(10);
    p.show(5.5);
    p.show("Jaswanth");
    return 0;
}


// b) operator overloading
// we redefine how operators like +,-,* etc work for user defined types (objects)

#include <iostream>
using namespace std;

class Complex {
    int real, imag;
public:
    Complex(int r=0, int i=0) : real(r), imag(i) {}

    // Operator overloading
    Complex operator + (Complex const &obj) {
        return Complex(real + obj.real, imag + obj.imag);
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(2, 3), c2(4, 5);
    Complex c3 = c1 + c2;  // operator+ overloaded
    c3.display();
}


// ---------------------run time polymorphism--------------------------------------------
// achieved using inheritance + virtual functions

#include <iostream>
using namespace std;

class Animal {
public:
    virtual void sound() {  // virtual function
        cout << "Animal makes sound" << endl;
    }
};

class Dog : public Animal {
public:
    void sound() override {
        cout << "Dog barks" << endl;
    }
};

class Cat : public Animal {
public:
    void sound() override {
        cout << "Cat meows" << endl;
    }
};

int main() {
    Animal* a1;
    Dog d;
    Cat c;
    a1 = &d;
    a1->sound();  // Calls Dog's sound() → runtime binding
    a1 = &c;
    a1->sound();  // Calls Cat's sound()
    return 0;
}


// why we need polymorphism 

// *) to write flexible and reusable code , to override base class behavior for specific derived classes , to support dynamic behavior at runtime , to reduce code code duplication


// can destructors be virtual ?

// yes, especially when using base class pointers to derived objects, to avoid memory leaks









