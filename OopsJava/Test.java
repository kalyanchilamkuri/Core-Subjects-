// what is polymorphism in java with example

// poly= many morps=form => one thing behaving in many forms 

// polymorphism allows the same methodname to perform different behaviors based on context 

// why?
// with out polymorphism => code becomes lengthy and repetitive

// class Dog {
//     void sound() {
//         System.out.println("Dog barks");
//     }
// }

// class Cat {
//     void sound() {
//         System.out.println("Cat meows");
//     }
// }


// with polymorphism => code becomes reusable and maintainable

// class Animal {
//     void sound() {
//         System.out.println("Animal makes sound");
//     }
// }

// class Dog extends Animal {
//     void sound() {
//         System.out.println("Dog barks");
//     }
// }

// class Cat extends Animal {
//     void sound() {
//         System.out.println("Cat meows");
//     }
// }


// Types of polymorphism in Java 

// static => compile-time => method overloading => because compiler determines which method to call based on arguements. 

// multiple methods with same name but different paremeter list in the same class

class Calculator{
    int add(int a,int b){
        return a+b;
    }
    int add(int a,int b,int c){
        return a+b+c;
    }
    double add(double a, double b){
        return a+b;
    }
}

// usage

// Calculator c = new Calculator();
// System.out.println(c.add(2, 3));
// System.out.println(c.add(2, 3, 4));
// System.out.println(c.add(2.5, 3.5));

// Rules of method overloading 

// 1)Same method name 
// 2)Different parameter list 
// 3) cannot overload by return type

// overloading can also happen in inheritance

// class A {
//     void show(int a) {}
// }

// class B extends A {
//     void show(int a, int b) {}
// }

// main method can also be overloaded 



// ------------------------------RunTime polymorphism-----------------------

// what is method overriding => child class provides its own implementation of a parent method 

// class Animal {
//     void sound() {
//         System.out.println("Animal sound");
//     }
// }

// class Dog extends Animal {
//     void sound() {
//         System.out.println("Dog barks");
//     }
// }

// usage :-  
// Animal a = new Dog();
// a.sound(); => here barks comes 

// here jvm checks the object type at runtime and calls the appropriate method 
// this is runtime polymorphism , dyna1mic method dispatch

// method call is decided by object type , not reference type

// Reference vs object

// Animal a=new Dog(); => variables --> depends on reference type ; Methods => depends on object type 

// polymorphism applies only to methods but not to variables 

// Here .. Animal a=new Dog();
// reference type -> animal , compiler checks does animal have x? => x=10;
// variables do not participate in runtime polymorphism 
// methods are decided by object type => Dog => sound() => Dog barks



// class Animal {
//     int x = 10;
// }

// class Dog extends Animal {
//     int x = 20;
// }

// public class Test {
//     public static void main(String[] args) {
//         Animal a = new Dog();
//         System.out.println(a.x);
//     }
// }

// here output is 10 because variables are resolved at compile time based on reference type

// rules of method overriding
// 1) same method name
// 2) same parameter list   
// 3) IS-A relationship between classes
// 4) access level cannot be more restrictive        
// 5) return type must be same or covariant
// 6) cannot override final and static methods

// class A{
//     protected void show(){
//         System.out.println();;
//     }
// }

// class B extends A{
    // public void show() {}
// }

// Public -> protected ->private 


// Final method and polymorphism 

// class A {
//     final void show() {}
// }

// class B extends A {
//     void show() {} // ❌ ERROR
// }


// static methods and polymorphism

// class A {
//     static void show() {
//         System.out.println("A");
//     }
// }

// class B extends A {
//     static void show() {
//         System.out.println("B");
//     }
// }

// output => A
 
// static methods use reference type , this is method hiding not overriding 

// constructor cannot be polymorphic

//class Shape {
//     void area() {
//         System.out.println("Area");
//     }
// }

// class Circle extends Shape {
//     void area() {
//         System.out.println("Area of circle");
//     }
// }

// class Square extends Shape {
//     void area() {
//         System.out.println("Area of square");
//     }
// }

// Compile-time polymorphism → Method Overloading → Compiler decides
// Runtime polymorphism → Method Overriding → JVM decides


// Final keyword in Java

// final => constant , cannot be changed once initialized i.e cannot change it further 

// depending on where we see it , the meaning changes 

// 1)Final variable 

// Meaning => once a value is assigned , it cannot be changed

// final int x = 10;
// x = 20; // ❌ ERROR

// initialzation can be at declaration or inside constructor 


// class Test {
//     final int x;

//     Test(int x) {
//         this.x = x;
//     }
// }

// 2) Final with object reference

// final Student s = new Student();
// s.name = "Rahul";   // ✅ allowed
// s = new Student();  // ❌ not allowed

// Reference cannot change,object data can change

// 3) Final method

// a final method cannot be overridden by child class

// class Parent {
//     final void show() {
//         System.out.println("Parent show");
//     }
// }

// class Child extends Parent {
//     void show() { } // ❌ ERROR
// }

