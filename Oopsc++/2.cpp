// classes , public , private access modifiers

#include<bits/stdc++.h>
using namespace std;

// class Employee{
//     private:
//         int a,b,c;// we cannot access or modify these directly from outside the class
//     public:
//          int d,e;
//          void setData(int a1,int b1,int c1);// Declaration
//          void getData(){
//             cout<<"The value of a is "<<a<<endl;
//             cout<<"The value of b is "<<b<<endl;
//             cout<<"The value of c is "<<c<<endl;
//             cout<<"The value of d is "<<d<<endl;
//             cout<<"The value of e is "<<e<<endl;
//          }
// };






class Employee{
    private: int a,b,c;
    public:
        int d,e;
        void setData(int a1,int b1,int c1); // we can directly assign values here or 
        void getData(){
            cout<<endl;
        }
}





// this setData function sets the values of private variables a,b,c
// Its the only way we can safely assign the values to private data
// It is a public method to assign values to private variables
// think==> login function (setData) and persons password(a,b,c)
// scope resolution operator
// This function allows the user to safely assign values to private variables.

// 1) directly inside the function but in public 
// 2) we have to use the scope resolution operator to assign the values


// we can assign here 
// first we write the calss name  then scope resolution operator and then function and the assign values 

// void Employee :: setData(int a1,int b1,int c1){
//     a=a1;
//     b=b1;
//     c=c1;
// }




int main(){
    Employee harry; // creating an employee object : Employee - harry
    harry.a=23   //a, b, c are private, so if you try harry.a = 10; → ❌ Compilation error.
    harry.d=5;
    harry.e=6;  //d, e are public, so you can access them directly like harry.d = 5; → ✅ No error.
    harry.setData(1,2,3); // member function that can access private members 
    harry.getData();
    return 0;
}



// protected class
// protected is like private class --> but we cana access variables from the child classes , but cant be accessed from the outside of the class.

#include<iostream>
using namespace std;

class Base {
protected:
    int a;   // visible to base + any class derived from the base class

public:
    void setA(int x) {
        a = x; 
    }
};

class Derived : public Base {
public:
    void show() {
        cout << "The value of a is " << a << endl; // ✅ Accessible because 'a' is protected
    }
};

int main() {
    Derived d;
    d.setA(10);  // Set value using public function
    d.show();    // Show value using derived class
    // cout << d.a; ❌ Not allowed, 'a' is protected
    return 0;
}
