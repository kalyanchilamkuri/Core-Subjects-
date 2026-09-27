// Java is object oriented i.e to organize large programs we use reusable components , make maintainance easy

// 1) constructor --> no return type , name=class name , called automatically
// 2) static methods are not polymorphic (called method hiding)
// 3) 


// 1)Class 

// a class is a blueprint , it describes what data an object stores (field/attributes) and what actions it can perform (methods). a class itself doessnot occupy memory only when objects are created using new 

// 2)Object 

// object is a living instance of class 

// // stack Car c1 = new Car() // heap; ...=> when we write this line , object is created in the heap memory and the reference c1 is stored in stack memory.

// 3) Constructors

// Constructors are special methods used to initialize the objects 

// properties of constructors --->> no return type , name=class name , called automatically , used to set the initial values 

// types are default , parameterized , copy , overloaded , private contructors(singleton pattern)

// Default contructor --> JVM gives it automatically only if you dont create any constructor 

class A {
    A() {
        System.out.println("Default constructor");
    }
}

// parameterized constructor --> it consists of parameters 

class Student {
    String name;
    int age;

    Student(String name, int age) {
        this.name = name;
        this.age  = age;
    }
}


// copy contructor --> we create it manually 

class Student {
    String name;
    int age;

    Student(Student s) {
        this.name = s.name;
        this.age = s.age;
    }
}


// Deep copy vs shallow copy 

// shallow copy => new object is created but reference are not copies (both objects points to the same memory) // shallow copy==> both objects point to the same memory 

// Deep copy => new object is created , internal objects also copied , completely independent // 


// contructor overloading 
class Box {
    int length, width;

    Box() {
        length = width = 1;
    }

    Box(int x) {
        length = width = x;
    }

    Box(int l, int w) {
        length = l;
        width = w;
    }
}

// private contructor (singleton pattern) --> used to prevent object creation from outside

// design pattern where a class allows only object to create at the runtime 

class Singleton {
    private static Singleton instance;

    private Singleton() {}

    public static Singleton getInstance() {
        if(instance == null)
            instance = new Singleton();
        return instance;
    }
}

// 5)This keyword ==> reference to the current object 

// uses of this --> 
// 1) differentiate between variables

class A {
    int x;

    A(int x) {
        this.x = x;  // unnecessary without this, wrong binding
    }
}

// 2) calling parameterized contructor 

A() {
    this(10);   // calls parameterized constructor
}


// returning the current object 

A show() {
    return this;
}


// 6)Super keyword 

// used to access parent class members 

// 1)access parent variable 2) call parent method 3) call parent constructor (must be first line)

// parent vs child variable 
class A {
    int x = 10;
}

class B extends A {
    int x = 20;

    void show() {
        System.out.println(super.x);  // 10
        System.out.println(this.x);   // 20
    }
}

// calling parent constructor 

class A {
    A() { System.out.println("Parent"); }
}

class B extends A {
    B() {
        super();   // calls A()
        System.out.println("Child");
    }
}

// Inheritance(JVM behavior)

// types of inheritance in Java 

// single multilevel hierarchical mutiple(interfaces) hybrid (via interface)

// java does not allow multiple inheritance => reason is diamond problem => java uses interfaces instead 

class Animal {
    String color = "Brown";

    void eat() {
        System.out.println("Animal eats");
    }
}

class Dog extends Animal {
    String breed = "German Shepherd";

    void bark() {
        System.out.println("Dog barks");
    }
}


// polymorphism 

// polymorphism = many forms.

// 2 types 1) compile time polymopshism 2)runtime polymorphism 

// compile time polymorphism (overloading) (overloading is called compile time polymorphism)

int add(int a, int b)
int add(int a, int b, int c)
double add(double a, double b)

// --> same method , different parameters , return type may change 

// runtime polymorphism (overriding)

class A {
    void show() { System.out.println("A"); }
}
class B extends A {
    void show() { System.out.println("B"); }
}

A obj=new B();
obj.show() // print B

// why B? -> because destination object decides methods = dynamic dispatch

class A {
    static void show() {}
}
class B extends A {
    static void show() {}
}


This is not overriding.  
It is **method hiding** because static methods are not polymorphic

---

# 🔥 **7.9 ABSTRACTION — Hiding Implementation**

Two ways:
1. Abstract classes  
2. Interfaces  

---

# ⭐ **7.9.1 ABSTRACT CLASS (DETAILED)**

~~~java

