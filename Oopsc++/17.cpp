// Inheritance in c++ => overview

// inheritance is the process of acquiring the properties of one class into another
// Inheritance is a mechanism in OOP where one class inherits the properties and behaviors of another class 

// why use inheritance?
/*
 *)code reuse: we don't have to write the same code again and again
 *)Extensibility:you can extend base class functionality
 *)polymorphism:enables runtime flexibility
 *)readability adn maintenance - simpler and modular code
*/

/*
*) Base class => the class being inherited from
*) Derived class => the class inheriting the base class
*)code reuse => you can reuse existing code using inheritance
*)Access specifier => controls how base members are accessed in derived

*/

// Multiple inheritance
class A {
public:
    void displayA() {
        cout << "Class A" << endl;
    }
};

class B {
public:
    void displayB() {
        cout << "Class B" << endl;
    }
};

class C : public A, public B {
public:
    void displayC() {
        cout << "Class C" << endl;
    }
};

int main() {
    C obj;
    obj.displayA();
    obj.displayB();
    obj.displayC();
    return 0;
}


// Multilevel inheritance
class Animal {
public:
    void eat() {
        cout << "Eating..." << endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        cout << "Barking..." << endl;
    }
};

class Puppy : public Dog {
public:
    void weep() {
        cout << "Weeping..." << endl;
    }
};

int main() {
    Puppy p;
    p.eat();   // From Animal
    p.bark();  // From Dog
    p.weep();  // From Puppy
    return 0;
}

// Single inheritance
#include <iostream>
using namespace std;

class Animal {
public:
    void sound() {
        cout << "Animal makes a sound" << endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        cout << "Dog barks" << endl;
    }
};

int main() {
    Dog d;
    d.sound(); // Inherited from Animal
    d.bark();  // Own method
    return 0;
}



#include<bits/stdc++.h>
using namespace std;

int main(){
    return 0;
}





// multiple inheritance
// one derived class inherits from more than one base class



















// Access Specifiers in Inheritance

// Access in derived class depends on how you inherit (public/private/protected).

// Base Member	Public Inheritance	Protected Inheritance	Private Inheritance
// public	public	protected	private
// protected	protected	protected	private
// private	❌ Not inherited	❌ Not inherited	❌ Not inherited

// 🧠 Usually, we use public inheritance (meaning “is-a” relationship).




// types of inheritance 

// 1)single 
// 2)multiple 
// 3)Multilevel
// 4)heirarchical
// 5)hybrid


// 4) heirarchical

#include <iostream>
using namespace std;

class Animal {
public:
    void eat() { cout << "Eating...\n"; }
};

class Dog : public Animal {
public:
    void bark() { cout << "Barking...\n"; }
};

class Cat : public Animal {
public:
    void meow() { cout << "Meowing...\n"; }
};

int main() {
    Dog d;
    d.eat();
    d.bark();

    Cat c;
    c.eat();
    c.meow();
}



// 5) hybrid => leads to diamond problem 

#include <iostream>
using namespace std;

class A {
public:
    void show() { cout << "A\n"; }
};

class B : virtual public A {};  // virtual to avoid duplication
class C : virtual public A {};
class D : public B, public C {};

int main() {
    D obj;
    obj.show(); // works fine because of virtual inheritance
}






// ambiguity in multiple inheritance

// when two base classes have the same member names (like same variable or same function),the derived class gets two copies of that member -> compiler becomes confused which one to use.


#include<bits/stdc++.h>
using namespace std;

class A{
    public:
      void show(){
         cout<<"class A show()"<<endl;
      }
};

class B{
    public:
       void show(){
        cout<<"class B show()"<<endl;
       }
}

class C:public A,public B{
    public:
       void display(){
        // show() ---> ambiguity : compiler doesnt know which show() to call
        A::show();
        B::show();
       }
};


int main(){
    C obj;
    obj.display();
    return 0;
}


// ** => we resolve the amiguity using scope resolution operator 
//  we can also call abj.A::show();

