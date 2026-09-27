
// // // // // // // // // // //STATIC

// // // // // // // // // // // case-1) static local variables (inside a function)

// // // // // // // // // // // where: inside a function 
// // // // // // // // // // // Effect: variable is created only once and retains its value between function calls

// // // // // // // // // // #include <iostream>
// // // // // // // // // // using namespace std;

// // // // // // // // // // void counter() {
// // // // // // // // // //     static int count = 0;  // created only once
// // // // // // // // // //     count++;
// // // // // // // // // //     cout << "Count: " << count << endl;
// // // // // // // // // // }

// // // // // // // // // // int main() {
// // // // // // // // // //     counter();  // Count: 1
// // // // // // // // // //     counter();  // Count: 2
// // // // // // // // // //     counter();  // Count: 3
// // // // // // // // // // }


// // // // // // // // // // // **) stored in static memory not stack , initialized only once , lifetime is entire program , scope is local

// // // // // // // // // // // case-2) static Global variables (file scope)

// // // // // // // // // // static int x=10;

// // // // // // // // // // void func(){
// // // // // // // // // //     cout<<x<<endl;
// // // // // // // // // // }

// // // // // // // // // // // **) internal linkage , lifetime is whole program , scope to file only

// // // // // // // // // // // Static Data members (inside a class)
// // // // // // // // // // // where: in a class
// // // // // // // // // // // effect: shared among all objects of the class

// // // // // // // // // // #include <iostream>
// // // // // // // // // // using namespace std;

// // // // // // // // // // class Student {
// // // // // // // // // // public:
// // // // // // // // // //     static int count;  // declaration

// // // // // // // // // //     Student() {
// // // // // // // // // //         count++;
// // // // // // // // // //     }
// // // // // // // // // // };

// // // // // // // // // // int Student::count = 0;  // definition outside class

// // // // // // // // // // int main() {
// // // // // // // // // //     Student s1, s2, s3;
// // // // // // // // // //     cout << Student::count << endl;  // Output: 3
// // // // // // // // // // }

// // // // // // // // // // // **) one common copy shared by all objects , belongs to claass and not to object , must be defined once outside the class

// // // // // // // // // // // Static member functions (inside a class)=> function belongs to the class , not to any objects

// // // // // // // // // // // #include <iostream>
// // // // // // // // // // // using namespace std;

// // // // // // // // // // // class Student {
// // // // // // // // // // // public:
// // // // // // // // // // //     static int count;  // declaration

// // // // // // // // // // //     Student() {
// // // // // // // // // // //         count++;
// // // // // // // // // // //     }
// // // // // // // // // // // };

// // // // // // // // // // // int Student::count = 0;  // definition outside class

// // // // // // // // // // // int main() {
// // // // // // // // // // //     Student s1, s2, s3;
// // // // // // // // // // //     cout << Student::count << endl;  // Output: 3
// // // // // // // // // // // }

// // // // // // // // // // // **) can be called using  classname:function() , cannot access non-static members directly , useful for utility/helper functions related to the class.

// // // // // // // // // // // Static class , we cannpt make a top-level class static
// // // // // // // // // // // we can make a nested class static inside another class

// // // // // // // // // // class Outer {
// // // // // // // // // // public:
// // // // // // // // // //     static class Inner {
// // // // // // // // // //     public:
// // // // // // // // // //         void hello() {}
// // // // // // // // // //     };
// // // // // // // // // // };

// // // // // // // // // // // this means:
// // // // // // // // // // // inner doesnt need an outer object to be used , it behaves like a normal class but is scoped inside outer