abstract class Shape {
    abstract void draw();
    void info() { System.out.println("Shape info"); }
}




// static 

// memory allocation , object creation , class loading , method overloading , design patterns 

// if something is static => it is loaded only once, it is stored in method area (a part of JVM memory) , all objects share it , it can be used without creating an object

// varibles , methods , blocks , nested classes , imports 

// a)static variables (also called class variables)

// these variables belong to the class , not instances 

class Counter {
    static int count = 0;    // static variable
    int normal = 0;          // instance variable

    Counter() {
        count++;
        normal++;
    }
}

// count is created once in Method Area.
// All objects share the same variable.
// normal is created separately for each object.

// b) static methods => a static method belongs to the class , cannot access non-static data directly , can be called without creating an object 

class MathUtil {
    static int square(int x) {
        return x * x;
    }
}

// static methods cannot use non-static variables because static methods are loaded into memory before any object is created and non-static variables belong to objects and they dont even exist at the time 


| Item              | Static Method Access? |
| ----------------- | --------------------- |
| static variable   | ✔ Yes                 |
| static method     | ✔ Yes                 |
| static block      | ✔ Yes                 |
| instance variable | ❌ No                 |
| instance method   | ❌ No                 |
| this / super      | ❌ No                 |


// static block  --> a static block runs only once, when the class is loaded , before main methods and used to initialize static variables and to execute startup logic 

class A {
    static int x;

    static {
        System.out.println("Static block executed");
        x = 10;
    }
}


// static class (nested static class)

// we cannot make a top level class static but we can make nested classes static 


// static import --> used to import static members so we dont need prefix 

import static java.lang.Math.*;

System.out.println(sqrt(25));    // instead of Math.sqrt()
System.out.println(PI);          // instead of Math.PI

// main method must be static why? ==> JVM compiles main method before creating any objects , if it was not static , JVM would need an object --> but whose object?


| Feature                | Static           | Non-static    |
| ---------------------- | ---------------- | ------------- |
| Memory                 | Method Area      | Heap          |
| Belongs to             | Class            | Object        |
| Access                 | ClassName.member | object.member |
| Needs object?          | No               | Yes           |
| Can access non-static? | ❌ No             | ✔ Yes       |
| loaded                 | once             | per object    |


// static cannot access nonstatic 

// static methods cannot be overridden because they belong to class.

// static variables cannot be overridden 

// constructors cannot be static because constructors depends on objects 

// interfaces can have static methods 

// static block run when the class is loaded 

// static variables are stored in methods area because they belong to class metadata


class A {
    static { System.out.println("Static Block"); }
    { System.out.println("Instance Block"); }
    A() { System.out.println("Constructor"); }
}

// order of execution is static block, instance block , contructor 


// ============ FINAL =================

// final means cannot be changed after the creation 

// but it behaves differently depending on where we use it 

// we apply final to variables , methods , classes ==> each has different rules 

// Final variables (constant)

// rule : --> a final variable must be assigned exactly once. 

final int x = 10;
// x = 20;   // ❌ ERROR: cannot change

// when must final variables be initialized ? --> we can initialize at declaration , in a constructor , in an instance block 


final int a;
final int b;

{
    a = 10;      // allowed
}

FinalTest() {
    b = 20;      // allowed
}



