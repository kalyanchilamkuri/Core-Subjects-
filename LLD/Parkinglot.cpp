// Design a parking lot system 

// SETUP 

// the parking lot has multiple slots 
// different vehicle types (bike,car,truck) occupy different slot sizes
// each vehicle gets a parking ticket upon entry 
// the system calculates the parking fee based on the duration of stay and vehicle type 

// EXIT AND PAYMENT

// a vehicle must complete payment before exiting 
// multiple payment methods are supported (cash , card , upi)
// once payment is successful , the vehicle exits , slot is freed


// INTERVIEW SETTING 

// interviewer : => lets start with a basic problem statement 
// candidate : => certainly , here is my understanding 

// --> the system should different vehicle types 
// --> vehicle enter and exit after making payment 
// --> a parking lot is assigned upon entry and freed upon exit 
// --> payment must be completed before leaving 
// --> the system handles different vehicle sizes and slot allocates efficiently 
























// Entities (vehicle , parking slot, ticket , parking lot)
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

// enum for vehicle type
enum VehicleType {
    BIKE,
    CAR,
    TRUCK
};

// Vehicle class
class Vehicle {
public:
    string number;      // vehicle number
    VehicleType type;   // type of vehicle

    Vehicle(string num, VehicleType t){
        number = num;
        type = t;
    }
};

// Parking spot class
class ParkingSpot {
public:
    int spotId;          // spot id
    VehicleType type;    // which vehicle allowed
    bool isOccupied;     // occupied or not

    ParkingSpot(int id, VehicleType t){
        spotId = id;
        type = t;
        isOccupied = false;
    }
};

// Ticket class
class Ticket {
public:
    int ticketId;           // ticket id
    string vehicleNumber;   // vehicle number
    int spotId;             // assigned spot
    time_t entryTime;       // entry time

    Ticket(int id, string vNum, int sId){
        ticketId = id;
        vehicleNumber = vNum;
        spotId = sId;
        entryTime = time(0);  // current time
    }
};

// Parking lot class
class ParkingLot {
public:
    vector<ParkingSpot> spots;     // all spots
    int ticketCounter = 1;

    // constructor create parking spots
    ParkingLot(){
        // create some spots
        spots.push_back(ParkingSpot(1,BIKE));
        spots.push_back(ParkingSpot(2,CAR));
        spots.push_back(ParkingSpot(3,CAR));
        spots.push_back(ParkingSpot(4,TRUCK));
    }

    // assign spot to vehicle
    Ticket* parkVehicle(Vehicle v){
        for(auto &spot : spots){
            if(!spot.isOccupied && spot.type == v.type){
                spot.isOccupied = true;

                cout<<"Spot assigned: "<<spot.spotId<<endl;

                // create ticket
                Ticket* t = new Ticket(ticketCounter++, v.number, spot.spotId);
                return t;
            }
        }
        cout<<"No spot available\n";
        return NULL;
    }

    // exit vehicle
    void exitVehicle(Ticket* ticket){
        time_t exitTime = time(0);
        int duration = (exitTime - ticket->entryTime)/60; // minutes

        if(duration==0) duration=1;

        int price = duration * 10; // 10 per min

        cout<<"Parking time: "<<duration<<" minutes\n";
        cout<<"Total price: "<<price<<endl;

        // free spot
        for(auto &spot : spots){
            if(spot.spotId == ticket->spotId){
                spot.isOccupied = false;
            }
        }
    }
};

int main(){

    ParkingLot lot;

    // create vehicle
    Vehicle v1("UP32AB1234",CAR);

    // park vehicle
    Ticket* t1 = lot.parkVehicle(v1);

    if(t1!=NULL){
        cout<<"Vehicle parked. Ticket ID: "<<t1->ticketId<<endl;
    }

    // exit vehicle
    lot.exitVehicle(t1);

    return 0;
}
