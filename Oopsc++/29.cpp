
#include<bits/stdc++.h>
using namespace std;

int main(){
    //basic example
    int a=4;
    int* ptr=&a;
    cout<<a<<endl;
    cout<<*ptr<<endl;

    // new keyword
    int* p=new int(40);
    float* q=new float(40.90);
    cout<<*q<<endl;

    int* arr=new int[3];
    arr[0]=10;
    *(arr+1)=20;
    arr[2]=30;
    cout<<arr[0]<<endl;  

    //delete
    delete[] arr;
    cout<<arr[0]<<endl;
    return 0;
}












// difference between stack and heap memory ?
// stack -> auto memory (destroyed when function ends)
// Heap -> manual memory (new/delete)

// dangling pointer is a pointer that points to memory that has already been freed

// if we forget to delete the memory , it may cause to memory leak

// delete -> for single object
// delete[] -> for arrays


