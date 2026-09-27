
// objects are entities in the real world

// class is like a blueprint of these entities



#include<bits/stdc++.h>
using namespace std;

class Teacher{
private:
    double salary;
public:
    //non -parameterized 
    Teacher(){
        dept="computer science";
        cout<<"Hi iam a good girl"<<endl;
    }
    //parameterized
    Teacher(string name,string dept,string subject,double salary){
       this->name=name;
       this->dept=dept;
       this->subject=subject;
       this->salary=salary;
    }
    // these are properties or attributes
    string name,dept,subject;
    
    // copy constructor

    Teacher(Teacher &orgobj){ //pass by reference
        cout<<"Iam a custom copy constructor"<<endl;
         this->name=orgobj.name;
         this->dept=orgobj.dept;
         this->subject=orgobj.subject;
         this->salary=orgobj.salary;
    }

    //methods/member functions
    void changedept(string newDept){
        dept=newDept;
    }
    //setter
    voidsetSalary(double s){
        salary=s;
    }
    //getter
    double getsalary(){
        return salary;
    }
    void getInfo(){
        cout<<"name"<<name<<endl;
        cout<<"subject"<<subject<<endl;
    }
}

// here not data hiding 

// class Account{
//     public:
//        string accountId;
//        string username;
//        string password;
//        double balance;
// }

// here is data hiding

class Account{
    private:
       string accountId;
       string username;
    public:
       string password;
       double balance;
}

class Student{
    string name;
    double cgpa;

    Student(string name,double cgpa){
        this->name=name;
        this->cgpa=cgpa;
    }
    //default copy constructor
    Student(Student &obj){
       this->name=obj.name;
       this->cgpa=obj.cgpa
    }
    void getInfo(){
        cout<<"name :"<<name<<endl;
        cout<<"cgpa :"<<cgpa<<endl;
    }
}

class Student{
    string name;
    double* cgpaptr;

    Student(string name,double cgpa){
        this->name=name;
        cgpaptr=new float;
        *cgpaptr=cgpa;
    }
    //default copy constructor
    Student(Student &obj){
       this->name=obj.name;
       this->cgpa=obj.cgpa
    }
    void getInfo(){
        cout<<"name :"<<name<<endl;
        cout<<"cgpa :"<<*cgpaptr<<endl;
    }
}

// deep copy 

class Student{
    string name;
    double* cgpaptr;

    Student(string name,double cgpa){
        this->name=name;
        cgpaptr=new float;
        *cgpaptr=cgpa;
    }
    //default copy constructor
    Student(Student &obj){
       this->name=obj.name;
       cgpaptr=new double;
       *cgpaptr=*obj.cgpaptr;
       this->cgpa=obj.cgpa
    }
    void getInfo(){
        cout<<"name :"<<name<<endl;
        cout<<"cgpa :"<<*cgpaptr<<endl;
    }
}





int main(){
     Teacher t1("kalyan","c++","hello",2000);
     Student s1("kalyan",8.5)
     t1.getInfo();
     s1.getInfo();
     *(s2.cgpaptr)=9.2;
    //  t1.name="kalyan";
    //  t1.subject="c++";
    //  t1.setsalary(2500);
    Teacher t2(t1); // default copy constructor 
    t2.getInfo();
     cout<<t1.name<<endl;
     return 0;
}


// Access Modifiers

// private => data and methods accessible inside the class
// public => data and methods accessible to everyone
// protected => data and methods accessible inside class and to its derived class


// Encapsulation

// encapsulation is wrapping up of data and member functions in a single unit of class
// encapsulation helps is data hiding ... i.e put private for sensitive functions

//constructor

// constructor is a special method invoked automatically at a time of object creation, used for the initialization
   // same name as class
   // constructor doesnt have a return type 
   // only called once (autojjjmatically), at object creation
   // memory allocation happens when contructor is called


// there are 3 types of constructors 
// 1)non parameterized , parametrized , copy constructor




// in c++ this is a special pointer that points to the current object,this->prop is same as *(this).prop


//copy constructor is a special constructor (default) used to copy properties of one object to another


// 2tyoes

// 1) a shallow copy of an object copies all of the number values from one object to another
// 2) a deep copy, on the other hand , not only copies the menber values but also make copies of any dynamically allocated memory that the members point to


// delete ptr doesnt delete the ptr ...it just deletes the memery that is pointing by the pointer


//inheritance

// when properties and member functions of base class are passed on the derived class



#include<bits/stdc++.h>
using namespace std;

class Person{
    public:
       string name;
       int age;

       Person(string name,int age){
        this->name=name;
        this->age=age;
       }
};

class Student:public Person{
  public:
     int rollno;

     Student(){
        cout<<"child constructor"<<endl;
     }
     void getInfo(){
        cout<<"name"<<name<<endl;
        cout<<"age"<<age<<endl; 
        cout<<"roll no"<<rollno<<endl;
     }
};

int main(){

}




//polymorphism 

// polymorphism is the ability of objects to take on different forms or behave in different ways depending on the context in which they are used

// *)compile time polymorphism => contructor overloading,function overloading
// *)run time polymorphism => function overriding

// function overriding 

// parent and child both contain the same function with diff implementation 
// the parent class function is said to be overridden

// overriding => we should get inheritance 






// abstraction

// hiding all unnecessary details and showing only the important parts

// one more way is:
//   using abstract class 
//   abstract classes are used to provide a base class from which other classes can be derived
//   they cannot be instantiated and are meant to be inherited
//   abstract classes are typically used to define an interface for derived classes





// static variables

// variables declared as static in a function are created and initialised once for the life time of the program  // in function

// static variables in a class are created and initialised once , they are shared by all the objects of the class //in class