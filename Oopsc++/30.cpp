#include<bits/stdc++.h>
using namespace std;

class Complex{
    int real,imaginary;
    public:
       void getData(){
         cout<<real<<endl;
         cout<<imaginary<<endl;
       }
       void setData(int a,int b){
         real=a;
         imaginary=b;
       }
};



int main(){
    // all the 3 are same

    // Complex c1;
    // Complex *ptr=&c1;
    // Complex *ptr=new Complex
    (*ptr).setData(1,2); // bracket is must because the priority of the . operator is higher than * operator
    (*ptr).getData(); // is exactly same as
    ptr->getData();



    // array of objects
    Complex *ptr=new Complex[3];
    ptr->setdata(1,2);
    ptr->getData();
    return 0;
}