// we use final for security , prevent behavior modification , performance optimization 

// Final Class 

// a final class cannot be.. inherited 

// final class A {}

// class B extends A {} // ❌ ERROR

// final cannot be used in constructor because constructor is not inherited
// final can be used in method overloading 

// super keyword in Java
// super refers to the immediatae parent class object , used inside child class 

// uses of super => 1) call parent constructor 2)access parent variables 3)access parent methods 

// super() => calls parent class constructor

class Parent {
    Parent(int x) {
        System.out.println("Parent: " + x);
    }
}

class Child extends Parent {
    Child() {
        super(10); // MUST be first line
        System.out.println("Child constructor");
    }
}
// accessing parent variables using super
// rules => must be first statement , used only inside constructor , if not written then java inserts super()

// accessing parent variables using super


// class Parent {
//     int x = 10;
// }

// class Child extends Parent {
//     int x = 20;

//     void show() {
//         System.out.println(x);        // 20
//         System.out.println(super.x);  // 10
//     }
// }

// accessing parent methods using super

// class Parent {
//     void display() {
//         System.out.println("Parent display");
//     }
// }

// class Child extends Parent {
//     void display() {
//         super.display();
//         System.out.println("Child display");
//     }
// }


// this => current 
// super => parent 


// Coupling 

// Tight coupling 

// one class directly depends on another classes , it is hard to change and not flexible 

class Engine {
    void start() {
        System.out.println("Engine started");
    }
}

class Car {
    Engine engine = new Engine();

    void drive() {
        engine.start();
        System.out.println("Car running");
    }
}

// cannot change engine easily , testing is difficult , code is rigid

// Loose coupling

// classes depend on abstraction but not implementation , flexible and easy to extend and maintain 

// interface Engine {
//     void start();
// }

// class PetrolEngine implements Engine {
//     public void start() {
//         System.out.println("Petrol engine started");
//     }
// }

// class DieselEngine implements Engine {
//     public void start() {
//         System.out.println("Diesel engine started");
//     }
// }

// class Car {
//     Engine engine;

//     Car(Engine engine) {
//         this.engine = engine;
//     }

//     void drive() {
//         engine.start();
//         System.out.println("Car running");
//     }
// }

// is is important 
// => easy modificaation , easy testing , scalable design , used in frameworks


// Coupling => coupling means how strongly one class depends on another class => if changing class A forces you to change class B , then they are tightly coupled => if class A can work even when class B changes , then they are loosely coupled 

// loose coupling => flexible and maintainble software 
// tight coupling => fragile and hard to maintain software


// Tight coupling 

// a class is tighly coupled if it directly depends on the concrete implementation of another class

// Means : one class creates another class using new, one class knows too much about another class , hard to replace or modify dependencies 

// Tight coupling

class Engine {
    void start() {
        System.out.println("Engine started");
    }
}

class Car {
    Engine engine = new Engine(); // ❌ tightly coupled

    void drive() {
        engine.start();
        System.out.println("Car is running");
    }
}

// Here car direclty creates engine , car depend on specific engline class 

// problems with tight coupling is ...hard to change ...if we want to diesel engine then we must modify car class , 


// Loose coupling 

// a class is loosely coupled if it depends on an abstraction (interface / abstract class ) not on a concrete class

// classes interact via interface , ijmplementation can change freely and minimal dependency 

// Loose coupling 

// program to an interface , not an implementation 

// step-1 => create an interface 

interface Engine {
    void start();
}

// step-2 => implement the interface

class PetrolEngine implements Engine {
    public void start() {
        System.out.println("Petrol engine started");
    }
}

class DieselEngine implements Engine {
    public void start() {
        System.out.println("Diesel engine started");
    }
}

// step-3=> use interface in dependent class 

class Car {
    Engine engine; // ✅ loosely coupled

    Car(Engine engine) {
        this.engine = engine;
    }

    void drive() {
        engine.start();
        System.out.println("Car is running");
    }
}

Car car1 = new Car(new PetrolEngine());
car1.drive();

Car car2 = new Car(new DieselEngine());
car2.drive();

car class remains unchanged and only engine implementation changes

// why this is loose coupling?

// car does not know which engine , how engine works , car only knows engine has start method

// Wall socket

// You can plug:

// Mobile charger

// Laptop charger

// TV plug

// 👉 Socket = interface
// 👉 Devices = implementations

// Dependency injection 

loose coupling is acheived using dependency injection (DI)

Types of Dependency Injection

1) constructor injection (Best)

Car(Engine engine){
    this.engine=engine;
}

2) Setter injection 

void setEngine(Engine engine){
    this.engine=engine;
}

// when a class directly depends on another concrete class then it is tightly coupled
// when a class depends on abstraction , not implementation 
// we achieve loose coupling using dependency injection
// loose coupling is better because of its flexibility maintainability and testability 

// Dependency injection is a design pattern that allows us to inject dependencies into a class rather than hardcoding them.









































