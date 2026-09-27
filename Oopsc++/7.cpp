
// Friend Functions

//normally members like a,b of a class are not accessible outside the class
//but sometimes we need an external function to access the private data
//to allow this we use a friend function
//you make it friend of the class by using friend keyword

// A friend function is not a member of the class, but it can access private/protected members of the class , It must be declared inside the class with friend keyword 

// when to use friend function

// When operator overloading needs access to private members.
// When two classes need to cooperate closely.
// When writing utility functions like sumComplex.


//properties of friend functions

// 1) not in the scope of class
// 2) since it is not in the scope of the class , it cannot be called from the object of that class. c1.sumComplex() == Invalid
// 3)can be invoked without the help of any object
// 4)usually contains the arguements as objects
// 5)can be declared inside the private or public section of the classes
// 6)It cannot access the members directly by their names and need object_name.member_name to access any member.

#include <bits/stdc++.h>
using namespace std;

class Complex {
    int a, b;

public:
    void setNumber(int n1, int n2) {
        a = n1;
        b = n2;
    }

    //Friend function declaration
    //declares sumComplex as a friend function
    //It is not a member function
    //Just declared inside the class

    //Below line means  => declaring the sumcomplex function and complex function as friends. 
    friend Complex sumComplex(Complex o1, Complex o2);

    void printNumber() {
        cout << "Your number is " << a << " + " << b << "i" << endl;
    }
};

// we use friend function => when we want a function outside of the class to access private variables

// Friend function definition
// this function is outside the class 
// It adds two complex numbers by accessing their private data directly
Complex sumComplex(Complex o1, Complex o2) {
    Complex o3;
    o3.setNumber(o1.a + o2.a, o1.b + o2.b);  // private data accessed
    return o3;
}

int main() {
    Complex c1, c2, sum;

    c1.setNumber(1, 4);
    c1.printNumber();

    c2.setNumber(2, 5);
    c2.printNumber();

    sum = sumComplex(c1, c2);
    sum.printNumber();

    return 0;
}









// basic rubrik function 

#include <iostream>
using namespace std;

class Box {
    int width;

public:
    Box(int w) { width = w; }

    // friend function declaration
    friend void showWidth(Box b);
};

// Friend function definition
void showWidth(Box b) {
    // Can access private data directly
    cout << "Width of box = " << b.width << endl;
}

int main() {
    Box b1(10);
    showWidth(b1);   // Even though width is private, friend function can access it
    return 0;

}





// Properties of Friend Functions
// Declared inside class using friend keyword.
// Not a member function of the class (so it’s called like a normal function, not obj.func()).
// Can access private and protected members of the class.
// Can be declared in multiple classes if needed.
// Not inherited when the class is inherited.
// Can be useful for operator overloading (like operator<< for cout).

// When two classes need to share their private data with one common function.
// For operator overloading (e.g., operator<< for printing an object)
// For utility functions that need access to private data but should not be part of the class itself.




// friend function between 2 classes

#include <iostream>
using namespace std;

class B;  // forward declaration

class A {
    int x;
public:
    A(int val) : x(val) {}
    friend void add(A, B);  // declare as friend
};

class B {
    int y;
public:
    B(int val) : y(val) {}
    friend void add(A, B);  // declare as friend
};

void add(A objA, B objB) {
    cout << "Sum = " << objA.x + objB.y << endl;  // accessing private members
}

int main() {
    A a1(5);
    B b1(10);
    add(a1, b1);  // Output: Sum = 15
    return 0;
}






// a friend function in c++ is basically a non-member function that is given special access to the private and the protectedmembers of a class , normally only the class's own member functions can access private data but if we declare a function using the keyword inside the class that function can also access those private members, even though its not actually a part of the class.


























