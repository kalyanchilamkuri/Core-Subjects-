
// multiple inheritance c++ oops
// a derived class inherits more than one class

// why we need multiple inheritance?
// => sometime a class logically needs two or more base classes 

         // Base1       Base2
         //   \         /
         //    \       /
         //    Derived

// What’s the problem with multiple inheritance?
// Ambiguity problem (Diamond problem).
// If both Base1 and Base2 have a function with the same name, Derived won’t know which one to use.

// how to solve Ambiguity=> we use scope resolution operator or use virtual inheritance if the base classes have a common ancestor

// How is memory laid out?
// Derived will have separate memory for Base1’s members and Base2’s members.

// What is inherited in this case?
// All non-private members from both Base1 and Base2, subject to the inheritance mode (public here).

// What happens if both Base1 and Base2 have a member variable with the same name?
// Access will be ambiguous, must use Base1::var or Base2::var.


#include<bits/stdc++.h>
using namespace std;

class Base1{
    protected:
       int base1int;
    public:
       void set_base1int(int a){
         base1int=a;
       }
};

class Base2{
    protected:
       int base2int;
       public:
          void set_base2int(int a){
            base2int=a;
          }
};

/*
inherited class will look like this 
base1int -> protected
base2int -> protected

funcs are public
*/

class Derived : public Base1,public Base2{
    public:
        void show(){
           cout<<"this is "<<base1int<<endl;
           cout<<"this is "<<base2int<<endl;
           cout<<"this is "<<base1int+base2int<<endl;
        }
};

int main(){
   Derived harry;
   harry.set_base1int(10);
   harry.set_base2int(20);
   harry.show();
    return 0;
}




// what is diamond problem?

// it occurs when a class inherits from two classes that both inherit from the same base class

// so the inheritance diagram looks like a diamond shape

// A-> base class
// B and C -> derived from a
// D-> derived from both B and C


#include <iostream>
using namespace std;

class A {
public:
    int value;
    A() { value = 10; }
};

class B : public A {};
class C : public A {};
class D : public B, public C {
public:
    void show() {
        cout << "Value = " << value << endl; // ❌ Error: ‘value’ is ambiguous
    }
};

int main() {
    D obj;
    obj.show();
    return 0;
}


// ❌ What happens here?

// D inherits from both B and C.

// Both B and C inherited a copy of A.

// So, D actually has two copies of A.

// When you write value, compiler doesn’t know which A::value you are referring to —
// → Ambiguity Error!


// how to resolve the diamond problem 

// using virtual inheritance

// we tell the compiler that only one shared copy of the base class A should be inherited, no matter how many intermediate classes derive from it
// we do this using the virtual keyword


#include <iostream>
using namespace std;

class A {
public:
    int value;
    A() { value = 10; }
};

class B : virtual public A {};
class C : virtual public A {};

class D : public B, public C {
public:
    void show() {
        cout << "Value = " << value << endl; // ✅ No ambiguity
    }
};

int main() {
    D obj;
    obj.show();
    return 0;
}


// what happens now?

// both B and C virtually inherit from A
// so when D inherits from both => only one shared copy of A is created
// hence , no ambiguity => problem solved



// what is the diamond problem?
// => it occurs in multiple inheritance when a derived class inherits from two classes that both inherit from the same base class, leading to two copies of base class members in the final derived class.
// => because the derived class gets duplicate copies of the base class and causes ambiguity 
// => by using virtual inhertance , which ensures only one shared copy of the base class is inherited
// => what does the keyword virtual do here => it tells the compiler to maintain only a single instance of the base class even if multiple paths of inheritance exist
// => when using multiple inheritance and a common base class is repeated in hierarchy



