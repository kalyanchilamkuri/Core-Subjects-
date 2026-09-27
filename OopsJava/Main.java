
// Inheritance 

// inheritance is a mechanism where one class acquires the properties(variables) and behaviours(methods) of another class.
// It is used to achieve reusability and establish a relationship between classes.

// In simple words => one class reuses another class , avoids rewriting code , creates a parent -> child relationship 

// why inheritance?
// without inheritance => hard to maintain and code duplication 
// class Car {
//     int speed;
//     int wheels;

//     void move() {
//         System.out.println("Car is moving");
//     }
// }

// class Truck {
//     int speed;
//     int wheels;

//     void move() {
//         System.out.println("Truck is moving");
//     }
// }

// with inheritance
// class Vehicle {
//     int speed;
//     int wheels;

//     void move() {
//         System.out.println("Vehicle is moving");
//     }
// }

// class Car extends Vehicle {
// }

// class Truck extends Vehicle {
// }
// code reuse , easy maintanance , clear hierarchy


// extends => create parent-child relation ship , super => access parent class , protected => access in child classes , final => prevent inheritance or overriding 

// class Parent {
//     int money = 1000;

//     void house() {
//         System.out.println("Parent has a house");
//     }
// }

// class Child extends Parent {
// }

// // usage 

// public class Main {
//     public static void main(String[] args) {
//         Child c = new Child();
//         System.out.println(c.money);
//         c.house();
//     }
// }

// extends => child IS-A parent , child can access non-private members , JVM copies parent members logically but not physically 

// Super keyword => access parent class members , call parent class constructor
// super refersto the pareny class object part 
// => call parent constructor , access parent variables , access parent methods

// rules of super 
// 1. super() must be the first statement in child class constructor
// 2. super can be used to access parent class members when there is a name conflict

// class Parent {
//     Parent(int x) {
//         System.out.println("Parent: " + x);
//     }
// }

// class Child extends Parent {
//     Child() {
//         super(10); // MUST be first line
//         System.out.println("Child constructor");
//     }
// }


// accessing parent variables using super 
// class Parent {
//     int x = 10;
//     void display(){
//     System.out.println("Parent display");
//   }
// }

// class Child extends Parent {
//     int x = 20;

//     void show() {
//         System.out.println(x);        // 20
//         System.out.println(super.x);  // 10
//         super.display();          // Parent display
//     }
// }


// Method overriding (rutime polymorphism)

// child provides its own implementation of a parent method
// Rules => same method name , same parameters , IS-A relationship required 

// class Parent {
//     void show() {
//         System.out.println("Parent show");
//     }
// }

// class Child extends Parent {
//     void show() {
//         System.out.println("Child show");
//     }
// }

// Types of inheritace

// Single inheritance 

class A{}
class B extends A{}


// Multilevel inheritance

class A{}
class B extends A{}
class C extends B{}

// Hierarchical inheritance

class A{}
class B extends A{}
class C extends A{}

// Multiple inheritancec (Not allowed with classes)
class A {}
class B {}
class C extends A, B {} // ❌ ERROR

// but allowed with interfaces
interface A {
    void show();
}

interface B {
    void show();
}

class C implements A, B {
    public void show() {
        System.out.println("Resolved");
    }
}

// java supports multiple inheritances with interfaces only but not classes and constryctores cannot be inherited and we cannot override static methods ,  super() is in first line because parent must initialize first 

// Diamond problem in java

// diamond problem happends when a class inherits from 2 classes , both parent classes have same method , JVM gets confused about which method to call 
    //   A
    //  / \
    // B   C
    //  \ /
    //   D
// B and C both inherit from A , D inherits from both B and C and method conflicts occurs 

// B.show() ?

// C.show() ?

// JVM cannot decide and doent allow multiple inheritacne with classes to avoid ambiguity , avoid complex memory layout , to avoid complex memory layout , avoid runtime confusion and keep JVM simple and fast 

interface A {
    void show();
}

interface B extends A {
}

interface C extends A {
}

class D implements B, C {
    public void show() {
        System.out.println("Resolved diamond problem");
    }
}

// why no confusion here becauses interfaces do not provide implementation , child class must implement method , JVM knows exactly which method to run 

// Diamond problem with default methods 




















