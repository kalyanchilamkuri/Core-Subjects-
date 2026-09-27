
// Dynamic initialization of objects using constructors
// Here we will learn the classic case of overloading + dynamic initialization

// dynamic initialization means initializing data members at runtime , usually using constructors with values that are not known at compile-time

// static initialization => int a=5; values are set at compile time 

// dynamic initialization => int a;cin>>a; values are set at run time

#include <bits/stdc++.h>
using namespace std;

class BankDeposit {
    int principal;
    int years;
    float interestRate;
    float returnValue;

public:
    BankDeposit() {} // Default constructor
    // Constructor with float interest rate (e.g. 0.05 for 5%)
    BankDeposit(int p, int y, float r);
    // Constructor with int interest rate (e.g. 5 for 5%)
    BankDeposit(int p, int y, int r);
    void show();
};

// Constructor with float interest rate
BankDeposit::BankDeposit(int p, int y, float r) {
    principal = p;
    years = y;
    interestRate = r;
    returnValue = principal;

    for (int i = 0; i < years; i++) {
        returnValue *= (1 + interestRate);
    }
}

// Constructor with int interest rate
BankDeposit::BankDeposit(int p, int y, int r) {
    principal = p;
    years = y;
    interestRate = float(r) / 100;
    returnValue = principal;

    for (int i = 0; i < years; i++) {
        returnValue *= (1 + interestRate);
    }
}

// show() function to display data
void BankDeposit::show() {
    cout << "\nPrincipal amount was " << principal;
    cout << "Return value after " << years << " years is " << returnValue << endl;
}

int main() {
    BankDeposit bd1, bd2; // two objects createdusing default constructor firstis 
    int p, y;
    float r;
    int R;

    cout << "Enter value of principal, years and interestRate (float): ";
    cin >> p >> y >> r;
    bd1 = BankDeposit(p, y, r); // Dynamic initialization using float rate
    bd1.show();

    cout << "\nEnter value of principal, years and interestRate (int): ";
    cin >> p >> y >> R;
    bd2 = BankDeposit(p, y, R); // Dynamic initialization using int rate
    bd2.show();

    return 0;
}





// 2. Dynamic Initialization of Objects => initializing the data members of a class at run time i.e when the program is running , instead of compile time

👉 When we create an object using new keyword (on the heap), constructor is still called, but memory is allocated dynamically (runtime).

Object is created at runtime.

Memory allocated on heap using new.

Lifetime = until we explicitly delete it.

Constructor is called automatically after new.




// #include <iostream>
// using namespace std;

// class Student {
//     int age;
// public:
//     // parameterized constructor
//     Student(int a) {
//         age = a;
//         cout << "Constructor called, age = " << age << endl;
//     }

//     void show() {
//         cout << "Age = " << age << endl;
//     }

//     ~Student() {
//         cout << "Destructor called for age = " << age << endl;
//     }
// };

// int main() {
//     // 🔹 static initialization
//     Student s1(18);

//     // 🔹 dynamic initialization
//     Student *s2 = new Student(22);  // constructor runs here
//     s2->show();

//     delete s2;  // destructor called manually for dynamic object
//     return 0;
// }



//dynamic intialization means assigning values to variables or data members at run time.
//it allows objects to be initialized using user input , calculations or function returns usually through constructors 



int a = 10;  // static initialization (value fixed in code)

int x;
cout << "Enter value: ";
cin >> x;  // value given at runtime → dynamic initialization








#include<bits/stdc++.h>
using namespace std;

class student{
    int age;
    public:
        student(int a){
            age=a;
            cout<<age<<endl;
        }

        void show(){
            cout<<"Age "<<age<<endl;
        }

        ~student(){
            cout<<"Destructor called for age = "<<age<<endl;
        }
}

int main(){
      student s1(18);

      // this object is stored in stack memory , so its destructor will be called automatically when main() ends or when it goesout of scope
      
    // dynamic intialization
      student *s2=new student(22);  //constructor runs here
      s2->show();  

      // new dynamically allocates memory for a student object in the heap memory 
      // the constructor is called immediately 
      // here s2 is a pointer to the object created in the heap

      delete s2;  //destructor called manually for dynamic object
      return 0;
}






// in c++ dynamic initialization means creating and initializing an object at runtime using the new keyword
// when we use the new, the constructor is automatically called, and when we use delete the destructor is called to free memeory









// static infront of a class

// in c++ we cannot make a class itselft at the global scope like you can in some languages
// but there are two specific cases wherestatic behaves differently with a class 

// *) static nested class
// if a class is declared inside another class , then you can make that inner(nested) class static

#include<bits/stdc++.h>
using namespace std;


class outer{
    public:
       static class inner{
         public:
             void show(){
                 cout<<"inside static";
             }
       };
};

int main(){
     outer::inner obj;
     obj.show();
     return 0;
}


// here the inner class is declared as static inside the outer class
// so we can access it as outer::inner without needing an object of outer
// its like static here removes dependency on the outer class's object

// **usecase => when an inner class doesnt need access to the non-static members of the outer class


// *) we cannot declare a constructor as static 

// a constructors purpose is to initialize objects 
// static means belongs to the class , not to any object
// so it deosnt make sense - because constructors run only when an object is created






