// Functional requirements 

// okay ... so what i thought was elevator system should:

// 1) user presses button (up/down) 2)elevator comes to floor 3)user selects destination floor 4)elevator moves up/down 5)open door ata floor 6)multiple elevators support 7)show current floor

// Non-functional requirements 

// system should be fast and safe 

// 1) No wrong floor 2)should handle many requests 3)minimum waiting time 4)should not crash 5)scalable for big buildings 


// what will i speak in interview 

// Main classes are 1)elevator 2)request 3)elevatorcontroller 4)Button 5)Floor 

// when user presses button --> 1)request goes to controller 2)controller assigns best elevator 3)elevator opens 4)door opens

// Main goal: --> minimum waiting time , correct floor 

// Entries ==> elevator , request ,  controller 


#include<bits/stdc++.h>
using namespace std;

// request class
class Request {
public:
    int floor;      // requested floor
    string direction; // up or down

    Request(int f, string d){
        floor = f;
        direction = d;
    }
};

// Elevator class
class Elevator {
public:
    int id;               // elevator id
    int currentFloor;     // current floor
    string direction;     // up/down/idle
    queue<int> requests;  // destination queue

    Elevator(int i){
        id = i;
        currentFloor = 0;
        direction = "idle";
    }

    // add request to elevator
    void addRequest(int floor){
        requests.push(floor);
    }

    // move elevator
    void move(){
        if(requests.empty()){
            direction = "idle";
            return;
        }

        int dest = requests.front();

        if(currentFloor < dest){
            direction = "up";
            currentFloor++;
        }
        else if(currentFloor > dest){
            direction = "down";
            currentFloor--;
        }

        cout<<"Elevator "<<id<<" at floor "<<currentFloor<<endl;

        // reached destination
        if(currentFloor == dest){
            cout<<"Elevator "<<id<<" stopped at "<<dest<<endl;
            requests.pop();
        }
    }
};

// Controller class
class ElevatorController {
public:
    vector<Elevator> elevators;

    ElevatorController(int n){
        for(int i=0;i<n;i++){
            elevators.push_back(Elevator(i));
        }
    }

    // assign elevator
    void requestElevator(int floor){
        int best = 0;
        int minDist = 1e9;

        // find nearest elevator
        for(int i=0;i<elevators.size();i++){
            int dist = abs(elevators[i].currentFloor - floor);
            if(dist < minDist){
                minDist = dist;
                best = i;
            }
        }

        cout<<"Elevator "<<best<<" assigned\n";
        elevators[best].addRequest(floor);
    }

    // run elevators
    void step(){
        for(auto &e : elevators){
            e.move();
        }
    }
};

int main(){

    ElevatorController controller(2); // 2 elevators

    controller.requestElevator(5);
    controller.requestElevator(2);

    for(int i=0;i<10;i++){
        controller.step();
    }

    return 0;
}














#include<bits/stdc++.h>
using namespace std;



int main(){

}