// Ticket Booking system like BookMyShow , Paytm , District 

// Step-1

// Functional requirements 

// 1) => user should be able to search an event based on some location , title and date 
// 2) => user should be able to view the details of the events (seat, description , metadata)
// 3) => user should be able to do a booking for that event

// Step-2
// Non-Functional requirements 

// 1) => scale: !00M DAU 
// 2) => CAP theorem : Highly Available with respect to searching and viewing an event and highly consistent with respect to booking a particular ticket.


// step-3 
// Identify the core Entity 

// 1) => User 
// 2) => Event {movie / concert}
// 3) => Venue {Hall/Location}
// 4) => Ticket 

// step-4
// API Designing 

// GET: (location)
// GET: (Event details)
// POST: (Booking/reserve)
// POST: (Booking/confirm)

// step-5
// 






























// Code

// Entities ==> user ,movie , show , seat , Booking , payment

#include<bits/stdc++.h>
using namespace std;

// USER CLASS
class User{
public:
    int userId;
    string name;
    string email;
         
    User(int id,string name,string email){
        userId=id;
        this->name=name;
        this->email=email;
    }
};

// MOVIE CLASS
class Movie{
public:
    int movieId;
    string title;

    Movie(int num,string title){
        movieId=num;
        this->title=title;
    }
};

// SEAT CLASS
class Seat{
public:
    int seatnum;
    bool isbooked;

    Seat(int num){
        seatnum=num;
        isbooked=false;
    }
};

// SHOW CLASS
class Show{
public:
    int showId;
    Movie movie;
    string time;
    vector<Seat> seats;

    Show(int id,Movie m,string t,int totseats):movie(m){
        showId=id;
        time =t;

        for(int i=1;i<=totseats;i++){
            seats.push_back(Seat(i));
        }
    }

    // show available seats
    void showAvailableSeats(){
        cout<<"Available Seats: ";
        for(auto &seat:seats){
            if(!seat.isbooked){
                cout<<seat.seatnum<<" ";
            }
        }
        cout<<endl;
    }

    // book seat
    bool bookSeat(int seatNum){
        for(auto &seat : seats){
            if(seat.seatnum == seatNum){
                if(seat.isbooked){
                    cout<<"Seat already booked\n";
                    return false;
                }
                seat.isbooked = true;
                return true;
            }
        }
        cout<<"Seat not found\n";
        return false;
    }
};

// BOOKING CLASS
class Booking {
public:
    int bookingId;
    User user;
    Show &show;
    int seatNumber;

    Booking(int id, User u, Show &s, int seat) : user(u), show(s) {
        bookingId = id;
        seatNumber = seat;
    }

    void confirmBooking(){
        bool success = show.bookSeat(seatNumber);
        if(success){
            cout<<"Booking confirmed for seat "<<seatNumber<<endl;
        }else{
            cout<<"Booking failed\n";
        }
    }
};

int main(){

    Movie m1(1,"Avengers");

    Show show1(1,m1,"6PM",10);

    User u1(1,"Kalyan","k@gmail.com");

    show1.showAvailableSeats();

    Booking b1(1,u1,show1,3);
    b1.confirmBooking();

    show1.showAvailableSeats();

    return 0;
}

