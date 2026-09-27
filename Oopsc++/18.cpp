
#include<bits/stdc++.h>
using namespace std;

/*
Modifier   | 	Access from main()  |	Access in derived class
private	   |❌ Not allowed	       |  Not allowed
protected  |	❌ Not allowed	✅ Allowed
public	   |✅ Allowed	✅ Allowed
*/

//Base class
class Employee {
protected:          // Change from private to protected
    int id;
public:
    float salary;

    Employee(int n) {
        id = n;
        salary = 34;
    }

    Employee() {}
};

//Derived class syntax
/*
   class {{derived-class-name}} : {{visibility-class-name}} {{base-class-name}}
*/

// Note:
// *) default visibility mode is private
// *) private visibility mode: public members of the base class becomes private members of the derived class 
// *) public visibility mode: public members of the base class becomes public members of the derived class 

// creating a programmer class derived from Employee class

// Derived class
class Programmer : public Employee {
public:
    int langcode = 9;

    Programmer(int ok) {
        id = ok;  // Now valid since id is protected
    }

    void getData() {
        cout << "Programmer ID: " << id << endl;
    }
};

int main() {
    Employee harry(1), rohan(2);

    cout << "Harry's Salary: " << harry.salary << endl;
    cout << "Rohan's Salary: " << rohan.salary << endl;

    Programmer skillF(5);
    cout << "Language Code: " << skillF.langcode << endl;

    // cout << skillF.id << endl; ❌ Still invalid: id is protected, not public
    skillF.getData();  // ✅ Use member function to access id

    return 0;
}



// 🔹 Access Modifiers in Inheritance
// Base Class Member	Public Inheritance	   Protected Inheritance	Private Inheritance
// public	            public in derived	   protected in derived	    private in derived
// protected	        protected in derived   protected in derived	    private in derived
// private	            ❌ Not inherited	     ❌ Not inherited	     ❌ Not inherited


