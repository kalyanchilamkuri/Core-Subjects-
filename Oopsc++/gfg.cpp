
// Q)class 

// a class is notihng but a blueprint or a prototype from which objects are created. using classes we can create multiple objjects with same behavior instead of writing their code multiple times.

// Q)Access Specifiers

// access specifiers are special types of keywords that are used to specify or control the accessibility of entities like classes , methods.

// Q)Object

// an object is an instant of a class that represents real life entities.

// Q)Abstraction 

// abstraction is similar to data encapsulation and is very important in oops, it means showing only the necessary information and hiding the other irrelevent information from the user.

// Q)Encapsulation 

// Encapsulation is the binding of the data and methods that manipulate them into a single unit such that the sensitiuve data is hiden from the users.

// Q)Inhertance

// It is the mechanism in which one class is allwed to inherit the features of another class , inheritance supports the concepts of reusability i.e when we want to create a new class nad there is already a class that includes some of the code that we want , we can drive our new class from the existing class.

// Q)Polymorphism

// polymorphism allows the same method or object to behave differently baased on the context.
// compile time polymorphism , also known as static polymorphism or early binding is the type of polymorphism where the binding of the call to its code is done at the compiler time , method overloading or operator overloading are examples of compiler time polymorphism
// run time polymorphism is the type of polymorphism where the actual implementation of the function is determined during the runtime or execution. example is function overriding.

// function overloading => also known as compile time polymorphism 

// this occus when two or more functions in the same class share the same name but have different parameters lists.

// function overriding => run-time polymorphism

// this occurs when a function in derivved class has the same name , return type , and parameters as a function in the base class. we acheive this using a virtual function.

// Advantage of OOP over procedure-oriented programming language

// *) by using objects and classes , we can create reusable components leading to less duplication , and more efficient development and it provides a clear and logical structure making the code easier to understand , maintain and debug i.e oops support the DRY(dont repeat yourself)principle , this principle encourages minimizing code repetiootion , leading to cleaner and more maintainable code.

// object oriented is a programming paradigm , where the complete software operates as a bunch of objects talking to each other. an object is a collection of data and methods wich operate on that data.

// object oriented programming => follows a bottom-to-top approach , enhanced code reusability due to concepts of polymorphism , modifying and updating the code is easier , data is given more importance in oops , here data is given more importance 
// structural programming => it follows a top-to-down approach , no restriction to the flow of data , code reusabilityis achieved by using functions and loops,functionas are called dequentially , here code is given more importance

// what is an interface 
// an interface in c++ is typically represented by a class that contains only pure virtual functions such a class specifies a contract , any class that inherits front the interface must implement all pure virtual functions
// a class with only pure virtual functions is called as an interface
// we cannot create objects of an interface class

// Q)what is the difference between the structure and class
// the major differenc between the structure and the class is..in structure all the members are set to public by default but in class members are private by edfault
// the other difference is that we use struct for declaring the structure and we use class for declaring a class in c++

// Q)what is constructor?
// a constructor is a block of code that initializes the newly created object, a constructor resembles an instance methods but its not a method as it doesnt have a return type.

// default contructor => it is a constructor that doesn't take any arguements, it is a non-parameterized constructor that is automatically defined by a non-parameterized constructor that is automatically define by the compiler
// non-parameterized constructor => it is a user-defined constructor having no arguements or parameters

// parameterized constructor
// the constructors that take some arguements are known as parameterized constructors

// a destructor is a method that is automatically called when the object goes out of scope or destroyed.

// we can overload constructors in a class in c++.
// we cant overload the destructors in a class

// Q)what are friend functions and friend classes?
// Friend functions => a friend function is a special function that is allowed to access private and protected data of a class, even though its not a member of the class
// friedn class=>a friend class is a class that can access the private and protected members of another class , its like a trusted friend ...it can see and also change your personal information

// Q)virtual function 

// 1) a virtual function is a member function in a base class that we expect to override in derived class , it allows runtime polymorphism it means the actual function called is decided at runtime based on type of object.
#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() {      // virtual function
        cout << "Base class show()" << endl;
    }
};

class Derived : public Base {
public:
    void show() override {
        cout << "Derived class show()" << endl;
    }
};

int main() {
    Base* bptr;
    Derived d;

    bptr = &d;
    bptr->show();  // Calls Derived::show() because 'show' is virtual

    return 0;
}

// output is derived class show()
// if show() was not declared virtual,the output would be base calss show() because of static (compiler-time) binding 

// pure virtual function 

// a pure virtual function is a virtual function that has not implementation in the base class , it is just a function declaration with =0;
// this makes the class as an abstract class, which cannot be instantiated directly

#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() = 0;  // pure virtual function (no body)
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a Circle" << endl;
    }
};

int main() {
    // Shape s;           // ❌ Error: cannot instantiate abstract class
    Shape* sp = new Circle();
    sp->draw();               // Calls Circle::draw()
    delete sp;
    return 0;
}

// differences

// virtual => has a defination(body) , allow overriding in derived class , base class can be instantiated => allows overriding 
// pure virtual function => no defination(body) , force derived classes to override it , base class becomes abstract (we cannot intantiate) , virtual void func()=0 => forces mandatory overriding and makes the class abstract

// Q)what is an abstract class
// in general terms , an abstract class is a class that is intended to be used for inheritance.it cannot be instantiated, an abstract class can consist of both abstract and non-abstract methods.

// In c++,an abstract class is a class that contains at least one pure virtual function , where as in java we declare with an abstract keyword

// Q) what is an interface 

// In object oriented programming , an interface defines a contract ; It specifies what function a classmust have , but not how they are implemented.

// c++ doesnt have a special interface keyword , but we can create an interface using an abstract class that has only pure virtual functions 

#include <iostream>
using namespace std;

// This is an interface
class IShape {
public:
    virtual void draw() = 0;        // pure virtual function
    virtual double area() = 0;      // pure virtual function
    virtual ~IShape() {}             // virtual destructor (recommended)
};

// Implementing the interface
class Circle : public IShape {
    double radius;
public:
    Circle(double r) : radius(r) {}

    void draw() override {
        cout << "Drawing a Circle" << endl;
    }

    double area() override {
        return 3.14 * radius * radius;
    }
};

int main() {
    IShape* shape = new Circle(5.0);  // using interface pointer
    shape->draw();
    cout << "Area: " << shape->area() << endl;

    delete shape;
    return 0;
}


// key rules of interfaces:
// must contains only pure virtaul functions (syntax=0)
// no objects can be created from interface class.
/// any class that inherits from an interface must implement all its functions , otherwise it becomes abstract too

// in c++ an interface=abstract class with all pure virtaul functions , it defines what derived class must do, now they do it.
// they are heavily used in polymorphism and design patterns

// to enforce a common structure on different classes , to acheive polymorphism , to make your code flexible and maintainable - easily add new classes without changing old code

