
// Ambiguity resolution in inheritance in c++

#include<bits/stdc++.h>
using namespace std;

class Base1{
    public:
      void greet(){
        cout<<"How are you?"<<endl;
      }
};

class Base2{
    public:
       void greet(){
         cout<<"kaise ho?"<<endl;
       }
};

class Derived : public Base1 , public Base2{
    int a;
    public:
      void greet(){
         Base1 :: greet();
      }
};

class B{
    public:
       void say(){
        cout<<"Hello world"<<endl;
       }
};

class D:public B{
    int a;
    // d's new say() method will override base class's say() method
    // public:
    //    void say(){
    //     cout<<"Hello my beautiful people"<<endl;
    //    }
};

int main(){
    // ambiguity 1
    // Base1 base1obj;
    // Base2 base2obj;
    // base1obj.greet();
    // base2obj.greet();
    // Derived d;
    // d.greet()

    // B b;
    // b.say();

    D d;
    d.say();

    return 0;
}



#include <bits/stdc++.h>
using namespace std;

// Base class definition
class Base {
protected:
    int a;   // Protected: accessible in Base, derived classes, but NOT in main().
private:
    int b;   // Private: accessible only inside Base, not in derived classes.
};

/*
   Summary of how members are inherited based on access specifier and type of inheritance:

   For a PROTECTED member in Base (`a` in this case):

  | Public Derivation | Protected Derivation | Private Derivation
   ---------------------------------------------------------------------------------
   private members |   not inherited   |     not inherited    |     not inherited
   protected       |   protected       |     protected        |     private
   public          |   public          |     protected        |     private

   Note:  
   - Protected inheritance means all public and protected members of Base become PROTECTED in Derived.
   - Private members of Base are never inherited (but can be accessed via Base's public/protected methods)
*/

class Derived : protected Base {
    // 'a' is inherited from Base as protected in Derived
    // 'b' is not inherited at all (private in Base)
};

int main() {
    Base b;
    Derived d;

    // ❌ ERROR: 'a' is protected in Derived, so it cannot be accessed from main()
    // cout << d.a << endl; // will not compile

    return 0;
}
