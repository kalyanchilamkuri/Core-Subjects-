
// Consturctors in c++
// constructor is a special member function of the class that is automatically called when an object is created.
// Its main job is to initialize the object.

// It must have same name as class
// No return type (i.e we dont write void or int before the constructor)
// automatically invoked


// why we use a constructor

// without a construcor , you'd have to write a function like setValue(a,b) and manually initialize the object.

#include<bits/stdc++.h>
using namespace std;

class Complex{
    int a,b;
    public:
      // creating a constructor 
      // constructor is a special member function with the same name as of the class. It is autmatically invoked when ever an object is created
      // It is used to initialize the objects of its class

      Complex(void); // constructor declaration

      void printNumber(){
        cout<<" Your number is "<<a<<" + "<<b<<" i "<<endl;
      }
};

Complex :: Complex(void){  // ---> This is a default constructor as it takes no parameter
    a=0;
    b=0;

}

int main(){
    Complex c1,c2,c3;
    c1.printNumber();
    c2.printNumber();
    c3.printNumber();
    return 0;
}

/* characteristics of constructors

*) It should be declared in the public section of the class
*) They are automatically invoked whenever the object is created
*) Do not have return values and do not have return types
*) It can have default arguements
*) We cannot refer to their address
*/

// default constructor 

#include<bits/stdc++.h>
using namespace std;

class Student{
  int roll;
  string name;
  public:
      Student(){
        roll=0;
        name="unknown";
        cout<<"hello";
      }

      void display(){
        cout<<roll<<" "<<name<<endl;
      }
}

int main(){
    Student s;
    s.display();
    return 0;
}












// parameterized constructor

#include<bits/stdc++.h>
using namespace std;

class Student{
  int roll;
  string name;
  public:
      Student(int r,string k){
        roll=r;
        name=k;
        cout<<"constructor called";
      }
}


int main(){
  Student s(5,"hello");
  s.display();
  return 0;
}


//copy constructor => used to create a new object as a copy of an existing object.

#include<bits/stdc++.h>
using namespace std;

class Student{
  int roll;
  string name;
public:
   Student(int r,string k){
    roll=r;
    name=k;
   }

   Student(const Student&s){
       roll=s.roll;
       name=s.name;
       cout<<"copy constructor called";
   }

   void display(){
    cout<<roll<<" "<<name<<endl;
   }
}


int main(){
    Student s1(101,"Jaswanth");
    Student s2(s1);

    s2.display();
    return 0;
}


// constructor overloading

