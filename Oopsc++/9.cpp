
// More on c++ friend functions

#include <bits/stdc++.h>
using namespace std;

class Y;  // Forward declaration

class X {
    int data;
public:
    void setValue(int value) {
        data = value;
    }
    friend void add(X, Y);  // Friend function declaration
};

class Y {
    int num;
public:
    void setValue(int value) {
        num = value;
    }
    friend void add(X, Y);  // Friend function declaration
};

void add(X o1, Y o2) {
    cout << "Summing data of X and Y objects gives me " << o1.data + o2.num << endl;
}

int main() {
    X a;
    a.setValue(3);

    Y b;
    b.setValue(5);

    add(a, b);
    return 0;
}



