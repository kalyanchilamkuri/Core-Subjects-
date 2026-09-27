#include<bits/stdc++.h>
using namespace std;

class Baseclass{
   public:
      int var_base;
      void display(){
         cout<<"here is baseclass var"<<var_base<<endl;
      }
};

class Derivedclass:public Baseclass{
    public:
       int var_derived;
       void display(){
         cout<<"base variable "<<var_base<<endl;
         cout<<"displaying derived derived class variable "<<var_derived<<endl; 
       }
};

int main(){
    Baseclass * base_class_pointer;
    Baseclass obj_base;
    Derivedclass obj_derived;
    base_class_pointer = &obj_derived; // pointing base class pointer to the derived class

    base_class_pointer -> var_base=34;
    base_class_pointer->display();

    DerivedClass * derived_class_pointer;
    derived_class_pointer = &obj_derived;
    derived_class_pointer->var_derived=98;
    derived_class_pointer->display();
    return 0;
}