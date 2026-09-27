
// // // //OOPS

// // // // object oriented programming is a programming model that organizes software design around objects rather than functions or logic. It is especially useful for building large and complex programs.
// // // // oops is generally a design of objects rathan than logic i.e it is mainly used when we have large code

// // // // It works on concept of classes and objects

// // // // class:A blueprint or template for creating objects.
// // // // object:A real-world entity created using a class
// // // // OOP focuses on grouping data and behaviour together using these classes and objects


// // // // A class is a template like a cookie cutter and objects like cookies make using that cutter
// // // // Once you define a class (say car) , you can create many car objects (Car car1, Car car2,etc).


// // // // Treats data as a critical element

// // // // unlike procedural programming, which focuses mainly on functions, oops emphasizes protecting and organizing data.
// // // // Data is bundled inside objects and accessed through methods , ensuring better control and security

// // // // In OOP , problems in objects and build data functions around the objects

// // // // here problems are broken down into smaller parts , each represented as an object. each object holds both data(attributes) and functions(methods) that operate on the data
// // // // each obejct hold both data(attributes) and functions(methods) that operate on the data
// // // // This makes the code more modular , reusable and easier to debug

// // // // ----------------------------------------------------------------------------

// // // // example:

// // // //    class Student{
// // // //    public:
// // // //          string name;
// // // //          int age;
// // // //               void study(){
// // // //                   cout<<name<<" is studying. "<<endl
// // // //               }
// // // //             };

// // // //     Student is a class
// // // //     name and age are data
// // // //     study() is a function(method)

// // // //     // we can create different objects like:

// // // //     Student s1;
// // // //     s1.name="Jaswanth";
// // // //     s1.age=18;
// // // //     s1.study();

// // // // ------------------------------------------------------------------------------

// // // // object-oriented programming is a style of programming that focuses on using objects and classes to design and build application , 
// // // // unlike older styles , where we write functions and data seperately , oop combines both data and functions that work on that data into single unit called object.

// // // // CORE concepts

// // // // 1)class -> basic template for creating objects
// // // // 2)objects -> basic run time entities
// // // // 3)Data abstraction & encapsulation -> wrapping data and functions into single unit
// // // // 4)inheritance -> properties of one class can be inherited into others
// // // // 5)polymorphism -> ability to take more than one forms
// // // // 6)Dynamic binding -> code which will execute is not known until the program runs


// // // // BENEFITS
// // // // Better code reusability using objects and inheritance
// // // // principle of data hiding helps build secure systems
// // // // multiple objects can co-exist without any interference 

// // // // what is an object?

// // // // An object is a real world instance created using class
// // // // if a class is a design for a car , then each actual car you see is an object.
// // // // we dont use class directly, we create objects from classes , the objects will have properties(data) and behaviors(functions) defined in the class.

// // // // class Car {
// // // // public:
// // // //     string color;
// // // //     void drive() {
// // // //         cout << "The car is driving" << endl;
// // // //     }
// // // // };

// // // // Car car1;  // Object created from class
// // // // car1.color = "Red";
// // // // car1.drive();

// // // // In oops data is treated as critical element

// // // // In OOP data is protected and considered very important
// // // // Data is not exposed directly , instead we encapsulate it using access modifiers
// // // // This provides data security,controlled access and prevents misuse

// // // // Encapsulation

// // // // class BankAccount{
// // // //     private:
// // // //        int balance;
    
// // // //     public:
// // // //        void deposit(int amount){
// // // //         balance+=amount;
// // // //        }
// // // //        int getBalance(){
// // // //         return balance;
// // // //        }
// // // // };


// // // // Abstraction 

// // // // Abstraction means showing only the essential details and hiding the background implementation.
// // // // For example, when we drive a car, we just use the steering and brakes. We don’t care about the engine’s internal logic.
// // // // in c++ we acheive it using abstract classes(with virtual functions) or interfaces


// // // class shape(){
// // //     public:
// // //        virtual function draw()=0; //pure virtual function makes class abstract
// // // };

// // // // Circle gives its own version of draw().
// // // class circle:public shape{
// // //     public:
// // //         void draw(){
// // //             cout<<"drawing circle";
// // //         }
// // // }

// // // // rectange also gives its own version of draw().
// // // class rectangle:public shape{
// // //     public:
// // //         void draw(){
// // //             cout<<"drawing rectangle";
// // //         }
// // // }

// // // int main(){
// // //     shape* s1=new circle(),s2=new rectangle;
// // //     s1->draw;
// // //     s2->draw;
// // // }


// // // // here shape* s1 is a pointer of base class type 
// // // // This is needed to achieve runtime polymorphism (so that the correct draw() is called depending on the object).


// // // // we can also write 
// // // // circle c;
// // // // shape* s1=&c

