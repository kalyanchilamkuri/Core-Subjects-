// virtual keyword is used to achieve runtime polymorphism (also known as dynamic binding).
// It allows a derived class to override a function from the base class and ensures that the correct version of the function is called at runtime


// What is a virtual function?
// // A virtual function in C++ is a member function in a base class that you expect to override in derived classes, and you want the call to that function to be resolved at runtime (based on the actual object type), not at compile time.
// // 📌 Without virtual, the compiler uses static binding → decides the function to call at compile time based on the pointer/reference type.
// // 📌 With virtual, the compiler uses dynamic binding → decides the function to call at runtime based on the actual object’s type.

// #include <iostream>
// using namespace std;

// class Animal {
// public:
//     virtual void speak() { cout << "Animal sound\n"; }
//     virtual ~Animal() {}
// };

// class Dog : public Animal {
// public:
//     void speak() override { cout << "Woof!\n"; }
// };

// class Cat : public Animal {
// public:
//     void speak() override { cout << "Meow!\n"; }
// };

// int main() {
//     Animal* animals[] = { new Dog(), new Cat() };
//     for (auto a : animals) {
//         a->speak(); // Woof! then Meow!
//         delete a;
//     }
// }


// without virtual 
// #include <iostream>
// using namespace std;

// class Base {
// public:
//     void show() {
//         cout << "Base class show()" << endl;
//     }
// };

// class Derived : public Base {
// public:
//     void show() {
//         cout << "Derived class show()" << endl;
//     }
// };

// int main() {
//     Base* ptr;
//     Derived d;

//     ptr = &d;   // base pointer points to derived object
//     ptr->show(); // ❌ Calls Base::show(), not Derived::show()
//     return 0;
// }


// with virtual
#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() {       // 👈 virtual keyword added
        cout << "Base class show()" << endl;
    }
};

class Derived : public Base {
public:
    void show() override {      // 👈 override for clarity (optional)
        cout << "Derived class show()" << endl;
    }
};

int main() {
    Base* ptr;
    Derived d;

    ptr = &d;
    ptr->show();   // ✅ Calls Derived::show() because of virtual function
    return 0;
}


// a virtual function is a member function in a base class thay you expect to override in derived classes.



// // diamond problem:

// //     A
// //    / \
// //   B   C
// //    \ /
// //     D

// // b inherits from a and c inherits from a and d inhertis from both b and c
// //  What’s the problem?
// // When D inherits from both B and C, it ends up with two copies of A
// // One copy comes from B → A
// // Another copy comes from C → A

// // So inside D obj;, you effectively have:

// // A part (from B) → x
// // A part (from C) → x
// // That’s why in your code you must write:

// // obj.B::x = 10;
// // obj.C::x = 20;
// // If you wrote just obj.x, the compiler wouldn’t know which x you mean — the one from B’s A or C’s A — and it would give an ambiguity error.

// // Step 3 – Why it matters
// // This duplication of A is usually not what you want, because:
// // It wastes memory (two copies instead of one).
// // It can cause confusion if you expect there to be only one shared base.


// // Virtual inheritance (solves the diamond problem)
// // Short idea: when multiple derived classes inherit from the same base, and a further class inherits from those two, you may get two copies of the shared base. Marking the inheritance virtual tells the compiler to keep one shared copy of that base.


// how to fix it?



// #include <iostream>
// using namespace std;

// class A {
// public:
//     int x;
// };

// class B : public A { };
// class C : public A { };

// class D : public B, public C { };

// int main() {
//     D obj;
//     obj.B::x = 10;
//     obj.C::x = 20;

//     cout << obj.B::x << endl;  // 10
//     cout << obj.C::x << endl;  // 20
// }


// // here in the above code is is called diamond problem

// // What is the Diamond Problem?

// // It happens in multiple inheritance when a class inherits from two classes that have a common base class.
// // This creates an ambiguity (confusion) about which base class copy should be used.

// // example without virtual inheritance

#include <iostream>
using namespace std;

class A {
public:
    int value;
    A() { value = 10; }
};

class B : public A { };
class C : public A { };
class D : public B, public C {
public:
    void show() {
        // cout << value; ❌ Ambiguity! Which value? From B::A or C::A?
        cout << "B's value = " << B::value << endl;
        cout << "C's value = " << C::value << endl;
    }
};

int main() {
    D obj;
    obj.show();
    return 0;
}


// Problem: D has two copies of A’s data (value) → one from B, one from C.
// If we write obj.value, compiler throws ambiguous error.


// Solution → Virtual Inheritance

// We fix this by making B and C virtually inherit from A.
// That way, D gets only one shared copy of A.

#include <iostream>
using namespace std;

class A {
public:
    int value;
    A() { value = 10; }
};

// Virtual inheritance
class B : virtual public A { };
class C : virtual public A { };

class D : public B, public C {
public:
    void show() {
        cout << "Single value = " << value << endl; // ✅ No ambiguity now
    }
};

int main() {
    D obj;
    obj.show();
    return 0;
}

// Now D has only one copy of A (shared between B and C).


// We are telling the compiler:
// “⚠️ Hey compiler, no matter how many paths exist from D to A, only keep ONE shared copy of A in memory.”

// This is called virtual

























// what is a virtual function ?
// a function in the base class declared with the virtual keyword that can be overridden in the derived class

// what is the use of the virtual functions?
// to achieve runtiem polymorphism - the correct function is called depending on the actual object

// diff b/w compile-time polymorphism and run-time polymorphism
// compile-time used function overloading or operator overloading but runtime uses virtual functions 

// what is a pure virtual function?
// a virtual function with =0 => makes the class abstract

// what is a virtual base class?
// a base class declared as virtual to avoid duplicate copies of baase members during multiple inheritance

// can a constructor be virtual?
// no constructors cannot be virtual but destructors should be virtual if a pointer is used



// compile-time polymorphism => static binding => during compilation => function overloading , operator overloading 
// run-time polymorphism => dynamic binding => during program execution => virtual functions


// run-time polymorphism means => the function to be executed is decided at run time (not compile time) , based in the actual type of object that a pointer or reference refers to
// It is achieved in c++ using inheritance + virtual functions


// we achieve run time polymorphism using virtual functions and base class pointers or references

// to make sure that the derived class version of a function is executed even when accessed through base pointer