final int y;
y = 40;   // allowed
~~`

---

# 🔥 **1.1.1 FINAL REFERENCE VARIABLE (VERY IMPORTANT)**

Final reference means:
- the reference cannot change  
- but the object CAN change  

Example:

~~~java
final StringBuilder sb = new StringBuilder("Hi");
sb.append(" Java");     // ✔ allowed
// sb = new StringBuilder();  // ❌ not allowed


// Final methods 

// final methods cannot be overridden and final classes cannot be inherited

class A {
    final void display() {}
}

class B extends A {
    void display() {}  // ❌ ERROR
}

// final methods cannot be overridden , final classes cannot be inherited.

// because to prevent modification of parent class behavior 

// final class cannot be inherited 


final class Car {}

// class BMW extends Car {}   // ❌ ERROR

// --> used when we want to prevent inheritance , avoid overriding and create fully immutable classes



// final + static --> static 

// static -> one copy , final --> value cannot be changed 


void show(final int x) {
    // x++;   // ❌ cannot modify
}


// final + constructor 

// final variables can be initialized inside constructor to support immutability 

class Student {
    final int id;

    Student(int id) {
        this.id = id;
    }
}


// each object gets a unique immutable value.



// final methods can be overloaded , final variables can be uninitialized , contructor cannot be final , abstract class cannot be final.

// string is final (security , performance , caching ,hashcode immutability)

// Constructor cannot be final because constructors are not inherited and cannot be overridden, and final is used only to prevent overriding.


// This 

// this refers to the current object 

// we need this -->> when method parameters and instance variables have same name 

class Test {
    int x;

    Test(int x) {
        this.x = x;     // left = instance, right = parameter
    }
}

// use cases --> accessing instance varibles (clear name conflict) ==> 

class A {
    A() {
        this(10);
        System.out.println("Default");
    }

    A(int x) {
        System.out.println("Parameterized");
    }
}



// passing current object 

class A {
    void display(B b) {}
    void show() {
        display(this);
    }
}


// this cannot be used in static context because this requires an object 

// this and super cannot be used together because both must be in the first statement ********** 

// this in constructors is used for code reusability 

// ====== super 

// super means immediate parent object  ==> used in inheritance only 

// 1) when parent class and child class have same varible name 

// 2) calling parent class methods 

// 3) calling parent constructor 

// ==> must be first line of the constructor , cannot be used in the static context , cannot be used to access parent class private members , can be used only in child classes 


// | Feature              | this                  | super                    |
// | -------------------- | --------------------- | ------------------------ |
// | Refers to            | current object        | parent object            |
// | Used for             | accessing own members | accessing parent members |
// | Constructor call     | this()                | super()                  |
// | Must be first line?  | Yes                   | Yes                      |
// | Can appear together? | ❌ No                  | ❌ No                  |



// what is inheritance 

// inheritance means : a child class acquiring properties and behaviours of a parent class 

// if b extends a => b gets access to all non-private members of a , b can add new features , b can override behavior

// code reusability , method overriding , abstraction and architecture , polymorphism , hierarchical organization 

// Types of inheritance in Java

// 1) single , multilevel , hierarchical , hybrid (via interface)  , multiple inheritance(via classes)

// 1) single inheritance--> one parent->one child 

class A {}
class B extends A {}

// 2) multilevel inheritance-->  A->B->C (every level inherits everything from the above)
class A {}
class B extends A {}
class C extends B {}

// 3) hierarchical inheritance(one parent->many children)
class A {}
class B extends A {}
class C extends A {}

// 4) Hybrid inheritance(allowed via interface) --> since interfaces support multiple inheritance 
interface A {}
interface B {}
class C implements A, B {}


// why java doesnot support multiple inheritance?

// diamond problem --> 

   A
  / \
 B   C
  \ /
   D

// which method should D inherit ?
// to avoid ambiguity , java disallows it for classes 
// but it allows it for interfaces (java resolves it using default method rules)


// constructor execution order in inheritance 

// --> first parent then child 

// super() and constructor chaining 

// class B extends A {
//     B() {
//         super(); // inserted by JVM if not present
//     }
// }




// overriding and inheritance 

// overriding allows child to provide new version of parent's method 

class A {
    void show() { System.out.println("A"); }
}

class B extends A {
    void show() { System.out.println("B"); }
}


// --- Dynamic method dispatch  ==> It is a process where method call is decided at run time but not at compiler time 

// parent reference -> child object 

A obj = new B();
obj.show();   // B's version

// why B? --> 

// because reference type decides accessible methods at compile time 
// object type decides behavior at runtime 

// this is run time polymorphism 


| Modifier  | Inherited? | Accessible in child? |
| --------- | ---------- | -------------------- |
| private   | YES        | NO                   |
| default   | YES        | same package only    |
| protected | YES        | YES                  |
| public    | YES        | YES                  |


// composition vs inheritance

// use inheritance when : there is clear "IS-A" relation ship , behavior need overriding 
// use composition when : behavior uses "HAS-A" relationship , loose coupling is required , flexibility is needed.

// Car HAS-A Engine
// Not Car "is-a" Engine


public → protected → default → private
```

Must override with equal or higher visibility

---

# ⭐ **15. Deep Interview Questions on Inheritance**

### ✔ Basic
1. Why does Java not support multiple inheritance via classes?  
2. Name inheritance types in Java.  

### ✔ Medium
3. What is constructor chaining?  
4. Why does parent constructor run first?  
5. Can we override private methods?  

### ✔ Advanced
6. Explain dynamic dispatch.  
7. What is diamond problem?  
8. Difference between composition and inheritance?  
9. What happens if parent has only parameterized constructor?  