// // // // using new means we are dynamically allocating the object on the heap instead of the stack 

// // // // Heap allocation (new) → stays until we manually delete.
// // // // Stack allocation (normal object) → destroyed automatically when it goes out of scope.


// // // what is virtual ?

// // // virtual means this funciton supports overriding in derived classes,and at runtime the correct function will be called.

// // // with virtual :

// // // because of virtual, the function is decided at runtime not at compile time , this is called runtime polymorphism 

// // // class Animal {
// // // public:
// // //     virtual void sound() { cout << "Animal sound\n"; }
// // // };
// // // class Dog : public Animal {
// // // public:
// // //     void sound() { cout << "Dog barks\n"; }
// // // };
// // // int main() {
// // //     Animal* a = new Dog();
// // //     a->sound();   // Output: Dog barks ✅
// // // }


// // // without virtual:

// // // here base class function is called , because function binding happends at compile time 

// // // class Animal {
// // // public:
// // //      void sound() { cout << "Animal sound\n"; }
// // // };
// // // class Dog : public Animal {
// // // public:
// // //     void sound() { cout << "Dog barks\n"; }
// // // };
// // // int main() {
// // //     Animal* a = new Dog();
// // //     a->sound();   // Output: Dog barks ✅
// // // }

// // // new → used for dynamic allocation. It’s not mandatory, but often used with base class pointers to achieve polymorphism.
// // // virtual → allows overriding in derived class and enables runtime polymorphism.
// // // Pure virtual (=0) → makes the base class abstract, forcing derived classes to implement that function.

// // // Shape class says: “Every shape must implement draw()”.
// // // Circle and Rectangle each give their own version.
// // // Because of virtual, the correct version runs at runtime.
// // // new is used to create objects dynamically and store them in a base class pointer.

// // // Without virtual → function call is decided at compile time (early binding).
// // // With virtual → function call is decided at runtime (late binding / runtime polymorphism).
// // // That’s why we use virtual when we want different behavior in derived classes.




// // // // 2. Encapsulation

// // // // Encapsulation means binding data and methods together inside a class, and restricting direct access to the data (using private or protected).
// // // // For example, in ATM, we don’t access the balance variable directly; we use getter/setter methods.

// // // #include<bits/stdc++.h>
// // // using namespace std;

// // // class BackAccount{
// // //      private:
// // //          int balance;
// // //      public:
// // //         BankAccount(int initial){
// // //             balance=initial;
// // //         }
// // //         void deposit(int amount){
// // //             balance+=amount;
// // //         }
// // //         void withdraw(int amount){
// // //             if(amount<=balance){
// // //                 balance-=amount;
// // //             }else{
// // //                 balance=0;
// // //             }
// // //         }
// // //         int getBalance(){
// // //             return balance;
// // //         }
// // // }

// // // int main(){
// // //     BankAccount acC(100);
// // //     acc.deposit(500);
// // //     acc.withdraw(1000);
// // //     cout<<"final balance"<<acc.getBalance()<<endl;
// // // }




// // // polymorphism

// // // #include <iostream>
// // // using namespace std;

// // // // Compile-time polymorphism (function overloading)
// // // class Calculator {
// // // public:
// // //     int add(int a, int b) {
// // //         return a + b;
// // //     }
// // //     double add(double a, double b) {
// // //         return a + b;
// // //     }
// // // };

// // // // Runtime polymorphism (function overriding)
// // // class Animal {
// // // public:
// // //     virtual void sound() {
// // //         cout << "Animal makes a sound" << endl;
// // //     }
// // // };

// // // class Dog : public Animal {
// // // public:
// // //     void sound() {
// // //         cout << "Dog barks" << endl;
// // //     }
// // // };

// // // int main() {
// // //     Calculator c;
// // //     cout << "Sum int: " << c.add(2, 3) << endl;
// // //     cout << "Sum double: " << c.add(2.5, 3.7) << endl;

// // //     Animal* a = new Dog();
// // //     a->sound();  // Runtime polymorphism
// // //     return 0;
// // // }



// // // // inheritance

// // // // Inheritance means reusing code by deriving a new class (child) from an existing class (parent).
// // // // For example, a Car class can inherit from a Vehicle class.

// // // #include <iostream>
// // // using namespace std;

// // // class Vehicle {
// // // public:
// // //     void start() {
// // //         cout << "Vehicle started" << endl;
// // //     }
// // // };

// // // class Car : public Vehicle {
// // // public:
// // //     void drive() {
// // //         cout << "Car is driving" << endl;
// // //     }
// // // };

// // // int main() {
// // //     Car c;
// // //     c.start();  // Inherited method
// // //     c.drive();  // Own method
// // //     return 0;
// // // }


