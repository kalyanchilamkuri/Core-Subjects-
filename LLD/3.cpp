

#include<bits/stdc++.h>
using namespace std;

// Real life car 


class Car{
protected:
         string brand;
         string model;
         bool isEngineOn;
         int currSpeed;
         int currGear;
public:
        Car(string b,string m){
            this->brand=b;
            this->model=m;
            isEngineOn=false;
            currSpeed=0;
            currgear=0;//neutral
         }
           
         int getCurrSpeed(){
            return this->currSpeed;
         }

         string getTyre(){
            return this->tyre;
         }

         void setTyre(string tyre){
               this->tyre=tyre;
         }

        // behaviours => methods
         void startEngine(){
            isEngineOn=true;
            cout<<brans<<" "<<model<<" : Engine starts with a roar!"<<endl;
         }

         void shiftGear(int gear){
            if(!isEngineOn){
                cout<<brand<<" "<<model<<" : Engine is off:cannot shift gear."<<endl;
            }
            currGear=gear;
            cout<<brand<<" "<<model<<"shifted to gear"<<currGear<<endl;
         }

         void accelerate(){
            if(!isEngineOn){
                cout<<brand<<" "<<model<<<<" : Engine is off! cannot accelerate"<<endl;
                return;
            }
            currSpeed+=20;
            cout<<"brand<<"<<" "<<model<<" : Accelerating to "<<currSpeed<<"km/h"<<endl;
         }

         ~virtual Car() {}
};

int main(){
    Car* mycar=new sportsCar("Ford","Mustang");
}