---

# ✔ INHERITANCE IS NOW FULLY EXPLAINED



// polymorphism 

// alowing same method name to behave differently based on 

// type of object
// type/number of parameters
// runtime object type

// Java supports :
// 1) compiler-time polymorphism -> method overloading 
// 2) runtime polymorphism -> method overriding 



// multiple methods have same name but different parameters 

// difference can be number of parameters , type of parameters , order of parameters 

class Calculator {

    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }
}

// RULES of Overloading

// Must differ in:
// number of params
// OR type of params
// OR order of params


// run time polymorphism 

// run time polymorphism happens when the method execution depends on the object created , not the reference type 



// class Animal {
//     void sound() { System.out.println("Animal sound"); }
// }

// class Dog extends Animal {
//     void sound() { System.out.println("Bark"); }
// }

// class Cat extends Animal {
//     void sound() { System.out.println("Meow"); }
// }


// Animal a;

// a = new Dog();
// a.sound();  // Bark

// a = new Cat();
// a.sound();  // Meow







// dynamic method dispatch 

// JVM 1) looks at the reference type -> decides which method can be called 
// 2) look at the object type -> decides which implementation to run 

Animal a = new Dog();
a.sound();

// Compile-time:
// Compiler checks:
// does Animal have a method named sound()? Yes → OK.

// Runtime:
// JVM checks:
// what object is stored in variable a? Dog
// execute Dog’s version of sound()


// rules of method overriding --> 1) same method signature (name + parameters) 2) return types must be same or covariant return types allowed 

// final , static , private methods cannot be overridden 











// Binding (static vs dynamic)

// 1) static binding (compile-time)

// used for : 1) overloading 2) static methods 3) private methods 4) final methods 

// 2) dynamic binding (run time) used for overridden methods 




// | Feature             | Overloading    | Overriding                  |
// | ------------------- | -------------- | --------------------------- |
// | Polymorphism Type   | Compile-time   | Runtime                     |
// | Signature           | Must differ    | Must match                  |
// | Access modifier     | No restriction | Cannot reduce               |
// | Static allowed?     | Yes            | No                          |
// | Return type         | Can differ     | Must be same (or covariant) |
// | Inheritance needed? | No             | Yes                         |
// | Binding             | Static         | Dynamic                     |



// static overriding is not real overriding 
// overriding return type cannot change arbitarily 
// private methods dont override 
// variables cannot be overriden 

class A { int x = 10; }
class B extends A { int x = 20; }

A obj = new B();
System.out.println(obj.x);   // 10 (NOT 20)


// methods -> dynamic variables -> static 

// primitive types cannot be overridden 

// covariant return type in java allows an overridden method in a child class to return a more specific type than the return type of the method in the parent class. the return type must be a subclass of parent methods type 

What is polymorphism?

What is method overriding?

What is method overloading?

✔ Medium

Difference between overriding vs overloading?

Why static methods cannot be overridden?

What is dynamic dispatch?

✔ High-Level

What is covariant return type?

Can a private method be overridden?

Why variables cannot be overridden?

Explain method hiding.
// Method hiding happens when a child class defines a static method with the same name as a static method in parent class.

What is the difference between static and dynamic binding?

Why runtime polymorphism is important for frameworks?

// primitive datatypes are basic datatypes (8) --> byte short int char long float double boolean 

// functional interface--> interface having only one abstract method 
// Functional method is a method inside a functional interface. 
// Because this single method represents the function/logic of interface 


//  Abstraction in java - most detailed explanation possible 

// abstraction = hiding implementation details and showing only required functionality 

// Abstraction helps in:
// reducing complexity
// increasing security
// hiding unnecessary details
// achieving loose coupling
// making frameworks reusable
// preventing misuse of internal logic
// Abstraction is achieved using:
// ✔ Abstract classes
// ✔ Interfaces



// abstract class is a class that cannot be instantiated and may contain abstract methods 

abstract class Shape {
    abstract void draw();
}

Shape s = new Shape();   // ❌ ERROR

// features 

// 1) can have abstract and non-abstract methods 

abstract class A {
    abstract void run();
    void stop() { System.out.println("Stopped"); }
}

// 2) can have contructors 

abstract class Car {
    Car() { System.out.println("Car created"); }
}


// 3) can have instance , static, final variables 

// 4) can have static , final methods 

// abstract methods cannot have body 
abstract class Shape {
    abstract void draw();   
    