// // // Abstraction → Hiding implementation, showing only necessary details. (Abstract classes, interfaces)
// // // Encapsulation → Binding data + methods together, restricting direct access. (Private data + getters/setters)
// // // Polymorphism → One name, many forms. (Overloading, Overriding, virtual functions)
// // // Inheritance → Acquiring properties and methods of a base class. (Code reusability)



// // #include <bits/stdc++.h>

// // using namespace std;

// // int minPartitions(vector<int> used, vector<int> tot) {
// //     long long tha = 0;
// //     for (int x : used) {
// //         tha += x;
// //     }

// //     sort(tot.rbegin(), tot.rend());


// //     int par = 0;
// //     long long curr = 0;

// //     for (int cap : tot) {
// //         curr += cap;
// //         par++;
// //         if (curr >= tha) {
// //             return par;
// //         }
// //     }
// //     return par;
// // }

// // int main() {
// //     int n;
// //     if (cin >> n) {
// //         vector<int> used(n);
// //         for (int i = 0; i < n; i++) {
// //             cin >> used[i];
// //         }

// //         int m;
// //         cin >> m;
// //         vector<int> tot(m);
// //         for (int i = 0; i < m; i++) {
// //             cin >> tot[i];
// //         }

// //         int result = minPartitions(used, tot);
// //         cout << result << endl;
// //     }
// //     return 0;
// // }


// #include <bits/stdc++.h>

// using namespace std;

// string getString(string s) {
//     vector<int> count(26, 0);
//     vector<bool> vis(26, false);
    
//     for (char c : s) {
//         count[c - 'a']++;
//     }
    
//     string res = "";
    
//     for (char c : s) {
//         count[c - 'a']--;
        
//         if (vis[c - 'a']) {
//             continue;
//         }
        
//         while (!res.empty() && c > res.back() && count[res.back() - 'a'] > 0) {
//             vis[res.back() - 'a'] = false;
//             res.pop_back();
//         }
        
//         res.push_back(c);
//         vis[c - 'a'] = true;
//     }
    
//     return res;
// }

// int main() {
//     string s;
//     if (cin >> s) {
//         string result = getString(s);
//         cout << result << endl;
//     }
//     return 0;
// }




#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'encryptionValidity' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 * 1. INTEGER instructionCount
 * 2. INTEGER validityPeriod
 * 3. INTEGER_ARRAY keys
 */

vector<int> encryptionValidity(int one, int two, vector<int> keys) {
    int maxi = 0;
    for (int x : keys) maxi = max(maxi, x);
    
    vector<int> freq(maxi + 1, 0);
    for (int x : keys) freq[x]++;
    
    vector<int> div(maxi + 1, 0);
    for (int i = 2; i <= maxi; i++) {
        if (freq[i] == 0) continue;
        for (int j = i; j <= maxi; j += i) {
            div[j] += freq[i];
        }
    }
    
    int mox = 0;
    for (int x : keys) {
        mox = max(mox, div[x]);
    }
    
    long long strength = (long long)mox * 100000;
    long long attempts = (long long)one * two;
    
    return {attempts >= strength ? 1 : 0, (int)strength};
}

int main() {
    int one, two;
    if (cin >> one >> two) {
        int n;
        cin >> n;
        vector<int> keys(n);
        for (int i = 0; i < n; i++) {
            cin >> keys[i];
        }
        
        vector<int> result = encryptionValidity(one, two, keys);
        cout << result[0] << " " << result[1] << endl;
    }
    return 0;
}






vector<int> encryptionValidity(int one, int two, vector<int> keys) {
    int maxi = 0;
    for (int x : keys) maxi = max(maxi, x);
    
    vector<int> freq(maxi + 1, 0);
    for (int x : keys) freq[x]++;
    
    vector<int> div(maxi + 1, 0);
    // Count divisors including 1
    for (int i = 1; i <= maxi; i++) {
        if (freq[i] == 0) continue;
        for (int j = i; j <= maxi; j += i) {
            div[j] += freq[i];
        }
    }
    
    int mox = 0;
    for (int x : keys) {
        // For each key, count how many other keys it divides
        // Each key divides itself, so start from 1 (itself)
        mox = max(mox, div[x]);
    }
    
    // Use long long to avoid overflow
    long long strength = (long long)mox * 100000LL;
    long long attempts = (long long)one * (long long)two;
    
    return {attempts >= strength ? 1 : 0, (int)min(strength, (long long)INT_MAX)};
}

int main() {
    int one, two;
    if (cin >> one >> two) {
        int n;
        cin >> n;
        vector<int> keys(n);
        for (int i = 0; i < n; i++) {
            cin >> keys[i];
        }
        
        vector<int> result = encryptionValidity(one, two, keys);
        cout << result[0] << " " << result[1] << endl;
    }
    return 0;
}