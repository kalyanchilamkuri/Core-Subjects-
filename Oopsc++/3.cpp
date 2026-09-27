
// OOPS recap and Nesting of Members functions
// class => extension of structures
// structures had limitations
    // => members are public 
    // => No methods
// class => structures + more
// classes => can have methods and properties
// classes => can make few menmbers as private and public
// structures in c++ are typedefined

// ***********************************************************
// you can declare objects along with the class declaration like this:
    /*class Employee{
      // class defination
    } harry, rohan */

//harry.salary =8 makes no sense if salary is private
// Nesting of member functions


// what is a member function ?
// a member function is a function that belongs to a class.
// it is used to operate on the data members of that class.

// member functions can be defined inside the class and can also be defined outside of the class using the scope resolution operator

// 1)function defined inside the class 
#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int age;

    // Member function defined inside the class
    void showDetails() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    Student s;
    s.name = "Kalyan";
    s.age = 20;
    s.showDetails();  // ✅ calling member function
    return 0;
}


// 2)function defined outside the class 
#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int age;

    void setDetails(string n, int a);  // declaration only
    void showDetails();                // declaration only
};

// Function definitions outside the class
void Student::setDetails(string n, int a) {
    name = n;
    age = a;
}

void Student::showDetails() {
    cout << "Name: " << name << ", Age: " << age << endl;
}

int main() {
    Student s;
    s.setDetails("Thanusha", 19);
    s.showDetails();
    return 0;
}


// 3)inline member functions 
#include <iostream>
using namespace std;

class Math {
public:
    inline int add(int x, int y) {  // explicitly inline
        return x + y;
    }
};

int main() {
    Math m;
    cout << "Sum = " << m.add(5, 3) << endl;
    return 0;
}

//4) static member functions 

// when we use static inside a class 
// 1)the member belongs to the class itself , not to any specific object
// 2)so all objects share the same copy of that static member 

// static data members => static variables 
// static member functions => shared functions

// a static member function is a function that :
// 1) belongs to the class, not to any one object
// 2) can access only static data memebers or other static functions
// 3) can be called without creating an object
// a static function cannot access non-static data members directly

#include <iostream>
using namespace std;

class Counter {
    static int count;
public:
    static void increment() {
        count++;
        cout << "Count = " << count << endl;
    }
};

// Initialize static variable
int Counter::count = 0;

int main() {
    Counter::increment(); // ✅ can be called without object
    Counter::increment();
    Counter::increment();
    return 0;
}


// can only access static data members and can be called using className::functionName()


// 5)friend function 
#include <iostream>
using namespace std;

class Secret {
private:
    int code;
public:
    Secret(int c) { code = c; }
    friend void reveal(Secret s);  // friend declaration
};

void reveal(Secret s) {
    cout << "Secret code is " << s.code << endl; // allowed
}

int main() {
    Secret s(1234);
    reveal(s);
    return 0;
}


// a friend function is not a member of the class but it has access to the class's private and protected members



#include<bits/stdc++.h>
using namespace std;

class binary{
    string s; // by default members are private until unless specified
    public: // 2 public functions
       void read(void); // to input binary number from the user
       void chk_bin(void); // to check whether the input is a valid binary number
};

void binary :: read(void){  // reads the binary number as a string from the user and stores it in s.
    cout<<"Enter a binary number"<<endl;
    cin>>s;
}

// first void means that the function returns nothing
// second void means the function does not take any arguements

void binary :: chk_bin(void){ 
    for(int i=0;i<s.length();i++){
        if(s.at(i)!='0' && s.at(i)!='1'){
            cout<<"Incorrect binary format"<<endl;
            exit(0);
        }
    }
}

int main(){

    binary b;
    b.read();
    b.chk_bin();

    return 0;
      
}