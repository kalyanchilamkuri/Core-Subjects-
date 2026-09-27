// Tight coupling vs loose coupling 

//  Coupling 

// coupling => degree of dependency between classes or modules 
// high dependency => tight coupling 
// low dependency => loose coupling 

// Tight coupling => one class directly depends on another class , any change in one class forces changes in another class 

class Engine {
    void start() {
        System.out.println("Engine starts");
    }
}

class Car {
    private Engine engine = new Engine();

    void drive() {
        engine.start();
        System.out.println("Car is moving");
    }
}

// ❌ Car is tightly bound to Engine
// ❌ Cannot replace Engine easily
// ❌ Difficult to test
// ❌ Violates Dependency Inversion Principle


// TV remote works only with one TV brand
// If TV breaks → remote useless


// Loose coupling 

// loose coupling means classes depend on abstractions (interfaces) and implementation can change without affecting client 
// examples 
interface Engine {
    void start();
}

class PetrolEngine implements Engine {
    public void start() {
        System.out.println("Petrol engine starts");
    }
}

class ElectricEngine implements Engine {
    public void start() {
        System.out.println("Electric engine starts");
    }
}

class Car {
    private Engine engine;

    Car(Engine engine) {
        this.engine = engine;
    }

    void drive() {
        engine.start();
        System.out.println("Car is moving");
    }
}

// usage:
Engine e = new ElectricEngine();
Car car = new Car(e);
car.drive();

// ✔ Easy replacement
// ✔ Flexible design
// ✔ Clean architecture


// How to achieve loose coupling ?
// => use interfaces , dependency injection , use design patterns , tight coupling using new keyword 



// Final

// final is a non access modifier used to restrict modification 
// once something is declared final then it cannot be changed
// think of final as constant / fixed 

// final can be used with variables methods classes parameters 


// 1) final variables 

// a final variable can be assigned only once 
// becomes a constant 
// final int x=20 => x=10(invalid)

// 2) final instance variable 
class Test {
    final int x = 10;
}
// or intialized in constructor 

class Test {
    final int x;

    Test(int x) {
        this.x = x;
    }
}

//each object can have different value and must be initialized exactly once 

// 3)Final static variable

class Constants {
    static final double PI = 3.14;
}
// shared accross the class 


// 4)Final with object references 
final List<Integer> list = new ArrayList<>();
list.add(10);   // ✅ allowed
list.add(20);   // ✅ allowed

but list = new ArrayList<>(); // ❌ error
// final locks the reference but not the object 

// 5)Final method 
// a final method cannot be overridden but can be inherited 

class Parent {
    final void show() {
        System.out.println("Parent show");
    }
}

class Child extends Parent {
    // void show() { } ❌ error
}


// we use final methods to prevent modification of the critical logic , security , performance 


// 6)Final class 
// final class cannot be extended , no inheritance allowed 

final class Utility {
    void help() {
        System.out.println("Helping");
    }
}

class Test extends Utility { } // ❌ error


//  a final variable can be uninitialized 
// final methods can be overloaded 
// we can blank the final variable
// constructor can be final 


// summary 
// => variables -> constant 2)methods -> no override 3)classes -> no inheritance 4)reference ->cannot reassign 



// static keyword 

// static keyword belonging to the class but not the object 
// a static member is shared by all the me,bers of the class
// static => class level , non-static => object level

// static can be used with varibles methods blocks main methods nested classes 
// a static variable is craeted once when the class is loaded, shared among all objects , belongs to the class

class Student {
    static String college = "IIT";
    int id;
}



