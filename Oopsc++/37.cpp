#include <bits/stdc++.h>
using namespace std;

// rules for virtual functions

/*
*) they cannot be static
*) they are accessed but object pointers
*) virtual functions can be a friend of another class
*) a virtual function in base class might not be used
*) If a virtual function is defined in the base class then there is no need of redefining it in a derived class
*/

class cwh {
protected:
    char title[30];
    float rating;
public:
    cwh(char* s, float r) {
        strcpy(title, s);
        rating = r;
    }
    virtual void display() =0    // pure virtual style optional
};

class cwhvideo : public cwh {
    float videolen;
public:
    cwhvideo(char* s, float r, float vl) : cwh(s, r) {
        videolen = vl;
    }
    void display(void) {
        cout << "This is an amazing video with title \"" << title << "\"" << endl;
        cout << "This video has rating: " << rating << " out of 5" << endl;
        cout << "Length of this video is: " << videolen << " minutes" << endl;
    }
};

class cwhtext : public cwh {
    int words;
public:
    cwhtext(char* s, float r, int wc) : cwh(s, r) {
        words = wc;
    }
    void display(void) {
        cout << "This is an amazing text tutorial with title \"" << title << "\"" << endl;
        cout << "This text has rating: " << rating << " out of 5" << endl;
        cout << "Number of words in this text is: " << words << endl;
    }
};

int main() {
    char title[] = "Django tutorial";
    float rating = 4.89;
    float vlen = 4.56;
    int words = 433;

    // Pointer to base class
    cwh* tutorials[2];

    // Creating video and text objects
    cwhvideo djVideo(title, rating, vlen);
    cwhtext djText(title, rating, words);

    // Storing base class pointers
    tutorials[0] = &djVideo;
    tutorials[1] = &djText;

    // Runtime polymorphism
    tutorials[0]->display();
    cout << "--------------------------" << endl;
    tutorials[1]->display();

    return 0;
}




// what is apure virtual function?

// a pure virtual function with no defination in the base class - it only provides a declaration and expects the derived class to implement it 
// a pure virtaul function is a function that must be overriden in the derived class







#include <iostream>
using namespace std;

class Shape {
public:
    // Pure virtual function
    virtual void draw() = 0;  
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing Circle" << endl;
    }
};

class Square : public Shape {
public:
    void draw() override {
        cout << "Drawing Square" << endl;
    }
};

int main() {
    // Shape s; ❌ Error: cannot instantiate abstract class

    Shape* shape;
    Circle c;
    Square s;

    shape = &c;
    shape->draw();   // Output: Drawing Circle

    shape = &s;
    shape->draw();   // Output: Drawing Square
}



// what is an abstract class?
// a class that contains atleast one pure virtaul function is called an abstract class
// we cannot create an object of an abstract class but we can create a pointer reference to it 





// abstract class with constructor 

// => abstract class can have a constructor, but we cant create its object directly

#include <iostream>
using namespace std;

class Base {
public:
    Base() {
        cout << "Base constructor called\n";
    }
    virtual void show() = 0;  // pure virtual
};

class Derived : public Base {
public:
    void show() {
        cout << "Derived implementation\n";
    }
};

int main() {
    Derived d;  // Base constructor is still called
    d.show();
}


// why do we need pure virtual functions ?

// to enforce derived classes to provide their own implementation







//-------------------------------Encapsulation --------------------

// Data wrapping 

// ==> encapsulation means binding data(variables) and methods(functions) that operate on that data into a single unit i.e a class
// ==> it also restricts direct access to the data - only class methods can modify it 


#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;  // Data is hidden

public:
    BankAccount(double b) {
        balance = b;
    }

    void deposit(double amount) {
        if (amount > 0)
            balance += amount;
    }

    double getBalance() {   // Controlled access
        return balance;
    }
};

int main() {
    BankAccount acc(1000);
    acc.deposit(500);
    cout << "Current balance: " << acc.getBalance() << endl;

    // acc.balance = -500; ❌ Error: private member
    return 0;
}




// it is like a capsule => it wraps the medicine inside so you cant touch it directly. 
// we just take the capsule like using deposit() and getBalance() instead of touching the balance



// encapsulation means wrapping data and the functions that operate on it into a single unit , it helps in data binding and code maintainability.


// --------------Abstraction ------------------------------------------



// abstraction means showing only essential features of an object while hiding the complex implementation details




#include <iostream>
using namespace std;

class Car {
public:
    void startCar() {
        startEngine();
        cout << "Car started!" << endl;
    }

private:
    void startEngine() {    // hidden from user
        cout << "Engine started internally..." << endl;
    }
};

int main() {
    Car c;
    c.startCar();   // user doesn’t know internal details
    return 0;
}


// here user only calls the startcar , not worrying about how engine starts 
// the complex logic is hidden in private function startengine()



// abstraction using access modifiers

#include <iostream>
using namespace std;

class Car {
private:
    void checkFuel() {
        cout << "Checking fuel..." << endl;
    }
    void startEngine() {
        cout << "Engine started!" << endl;
    }

public:
    void start() {       // Only expose this function to the user
        checkFuel();     // Internal details are hidden
        startEngine();
        cout << "Car is ready to drive!" << endl;
    }
};

int main() {
    Car c;
    c.start();   // User just calls 'start', doesn't know internal details
    return 0;
}


// abstraction using abstract class

#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() = 0;  // pure virtual function → abstraction
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a Circle" << endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Drawing a Rectangle" << endl;
    }
};

int main() {
    Shape *s;      // abstract class pointer
    s = new Circle();
    s->draw();     // Draws circle

    s = new Rectangle();
    s->draw();     // Draws rectangle

    delete s;
    return 0;
}


// abstraction using pure virtual functions
// it forces derived classes to implement it , ensuring a common interfacae while hiding implementation

#include <iostream>
using namespace std;

class Device {
public:
    virtual void start() = 0;  // pure virtual function
    virtual void stop() = 0;   // pure virtual function
};

class Fan : public Device {
public:
    void start() override { cout << "Fan started" << endl; }
    void stop() override { cout << "Fan stopped" << endl; }
};

class Light : public Device {
public:
    void start() override { cout << "Light turned on" << endl; }
    void stop() override { cout << "Light turned off" << endl; }
};

int main() {
    Device *d;

    d = new Fan();
    d->start();
    d->stop();

    d = new Light();
    d->start();
    d->stop();

    delete d;
    return 0;
}
