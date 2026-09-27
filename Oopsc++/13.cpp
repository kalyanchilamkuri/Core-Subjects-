
// Constructor with default parameters

// advantages of default parameters in constructors

// *) reduces the need for the constructor overloading
// *) simplifies the code - fewer lines needed
// *) cleaner logic when one parameter is usually constant

#include<bits/stdc++.h>
using namespace std;

class Simple{
    int data1;
    int data2;
    public:
       Simple(int a,int b=9){
         data1=a;
         data2=b;
       }
       void printData();
};

void Simple :: printData(){
    cout<<"The value of data is "<<data1<<" and "<<data2<<" "<<endl;
}

int main(){
    Simple s(1,4);
    s.printData();

    Simple g(3);
    g.printData();
    return 0;
}


