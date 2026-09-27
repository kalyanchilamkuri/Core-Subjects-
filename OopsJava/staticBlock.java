
// what is a package => a package is a namespace groups related

// java
//  └── util
//      └── ArrayList.java

// these packages exists to organize large codebases , control access (public , protected , default)

// import tells the compiler where to find a class , ....import.java.util. imports only classes but not subpackages


// public class video2 => pubic -> accessible from anywhere , file name must match public class name 

// static void main(String[] args)
// why main is static? => because JVM does not create objects to start your program 
// Load class -> Find main -> Execute  ==>> no object exists yet so main must be static and jvm call it like className.main(args)

// why public => JVM is outside your package , it must be accessible 

// why void? => JVM doesnt expect any return value 

// why String[] args? => used to pass command-line arguements

// static vs non-static 

// 1) static    .....    stored in method area .....  belongs to class
// 2) non-static .....   Heap                  .....  object

// static method example 

// static void func() {
//     // greeting(); ❌ NOT ALLOWED

//     Main obj = new Main();
//     obj.greeting();
// }
// error occurs => 
    // 1) static metjods belong to class , cannot be used to access instance members directly 
    // 2) Because static exists before objects

// // this is illegal 
// static void func() {
//     greeting();
// }

// // Correct 
// static void func() {
//     Main obj = new Main();
//     obj.greeting();
// }


// Non-static Method 
// void greeting() {
//     fun();
//     System.out.println("Hello world");
// }


// why non-static cannot access static?
// Because static members exist even before object creation







public class staticBlock {
    static int a = 4;
    static int b;

    static {
        System.out.println("I am in static block");
        b = a * 5;
    }
}


// what is staticBlock?

// executes once,executes when class is loaded , used for complex static initialiaztion 

// execution order
// 1. Static variables
// 2. Static block
// 3. main()


// Main method

public static void main(String[] args){
    staticBlock obj=new staticBlock();
    System.out.println(staticBlock.a+staticBlock.b);
}

// static classes 
// outside class cannot be statuc , only the inner classes can be static 

//correct
class Outer {
    static class Inner {
        void show() {
            System.out.println("Static inner class");
        }
    }
}

// | Modifier  | Same Class | Same Package | Subclass | Everywhere |
// | --------- | ---------- | ------------ | -------- | ---------- |
// | public    | ✅          | ✅            | ✅        | ✅          |
// | protected | ✅          | ✅            | ✅        | ❌          |
// | default   | ✅          | ✅            | ❌        | ❌          |
// | private   | ✅          | ❌            | ❌        | ❌          |


// singleton class (interview favourite)

class Singleton{
    private static Singleton instance;

    private Singleton() {};
    
    public static Singleton getInstance(){
        if(instance==null) instance=new Singleton();
        return instance;

    }
}

// why private constructor?

// it prevents new Singleton;

// Final Summary (Memorize)

// static => belongs to class , loaded once , shared by all objects
// Non-static => belongs to project , created per instance 
// main() => public -> JVM access , static -> no object , void -> no return , String[] -> command-line args






