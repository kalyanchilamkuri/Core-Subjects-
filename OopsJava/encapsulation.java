// encapsulation in Java 

// encapsulation = binding data and methods together and protecting data from outside access 
// encapsulation is the process of wrapping data(variables) and methodsinto a single unit and restricting direct access to the data 


// with out encapsulation , anyone can change data and no control , bugs and security issues 
// with encapsulation => data is protected , controlled access , better maintainability 
// It is like a capsule medicine => data hidden inside 


// Encapsulation in Java => 3 rules 

// 1) make variables private 
// 2) provide public methods
// 3) control access using getters and setters 

// class Student{
//     private int age;

//     public void setAge(int age){
//         if(age>0){
//             this.age=age;
//         }
//     }

//     public int getAge(){
//         return age;
//     }
// }

// Student s = new Student();
// s.setAge(20);
// System.out.println(s.getAge());

// here we use private variable to prevent direct access , forces controlled modification , improves security 
// Encapsulation = Data Hiding + Control Access

// Benefits in encapsulation: 
// data security , easy modification , loose coupling , maintainability

// Note : encapsulation is not possible with public , protected , default access modifiers

// encapsulation => hides data , achieved using access modifiers , main focus is protection 
// abstraction => hides implementation , achieved using abstract class / interface , focus is design 


// Abstract class in Java

// An abstract class is a class that cannot be instantiated and may contain abstract methods
// abstract class exists to provide partial implementation , to act as a base class , to enforce child classes to implement behaviour


// Abstraction in Java

// abstraction means hiding unnecessary details and showing only what is required to the user.public class encapsulation
// abstraction is the process of hiding implementaion details and exposing only essential functionality to the user

// why it is needed?
// without abstraction => code becomes complex , user must know internal working ,hard to maintain 
// with abstraction => simpleusage , better security , easy modification 

// Abstraction in Java can be achieved using abstract classes and interfaces

// abstraction => hides implemenation , focuses on behaviur and acheived using abstract class / interface 
// encapsulation => hides data , docuses on data protection and achieved using access modifiers 

// Abstraction using abstract classes 

// Abstract class Basics 

// ab abstract class is a class that cannot be instantiated and may contain abstract methods

// Abstract Method => 

    // abstract void start(); 
    // no body , must be implemented by child class


// abstract class example 

abstract class vehicle(){
    abstract void start(); // what to do 

    void fuel(){ // common behaviour
        System.out.println("Vehicle is refueling");
    }
}


// child class

child car extends vehicle{
    void start(){
        System.out.println("Car is starting");
    }
}

vehicle v=new car();
v.start(); // Car is starting
v.fuel(); // Vehicle is refueling

// here abstract class vehicle provides common behaviour fuel() and enforces child classes to implement start() method

// key rules => cannot create object , can have 1)abstract methods 2) concrete methods 3) contructors 4)Instance variables 

// when to use abstract class => 1) when we have IS-A relationship 2) when we want to provide common behaviour 3) when we want to enforce child classes to implement methods

// use when 1)classes are closely related , when we want shared implementaion and partial abstraction


// Abstraction using interface

// Interface => an interface is a blueprint that defines behaviour without implementaion 

// interface Payment{
        //    void pay(int amount);
// }

// implementing class:

// class CreditCardPayment implements Payment {
//     public void pay(int amount) {
//         System.out.println("Paid " + amount + " using Credit Card");
//     }
// }

// Payment p = new CreditCardPayment();
// p.pay(500);

// rules 
// 1) methods are public abstract by default , variables are public static final , no constructors , supports multiple inheritance 

// interface with default methods , static methods 


// abstract class when => you want base class , you share code , classes are related
// interface => you need multiple inheritance , you want loose coupling , you define a contract 

// abstraction cannot exists without encapsulation 
// abstract class can have non abstract methods , interface can have method body 


// We want to design a system for payments , different payment methods: 1) credit card 2)upi 

// 1) using abstract class 

// create abstract class 

abstract class Payment {

    // abstract method (WHAT to do)
    abstract void pay(int amount);

    // concrete method (COMMON behavior)
    void receipt() {
        System.out.println("Payment receipt generated");
    }
}

// payment is abstract , it defines common structure , it provides partial implementation 

// step-2 -credit card 

class CreditCardPayment extends Payment{
    void pay(int amount){
        System.out.println(amount);
    }
}

// step-3 - child class - upi 

class UPIpayment extends Payment{
    void pay(int amount){
        System.out.println(amount);
    }
}

use abstract class reference 

public class Main {
    public static void main(String[] args) {

        Payment p;

        p = new CreditCardPayment();
        p.pay(500);
        p.receipt();

        p = new UPIPayment();
        p.pay(300);
        p.receipt();
    }
}


// Program using interface 

// step-1) create interface

interface Payment {
    // abstract method by default
    void pay(int amount);
}

// no implementation , only contract 

// step-2) credit card implementation

class CreditCardPayment implements Payment {
    public void pay(int amount) {
        System.out.println("Paid " + amount + " using Credit Card");
    }
}

// step-3) Upi implementation 

class UPIPayment implements Payment {

    public void pay(int amount) {
        System.out.println("Paid " + amount + " using UPI");
    }
}

// step-4) use interface reference 

public class Main {
    public static void main(String[] args) {

        Payment p;

        p = new CreditCardPayment();
        p.pay(500);

        p = new UPIPayment();
        p.pay(300);
    }
}


// Interface give us full abstraction , loose coupling , multiple 






    




