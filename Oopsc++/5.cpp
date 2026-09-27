
// Static data members and methods

// static data members

// Declared using static inside the class.
// It’s shared across all objects of the class.
// Memory is allocated only once, not per object.
// Needs to be defined outside the class.

static int count; // inside class
int Employee::count = 0; // outside class



//Static Member Function
// Declared using static keyword.
// Can be called without any object using ClassName::functionName().
// It can only access static members, not normal ones.

//visualization

// *) Imagine a classroom(class) and students(objects):
//    each student can have their own name and roll number => (normal variables)
//    but the classroom has only one register shared by all => this is a static variable


//Static method

//A static function in a class can be called wihtout any object , and it can only access static members
// called with classname , belongs to the class , can access static variables 

#include <bits/stdc++.h>
using namespace std;

class Employee {
    int id;
    static int count;  // Static variable shared by all objects

public:
    void setData(void) {
        cout << "Enter the id: ";
        cin >> id;
        count++;
    }

    void getData(void) {
        cout << "The id is " << id << " and this is employee number " << count << endl;
    }

    static void getCount() {
        // cout<<id<<endl   //throws an error
        cout << "Total number of employees: " << count << endl;
    }
};

// Define static variable outside the class
int Employee::count = 0;

int main() {
    Employee a, b, c;

    a.setData();
    a.getData();

    Employee::getCount(); // Static function call without object

    b.setData();
    b.getData();

    Employee::getCount(); // Static function call without object

    c.setData();
    c.getData();

    Employee::getCount(); // Static function call without object

    return 0;
}





// static has different meanings depending on where it is used, inside a function,inside a class, outside at file scope

// static has different meanings depending on where it is used , inside a function , inside a class , outside at file scope

1)inside a function 

// a variable declared as static inside a function is created only once and keeps its value between function calls
#include <iostream>
using namespace std;

void counter() {
    static int count = 0;  // created once, lifetime = entire program
    count++;
    cout << "Called " << count << " times\n";
}

int main() {
    counter();  // Called 1 times
    counter();  // Called 2 times
    counter();  // Called 3 times
}

usecase: keeping function state (like remembering how many times a function was called);

2)static variable inside a class 

a static data member inside a class is shared by all the objects of the class, only one copy exists , no matter how many objects you create

#include <iostream>
using namespace std;

class Student {
public:
    static int totalStudents;  // declaration
    Student() { totalStudents++; }
};

// definition (outside the class)
int Student::totalStudents = 0;

int main() {
    Student s1, s2, s3;
    cout << "Total Students = " << Student::totalStudents << endl;  // 3
}

// usecase:keeping track of all values common to all objects

// 3)static member function in a class

// a static member function belongs to the class but not the objects
// we call it without creating an object
// it can only access other static members

#include <iostream>
using namespace std;

class Math {
public:
    static int square(int x) {
        return x * x;
    }
};

int main() {
    cout << "Square = " << Math::square(5) << endl;  // 25
}


// Static in function → variable retains value across calls.
// Static in class (variable) → shared by all objects.
// Static in class (function) → can be called without object; only works with static data.

