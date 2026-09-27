//Constructors in derived class
// we can use constructors in derived classes in c++
// if base class constructor does not have any arguements, there is no need of any constructor in derived class
// but if there are one or more arguements in the base class constructor, derived class need to pass arguements to the base class constructor
// if both base and derived classes have constricyroe base class const is executed first

// in multiple inheritance, base classes are constructed in the order in which they appear in the class declaration
// in multilevel inheritance, the constructors are executed in the order of inheritance

// special syntax

// c++ supports a special syntax for passing arguements to multiple base classes
// the constructor of the derived class receives all the args at once and then willpass the cells to the respective baseclasses

// special case or virtual base class

// the constructors for virtual base classes are invoked before an nonvirtual base class
// if there are multiple virtual base classes, they are invoked in the order declared
// any non-virtual base class are then constructed before the derived class constructor is executed



// one
// If a base class constructor has no arguements you dont need to call it , its called automatically before the derived class constructor 
// but if the base class constructor has parameters , the derived class must explicitly pass them using an initializer list

// here base class constructor run first then derived class constructor runs 
#include <iostream>
using namespace std;

class Base {
    int a;
public:
    Base(int x) {
        a = x;
        cout << "Base constructor called with a = " << a << endl;
    }
};

class Derived : public Base {
    int b;
public:
    Derived(int x, int y) : Base(x) {   // 👈 passing x to Base constructor
        b = y;
        cout << "Derived constructor called with b = " << b << endl;
    }
};

int main() {
    Derived obj(10, 20);
    return 0;
}


//two (in multiple)
// when we have multiple base classes , constructors are called in the order they appear in the inheritance list, no in the order they are passed in the initializer list.

#include <iostream>
using namespace std;

class A {
public:
    A() { cout << "A's constructor\n"; }
};

class B {
public:
    B() { cout << "B's constructor\n"; }
};

class C : public A, public B {  // order: A → B
public:
    C() { cout << "C's constructor\n"; }
};

int main() {
    C obj;
    return 0;
}


// three (multilevel)
// in multilevel inheritance , constructors execute from base->derived->most derived\

#include <iostream>
using namespace std;

class A {
public:
    A() { cout << "A's constructor\n"; }
};

class B : public A {
public:
    B() { cout << "B's constructor\n"; }
};

class C : public B {
public:
    C() { cout << "C's constructor\n"; }
};

int main() {
    C obj;
    return 0;
}


// four (special case : virtual base class constructors)

// if a base class is declared as virtual , its constructor is called before any non-virtual base class , no matter the order in which they appear in the inhertance list

🧠 “What is the order of constructor calls in inheritance?”
→ Base → Derived (always base first).

⚙️ “If there are multiple base classes, which constructor executes first?”
→ In the order they appear in the class declaration, not in the initializer list.

💡 “What if a base class has parameters?”
→ The derived class must call it explicitly using an initializer list.

🔁 “In virtual base class scenario, which constructor is called first?”
→ Virtual base class constructors are always called before non-virtual ones.

⚡ “When is destructor called?”
→ Destructors are called in reverse order of constructors (Derived → Base).



