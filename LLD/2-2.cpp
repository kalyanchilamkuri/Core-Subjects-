// Encapsulation 
 
// Encapsulation is the process of bundling data and the methods that operate on that data into a single unit(class),while restricting direct access to the data 

// Encapsulation=data hiding+controlled access

// Data is marked as private , access is given through public methods

// basically data should be secured , that is no one from outside can access the variables.



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
         // variables --> characters
         string brand;
         string model;
         bool isEngineOn;
         int currSpeed;
         int currGear;

public:

         SportsCar(string b,string m){
            this->brand=b;
            this->model=m;
            isEngineOn=false;
            currSpeed=0;
            currgear=0;//neutral
            string tyre;
         }

         //getters and setters
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



}

int main(){
    Car* mycar=new sportsCar("Ford","Mustang");
    
    myCar->startEngine();
    myCar->shiftGear();
    myCar->accelerate();
    myCar->brake();
    myCar->stopEngine();

    cout<<myCar->getCurrSpeed();

    delete myCar;

    //setting arbitary value to speed

}


