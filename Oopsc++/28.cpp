//syntax for initialization list in constructor:
// constructor (arguement-list) : initialization-section
// {
    // assignment+othercode
// }

#include <bits/stdc++.h>
using namespace std;

class Test {
    int a;
    int b;
public:
    // Test(int i,int j):b(i),a(a+i) this creates error and return the garabage value because here a is declared first
    Test(int i, int j) : a(i), b(2 * j) {
        cout << "constructor executed" << endl;
        cout << "value of a is " << a << endl;
        cout << "value of b is " << b << endl;
    }
};

int main() {
    Test t(4, 6);
    return 0;
}
