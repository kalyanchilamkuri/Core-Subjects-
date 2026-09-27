
#include<bits/stdc++.h>
using namespace std;

class A{
    int a;
    public:
       void setData(int a){
          this->a=a;
       }
       void getData(){
         cout<<"the value of a is "<<a<<endl;
       }
}

int main(){
    // this keyword is a pointer which points to the object which invokes the member function
    A a;
    a.setData(9);
    a.getData();
    return 0;
}


#include <iostream>
using namespace std;

class Box {
    int length;
public:
    Box& setLength(int l) {
        this->length = l;
        return *this;  // returning current object
    }
    void show() {
        cout << "Length = " << length << endl;
    }
};

int main() {
    Box b;
    b.setLength(10).show();  // method chaining
    return 0;
}






// this is a pointer to the current object of a class - i.e the object that is calling the member function 
// it is automatically passes to all non-static member functions of a class


// static functions are not tied to any object so ... this keyword is not available in static functions

#include <iostream>
using namespace std;

class Example {
public:
    Example() {
        cout << "Address of object in constructor: " << this << endl;
    }
};

int main() {
    Example e;
    cout << "Address of object in main: " << &e << endl;
}
 
// this is an implicit pointer available inside non-static member functions, which points to the object that invoked the function.
// its mainly used to resolve naming conflicts and to enable method chaining