    void info() {
        System.out.println("This is a shape.");
    }
}

class Circle extends Shape {
    void draw() {
        System.out.println("Drawing circle");
    }
}

Shape s = new Circle();
s.draw();
s.info();


// use abstract classes when we want partial implementation , we require common code + force certain methods , shared state accross child classes , we need constructor logic 

// limitations => only single inheritance , cannot achieve 100% abstractions , child classes must implement abstract methods 


// Interfaces in java --> to represent capabilities or behaviors that a class can have 

// runnable , comparable , serializable , cloneable 


// interfaces cannot have constructors , instance variables (only constants allowed)


// all the variables in the interfaces are implicitly public static final 

interface Vehicle {
    default void horn() {
        System.out.println("Beep!");
    }
}
```

Child class can override or use as is.

---

# ⭐ **4.6 Static Methods (Java 8)**

Cannot be overridden.

~~~java
interface A {
    static void show() { System.out.println("Static method"); }
}


A.show();   // directly using interface
```

---

# ⭐ **4.7 Private Methods (Java 9)**

Used for helper code inside interface.

~~~java
interface A {
    private void helper() {
        System.out.println("Helper method");
    }
}
```

---

# ⭐ **4.8 Multiple Inheritance in Interfaces**

Java allows this:

~~~java
interface A {}
interface B {}
class C implements A, B {}
```

If both interfaces contain default methods with same signature:

~~~java
interface A {
    default void show() { System.out.println("A"); }
}

interface B {
    default void show() { System.out.println("B"); }
}

class C implements A, B {
    public void show() { A.super.show(); }  // MUST resolve
}
```

This is **how Java solves diamond problem**.

---

# ⭐ **4.9 Abstract Class vs Interface (FULL TABLE)**



| Feature | Abstract Class | Interface |
|---------|----------------|------------|
| Inheritance | Single | Multiple |
| Variables | Anything | public static final only |
| Methods | abstract + concrete | abstract + default + static + private |
| Constructor | Yes | No |
| Access Modifiers | Any | Only public |
| Use-case | shared behavior | capabilities/contract |
| Abstraction Level | 0 to 100 percent | 100 percent (before Java 8) |

---

# ⭐ **5. REAL-WORLD EXAMPLES**

### ✔ Interface example:
Anything that *can fly*:

~~~java
interface Flyable { void fly(); }
class Bird implements Flyable { public void fly() {} }
class Airplane implements Flyable { public void fly() {} }
```

### ✔ Abstract Class example:
All vehicles have:
- engine  
- wheels  

But their starting behavior differs.

~~~java
abstract class Vehicle {
    void wheels() { System.out.println("Has wheels"); }
    abstract void start();
}
```

---

# ⭐ **6. IMPORTANT INTERVIEW QUESTIONS**

### ✔ Basic
1. What is abstraction?  
2. What is an abstract class?   // a class that cannot create an object 
3. What is an interface?  // blueprint that implements class , no contructor , cannot create object , only abstract methods , public static final , 

### ✔ Medium
4. Why interface cannot have constructors?  // contructor is used to create an object but interfaces cannot create object 
5. Can abstract class have constructor?  // yes (coz it is used when child class is created)
6. What are default methods?  // They allow adding new methods in interface without breaking old code.

### ✔ Advanced
7. Explain difference between interface and abstract class.  
8. Why Java allows multiple inheritance only through interfaces?  
9. What is diamond problem?  
10. How Java solves diamond problem in interfaces?  
11. Why variables in interface are public static final?  
12. Can interface have private methods?  




// Encapsulation -> bundling data (variables) and methods (operations) together inside a single unit (class) and restricting direct access to that data 

// focus is to protect the data 
// wrapping -> data +methods , hiding -> direct data acces blocked 






// four ingredients of encapsulation 

// 1) private variables 2) public getters 3) public setters 4) validation inside setters 

class Account {
    private double balance;      // 1. Hide the data

    public void setBalance(double b) {   // 2. Public setter
        if(b >= 0)                      // 3. Validation
            balance = b;
    }

    public double getBalance() {        // 4. Public getter
        return balance;
    }
}

| Modifier  | Class | Package | Subclass | World |
| --------- | ----- | ------- | -------- | ----- |
| private   | ✔     | ❌       | ❌        | ❌     |
| default   | ✔     | ✔       | ❌        | ❌     |
| protected | ✔     | ✔       | ✔        | ❌     |
| public    | ✔     | ✔       | ✔        | ✔     |

// strong encapsulation --> variables => private , methods => public/protected 

| Feature    | Encapsulation      | Abstraction                 |
| ---------- | ------------------ | --------------------------- |
| Focus      | Protect data       | Hide complexity             |
| Means      | Access modifiers   | Abstract classes/interfaces |
| Visibility | Controls access    | Shows essential behavior    |
| Purpose    | Security + control | Simplify design             |
| Example    | private fields     | abstract method             |


acc.balance = -1000;     // ❌ illegal
```

