#include <bits/stdc++.h>
using namespace std;

class Complex {
    int a;
    int b;

public:
    void setData(int u, int v) {
        a = u;
        b = v;
    }

    // void setDataBySum(Complex o1, Complex o2) {
    //     a = o1.a + o2.a;
    //     b = o1.b + o2.b;
    // }

    void setDataBySum(const Complex &o1, const Complex &o2){ //this avoids copying and makes it efficient
          //     a = o1.a + o2.a;
          //     b = o1.b + o2.b;
    }
    

    void printNumber() {
        cout << "Your complex number is " << a << " + " << b << "i" << endl;
    }
};

int main() {
    Complex c1, c2, c3;
    c1.setData(1, 2);
    c1.printNumber();

    c2.setData(3, 4);
    c2.printNumber();  // corrected: was printing c1 again

    c3.setDataBySum(c1, c2);
    c3.printNumber();  // corrected: was printing c1 again

    return 0;
}


// 🔹 Q2: What is the difference between setData() and setDataBySum()?
// ✅ "setData() sets values directly using parameters.
// setDataBySum() takes two other objects and sets values by computing from them."


// 🔹 Q3: Why can you access o1.a if a is private?
// ✅ “Because o1 and o2 are objects of the same class. A class`s member function can access private members of any object of the same class.”

