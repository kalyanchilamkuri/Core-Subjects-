// pillars of OOPS

// Abstraction inheritance polymorphism encapsulation 

// Abstraction 
// abstraction hides unnecessary details from a client and showcase only what is necessary 


#include<bits/stdc++.h>
using namespace std;

// Real life car 

class Car{
public:
     virtual void startEngine()=0;
     virtual void shiftGear()=0;
     virtual void accelerate()=0;
     virtual void brake()=0;
     virtual void stopEngine()=0;
     virtual ~Car() {}
};

class sportsCar:public Car{
public:
         string brand;
         string model;
         bool isEngineOn;
         int currSpeed;
         int currGear;

         SportsCar(string b,string m){
            this->brand=b;
            this->model=m;
            isEngineOn=false;
            currSpeed=0;
            currgear=0;//neutral
         }
}

int main(){
    Car* mycar=new sportsCar("Ford","Mustang");
}



