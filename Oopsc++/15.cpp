
// Copy constructor

//purpose of a copy constructor 
// *)a copy constructor is a constructor which creates a new object by copying an existing object.

// A obj1(10);         // calls parameterized constructor
// A obj2 = obj1;      // copy constructor is called here
// here obj2 is created as a copy of obj1.if you dont define a copy constructor, c++ automatically provides a default one that does a shallow copy (copies values bit by bit)

// shallow copy
// *)simply copies the values , pointers in both objects point to same memory 
// Deep copy
// *)Allocates seperate memory and copies actual data

// -------------------------------------------

#include<bits/stdc++.h>
using namespace std;

class Number{
  int a;
  public:
    Number(){
      a=0;
    }
    Number(int num){
      a=num;
    }
    // This is a copy constructor , It's called when a new object is created from an existing object.
    // const Number &obj means it takes a reference to an existing object, which is read only (due to const)
    // Inside , it prints a message to confirm that the copy constructor was used
    // Then it copies the value of a from obj to the new object
    Number(const Number &obj){
      cout<<"copy constructer called"<<endl;
      a=obj.a;
    }
    void display(){
      cout<<"value of a is: "<<a<<endl;
    }
};

int main(){
  Number x(5); // crerates an object x using the parameterized constructor 
  Number y=x;  // A new object y is created by copying x , so the copy constructor is called here, copying x.a(which is 5) into y.a , here the message "copy constructor called" is printed
  x.display(); // calls the display() function for the object x
  y.display(); 
  return 0;
}


// When is copy constructor called?
//  *)when an object is initialized from another object of the same class
//  *)when an object is passed by value to a function
//  *)when an object is returned by value from a function

// *) Deep copy => allocates new memory and copies actual data
// *) shallow copy => just copies pointers/values without duplicating memory




// copy => assigning one object to another
// c++ copies the contents of one object into another


// shallow copy => a shallow copy copies only the values of the data members , if the class has pointers , it copies only the address but not the actual data .....that means both the objects pointing to the same memory 

#include <iostream>
#include <cstring>
using namespace std;

class Student {
    char *name;
public:
    Student(const char *n) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    void show() { cout << "Name: " << name << endl; }

    // Default shallow copy constructor
    // (compiler creates automatically)
    ~Student() {
        delete[] name;
        cout << "Destructor called\n";
    }
};

int main() {
    Student s1("Jaswanth");
    Student s2 = s1;  // Shallow copy (default)
    s1.show();
    s2.show();
    return 0;
}


// s1 and s2 both point to the same name memory 
// when the program ends, both destructors try to delete the same memory
// this causes runtime error/double free/crash



// deepcopy => creates a new copy of dynamically allocated memory , it duplicates the actual data , not just the address
// so each object has its own memory 


// s1 and s2 each have seperate memory for the name
// so when destructors run, they free different memory blocks
// safe ....




#include<bits/stdc++.h>
using namespace std;

class Number{
    int a;
    public:
       Number(){
        a=0;
       }
       Number(int num){
         a=num;
       }
       // when no copy constructor is found , compiler supplies its own copy constructor
       Number(int &obj){
        cout<<"Copy constructor called"<<endl;
         a=obj.a;
       }
       void display(){
        cout<<"the number for this object is "<<a<<endl;
       }

}

int main(){
    Number x,y,z(45);
    x.display();
    y.display();
    z.display();
    Number z1(z);// copy contructor invoked 
    z1.display();
    z2=z;
    Number z3=z;// copy constructor invoked 

    // z1 should exactly resemble z or x or y




    return 0;
}























// what is a shallow copy ?

// a shallow copy copies all the member values of an object bit by bit , if the class has pointer members , it only copies the addresses, not the actual data.
// so both objects point to the same memory -> changes in one reflect another -> deleting one causes memory issues

// what is a deep copy?

// deep copy creates a new copy of dynamically memoery for each object
// so both objects have independent memory blocks and no interference



// when do we need a deep copy?

// whenever a class allocates dynamic memory using new => because the default copy contructor does shallow copy -> can lead to double deletion or dangling pointers.



//  copy constructor ==> called when a new object is created from an existing object
//  assignment operator ==> (=) called when both objects already exists


// shallow copy jusr copies values , including pointer addresses so both objects share the same memory 
// a deep copy duplicates the dynamically allcoted memory , so both objects are independent
// whenever a class uses a dynamic memory , I implement my own copy constructor to perform copy and avoid runtime errors