Why?
Because backend developers must protect money.

Correct usage:
~~~java
acc.deposit(500);
acc.withdraw(200);
```

Inside these methods, there is validation:
- prevent overdraft  
- prevent invalid amount  
- prevent negative value  

---

# ⭐ **9. Bad Example (NO Encapsulation)**

~~~java
class Person {
    public int age;
}
```

Anyone can set:

~~~java
p.age = -5;     // ❌ nonsense but allowed
```

Bad design.  
Breaks business rules.

---

# ⭐ **10. Good Example (Proper Encapsulation)**

~~~java
class Person {
    private int age;

    public void setAge(int age) {
        if(age > 0 && age < 120)
            this.age = age;
    }

    public int getAge() {
        return age;
    }
}
```

Now invalid ages are blocked.

---

# ⭐ **11. Encapsulation + Packages**

Java supports hierarchical organization:

~~~java
package bank;

public class Account {
    private double balance;
}
```

Even if another class in different package tries:

~~~java
acc.balance     // ❌ not visible
```

Encapsulation extends across packages.

---

# ⭐ **12. Encapsulation Enables Unit Testing**

Testing setter validation:

~~~java
@Test
public void testInvalidBalance() {
    Account a = new Account();
    a.setBalance(-100);

    assertEquals(0, a.getBalance());  // still 0
}
```

Encapsulation makes testing predictable.

---

# ⭐ **13. Deep Interview Questions on Encapsulation**

### ✔ Basic
1. What is encapsulation?  
2. Why do we need getters and setters?  

### ✔ Medium
3. Why should variables be private?  
4. What is data hiding? //  Data hiding means hiding internal data of class from outside world.
5. How does encapsulation increase security?   // variables are private , direct access is not allowed 

| Encapsulation            | Abstraction                   |
| ------------------------ | ----------------------------- |
| Hides data               | Hides implementation          |
| Uses private variables   | Uses abstract class/interface |
| Focus on security        | Focus on design               |
| Example: getters/setters | Example: interface            |


### ✔ Advanced
6. How does encapsulation lead to immutability?  //  immutable object=cannot change afeter creation (value set only once via constructor)
7. Difference between encapsulation and abstraction.  
8. How encapsulation reduces coupling?  
9. Can encapsulation exist without abstraction? (Yes → different concepts)  
10. How does JVM enforce encapsulation internally?  

---

# 🎯 ENCAPSULATION CHAPTER COMPLETED 100%

Next chapters will be delivered in the same **ultra-detailed** style:

## ✔ **CONSTRUCTORS (super deep) NEXT**  
Types, rules, chaining, edge cases, JVM behavior  
Then:

## ✔ Exception Handling  
## ✔ Strings & Memory Model  
## ✔ Collections Framework (very long & important)  
## ✔ JVM & Memory Model  

Just say **“continue”** and I will drop the next chapter immediately.


// shallow copy --> copy only the top level architecture --> a shallow copy creates a new object , but copies references of nested objects instead of duplicating them(i.e sharing) 
// deep copy --> duplicates everything including nested objects --> copy the structure and all nested objects




// functional methods usually refers to methods used in functional programming style mainly with:
// 1)Lamba expressions 2)Functional Interfaces

// Functional Interface ==> a functional interface is an interface with only one abstract method 

// predicate --> return boolean

// functional methods are used in functional programming style in java , mainly through interfaces and lambda expressions. A functional interface contains a single abstract method , this method is called a functional method.


// data hiding ==> protecting data from direct access 
// Data hiding means restricting direct access to variables and allowing access only through methods.

// encapsulation ==> wrapping data+methods into one unit and controlling access 
// Encapsulation is wrapping data and methods together into a single unit and controlling access using access modifiers.

// encapsulation=data hiding + methods


// Data hiding is the process of restricting direct access to variables using access modifiers like private. Encapsulation is the process of wrapping data and methods together into a single unit and controlling access through methods. Data hiding is a part of encapsulation.