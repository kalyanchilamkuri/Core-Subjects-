
// Parameterized construcor
// we can also define a constructor outside using scope resolution operator ::

#include<bits/stdc++.h>
using namespace std;

class Complex{
    int a,b;
public:
  Complex(void);
  void printNumber(){
    cout<<"Your number is "<<a<<" + "<<b<<" i "<<endl;
  }
}

Complex :: Complex(int x,int y){ // parameterized constructor.
    a=x;
    b=y;
}

int main(){
    //Implicit call
    Complex a(4,6);
    a.printNumber();

    //Explicit call
    Complex b=Complex(5,7);
    b.printNumber();
    return 0;
}


// dynamic constructor

// used when we allocate memory dynamically inside the constructor using new

#include<bits/stdc++.h>
using namespace std;

class Student {
    char *name;
public:
    Student(const char *n) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    void show() {
        cout << "Name: " << name << endl;
    }

    ~Student() {
        delete[] name;
    }
};

int main() {
    Student s1("Jaswanth");
    s1.show();
    return 0;
}





// dynamic constructor is a constructor that allocates dynamically at run time using the new operator 
// => instead of storing values in fixed variables , it creates space in the heap memory and then stores the data there

