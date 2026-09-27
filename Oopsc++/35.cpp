#include <bits/stdc++.h>
using namespace std;

class Baseclass {
public:
    int var_base;
    virtual void display() {
        cout << "Here is baseclass var: " << var_base << endl;
    }
};

class Derivedclass : public Baseclass {
public:
    int var_derived;
    void display() {
        cout << "Base variable: " << var_base << endl;
        cout << "Displaying derived class variable: " << var_derived << endl;
    }
};

int main() {
    Baseclass* base_class_pointer;
    Baseclass obj_base;
    Derivedclass obj_derived;

    base_class_pointer = &obj_derived;
    base_class_pointer->var_base = 10;      // setting base var
    // base_class_pointer->var_derived = 20; // ❌ not allowed via base pointer
    base_class_pointer->display();          // 🔴 still calls base version (no virtual!)

    return 0;
}
