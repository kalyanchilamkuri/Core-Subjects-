#include<bits/stdc++.h>
using namespace std;

/*
case-1:
class B:class A{
    // order of execution of constructor -> first A() then B()
}

case-2:
class C:class B,class A{
    // order of execution of constructor -> first B() and then A() then C()
}

case-3:
class A: public B,virtual public C{
    // order of execution of constructor -> C() then then B() then A()
}
*/

class Base1{
    int data1;
    public:
       Base1(int i){
           data1=i;
           cout<<"Base1 class constructor is called"<<endl;
       }
       void printData1(void){
           cout<<"The value of data1 is "<<data1<<endl;
       }
};

class Base2{
    int data2;
    public:
       Base2(int i){
           data2=i;
           cout<<"Base2 class constructor is called"<<endl;
       }
       void printData2(void){
           cout<<"The value of data2 is "<<data2<<endl;
       }
};

class Derived: public Base1,public Base2{  // order here is deciding factor
    int derived1,derived2;
    public:
       Derived(int a,int b,int c,int d):Base1(a,b),Base2(c,d){ // not here
           derived1=c;
           derived2=d;
           cout<<"Derived class constructor "<<endl;
       }
       void printDatader(void){
         cout<<"The value of d is "<<derived1<<endl;
         cout<<"The value of d is "<<derived2<<endl;
       }
};

int main(){
    Derived harry(1,2,3,4);
    harry.printDatader();
    return 0;
}