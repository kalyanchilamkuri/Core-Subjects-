
// Destructer

#include<bits/stdc++.h>
using namespace std;


// Destructor never takes an arguement nor does it return any value
int count=0;
/*

1) A destructor is a special member function of a class that is automatically called when an object goes out of scope or is explicitly needed.
2) It is used to release resources that the object was using during its lifetime
3) used to clean up resources , avoid memory leaks
*)It has same name as the class , starts with tilde(~) , it takes no arguements , it returns nothing , there is only one destructor per class(no overloading)
***) if you allocate with new then you must call delete
*/

class num{
    public:
       num(){
        count++;
        cout<<"This is the time when constructor is called for object number"<<count<<endl;
       }

       ~num(){
        cout<<"This is the time when destructor is called for object number"<<count<<endl;
        count--;
       }
};

int main(){
    cout<<"we are inside the main function"<<endl;
    cout<<"creating first object n1"<<endl;
    num n1;{
        cout<<"Entering this block"<<endl;
        cout<<"creating two more objects"<<endl;
        num n2,n3;
        cout<<"Exiting this block";
    }
    cout<<"back to main"<<endl;
    return 0;
}




// A destructor is a special member function of a class.
// It is called automatically when an object goes out of scope or is deleted.
// Its purpose: to clean up resources (like memory, files, or connections).
// Example 2: Destructor with Dynamic Memory

#include <iostream>
using namespace std;

class Student {
    int *marks;
public:
    Student(int m) {
        marks = new int(m);  // dynamic memory
        cout << "Constructor: marks = " << *marks << endl;
    }

    ~Student() {
        delete marks;  // cleanup
        cout << "Destructor: memory freed" << endl;
    }
};

int main() {
    Student s1(95);  // constructor runs
    // when object is destroyed, destructor frees memory
    return 0;
}


// destructor with static memory

#include <iostream>
using namespace std;

class Student {
public:
    Student() {
        cout << "Constructor called" << endl;
    }

    ~Student() {
        cout << "Destructor called" << endl;
    }
};

int main() {
    Student s1;   // constructor runs here
    // when main() ends, destructor runs automatically
    return 0;
}


