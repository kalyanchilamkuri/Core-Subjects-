
#include<bits/stdc++.h>
using namespace std;

class Base{
    protected:
    int a; //accessible to base + derived , but not outside 
    private:
    int b; // accessible only inside base
};

// for a protected member:
//                                   public inheritance  - protected inheritance - private inheritance
//   *)private   ===========>>        not inherited         not inherited         not inherited 
//   *)protected ===========>>        protected              private               protected 
//   *)public    ===========>>        public                 private               protected

class Derived : protected Base{
             
};

int main(){
    Base b;
    Derived d;
    cout<<d.a<<endl;  // will not work 
    return 0;
}


#include <iostream>
using namespace std;

class Base {
private:
    int a;   // private: not inherited
protected:
    int b;   // protected
public:
    int c;   // public
};

// Public inheritance
class Derived1 : public Base {
public:
    void show() {
        // a = 1; ❌ private not accessible
        b = 2;   // ✅ becomes protected in Derived1
        c = 3;   // ✅ remains public in Derived1
        cout << "Derived1: b=" << b << " c=" << c << endl;
    }
};

// Protected inheritance
class Derived2 : protected Base {
public:
    void show() {
        // a = 1; ❌ private not accessible
        b = 4;   // ✅ becomes private in Derived2
        c = 5;   // ✅ becomes private in Derived2
        cout << "Derived2: b=" << b << " c=" << c << endl;
    }
};

// Private inheritance
class Derived3 : private Base {
public:
    void show() {
        // a = 1; ❌ private not accessible
        b = 6;   // ✅ becomes protected in Derived3
        c = 7;   // ✅ becomes protected in Derived3
        cout << "Derived3: b=" << b << " c=" << c << endl;
    }
};

int main() {
    Derived1 d1;
    d1.show();
    cout << d1.c << endl;  // ✅ c is public here

    Derived2 d2;
    d2.show();
    // cout << d2.c; ❌ error: c is private in Derived2

    Derived3 d3;
    d3.show();
    // cout << d3.c; ❌ error: c is protected in Derived3

    return 0;
}
