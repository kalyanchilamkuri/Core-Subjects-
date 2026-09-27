// abstraction is hiding the implementation details and showing only whatis necessary.

// In oop, abstraction is achieved using: 1)abstract class 2)interfaces

// abstract class is a class that cannot be instantiated , can contain abstract methods,non-abstract methods , constructors , static methods , final methods , instance variables 

// abstract class Vehicle{
//    abstract void start();  // abstract method
//  }

// abstract function by default the functions are abstract and public

// an abstract method has no body , forces child classes to provide implementation
// abstract class Vehicle {
//     abstract void start();
// }

// ===>> If a class has atleast one abstract method , then the class must be abstract

// we need abstract classes to force a contract , to provide partial implementation and to achieve runtime polymorphism

// Method overriding in Abstract classes:
// when a child class provides its own implementation of a parent method

abstract class Vehicle {
    abstract void start();
}

class Bike extends Vehicle {
    @Override
    void start() {
        System.out.println("Bike starts with kick");
    }
}

// rules for overriding :
    // **)child class must implement all the abstract methods ,method signature must be same , access modifier cannot be more erstricted


// can abstract classes have concrete methods?
// yes 
abstract class Vehicle {
    abstract void start();

    void fuel() {
        System.out.println("Vehicle needs fuel");
    }
}


// abstract class + static methods
// can abstract class have static methods?
// yes 
abstract class Vehicle {
    abstract void start();

    static void info() {
        System.out.println("This is a vehicle");
    }
}


// static methods cannot be abstract because abstract need overriding , but static means belongs to class , cannot be overridden

// abstract class + final method 
// yes abstract class have final methods.

abstract class Vehicle {
    final void rules() {
        System.out.println("Follow traffic rules");
    }
}

// final methods cannot be overridden , so if a child class extends an abstract class with final method , it cannot override that method

// abstract class+constructors 
// yes can have
// used to initialize variables of abstract class 
// called when child object is created 

abstract class Vehicle {
    Vehicle() {
        System.out.println("Vehicle constructor");
    }
}

// Super keyword 
// super refers to the immediate parent class object 

// uses of super keyword: 1) access parent class variables 2)call parent class methods 3)call parent class constructor

// 1)
abstract class Vehicle {
    int speed = 60;
}

class Car extends Vehicle {
    int speed = 120;

    void showSpeed() {
        System.out.println(super.speed); // 60
    }
}


// 2)
abstract class Vehicle {
    void display() {
        System.out.println("Vehicle display");
    }
}

class Car extends Vehicle {
    void display() {
        super.display();
        System.out.println("Car display");
    }
}

//3)
abstract class Vehicle {
    Vehicle() {
        System.out.println("Vehicle constructor");
    }
}

// 4) super keyword in abstraction (we can use in child classes extending abstract class)
class Car extends Vehicle {
    Car() {
        super(); // called implicitly if not written
        System.out.println("Car constructor");
    }
}

// can we override concrete methods of abstract class?
// Yes 


// use abstract class when
// 1) you want base class with common code 
// 2) you want to force subclasses to implement some behaviour
// 3) you need constructors/state


// Interfaces in java

// an interface is a fully abstract blueprint of a class
// interfaces help us to achieve 100% abstraction
// multiple inheritance is possible using interfaces 
// loose coupling and runtime polymorphism can be achieved using interfaces

interface Animal {
    void sound();
}

// interfaace keyword is used 
// methods are public+static by default
// variables are public+static+final by default

// implementing an interface 
// use the implements keyword
// public is mandatory while overriding 
class Dog implements Animal {
    public void sound() {
        System.out.println("Dog barks");
    }
}

// interface variables
// variables in a interface are public , static and final by default

interface Vehicle {
    int SPEED = 100;
}

public static final int SPEED = 100;

// we cannot change the value of SPEED in implementing class
// SPEED = 200; // error

// Method overriding in interfaces
// method signature must be same , access modifier must be public , child class must implement all the methods

interface Shape {
    void draw();
}

class Circle implements Shape {
    public void draw() {
        System.out.println("Drawing circle");
    }
}


// Multiple inheritance using interfaces 
// Java does not allow multiple inheritance using classes to avoid ambiguity 


interface A {
    void show();
}

interface B {
    void show();
}

class C implements A, B {
    public void show() {
        System.out.println("Implementation of show");
    }
}

// No ambiguity here because both interfaces have same method signature
// interfaces can have static methods , cannot be overridden , must be called using interface name
// interface methods cannot be final , because final methods cannot be overridden
// final->cannot be changed,interface must be implemented
// interfaces extend interfaces but not classes 
// class->class =>extends class->interface => implements interface->interface => extends

// Diamond problem in interfaces


interface A {
    default void show() {
        System.out.println("A");
    }
}

interface B {
    default void show() {
        System.out.println("B");
    }
}

class C implements A, B {
    public void show() {
        A.super.show(); // or B.super.show();
    }
}

// functional interface => interface with exactly one abstract method
// used with lambda expressions 

// use interfaces when
// 1) you need to achieve multiple inheritance      
// 2) you want to define a contract that multiple classes can implement
// 3) you want to achieve loose coupling between classes

// Interface defines a contract that a class must implement, enabling abstraction, multiple inheritance, and loose coupling.

public class oops5 {
    public static void main(String[] args) {
        Bike bike = new Bike();
        bike.start(); // Bike starts with kick

        Car car = new Car();
        car.showSpeed(); // 60

        Dog dog = new Dog();
        dog.sound(); // Dog barks

        C c = new C();
        c.show(); // Implementation of show

        Vehicle.info(); // This is a vehicle

        Car car2 = new Car();
        // Output:
        // Vehicle constructor
        // Car constructor
    }
}

// Interface
// An interface is a contract that defines what a class must do.
// variables => public final static , methods => public abstract by default

// Annotations 
// annotations are metadata , information about code
// they do not change the code but help the compiler , frameworks and tools

// common annotations in java

// 1) @Override => indicates that a method is intended to override a method in a superclass
// Used when implementing an interface method.
// @Override is important because it helps catch errors at compile time if the method signature does not match any method in the superclass or interface.
interface Animal {
    void sound();
}

class Dog implements Animal {
    @Override
    public void sound() {
        System.out.println("Dog barks");
    }
}

// @FunctionalInterface => indicates that an interface is intended to be a functional interface

// must have exactly one abstract method 
// can have default and static methods 



























