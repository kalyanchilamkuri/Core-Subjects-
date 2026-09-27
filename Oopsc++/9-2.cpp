#include <bits/stdc++.h>
using namespace std;

class c2; // forward declaration

class c1 {
    int val;
    friend void exchange(c1 &, c2 &);
public:
    void indata(int a) {
        val = a;
    }

    void display(void) {
        cout << val << endl;
    }
};

class c2 {
    int val2;
    friend void exchange(c1 &, c2 &);
public:
    void indata(int a) {
        val2 = a;
    }

    void display(void) {
        cout << val2 << endl;
    }
};

void exchange(c1 &x, c2 &y) {
    int tmp = x.val;
    x.val = y.val2;
    y.val2 = tmp;
}

int main() {
    c1 oc1;
    c2 oc2;

    oc1.indata(35);
    oc2.indata(67);

    cout << "Before exchange:" << endl;
    oc1.display();
    oc2.display();

    exchange(oc1, oc2);

    cout << "After exchange:" << endl;
    oc1.display();
    oc2.display();

    return 0;
}


// declaring a friend member function as private and public has no difference.