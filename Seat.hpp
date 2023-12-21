//
//  Seat.hpp
//  Ticket Reservation System
//
//  Created by Macbook on 14/12/2023.
//

#ifndef Seat_hpp
#define Seat_hpp
#include <iostream>
using namespace std;

class Seat {
private:
    int seatNumber;
    string bookingStatus;
    string passangerName;
    Seat* prev;
    Seat* next;
    
public:
    Seat();
    
    void setSeatNumber(int);
    int getSeatNumber();
    void setBookingStatus(string);
    string getBookingStatus();
    void setPassangerName(string);
    string getPassangerName();
    void setPrev(Seat* prev);
    Seat* getPrev();
    void setNext(Seat* next);
    Seat* getNext();
};

#endif /* Seat_hpp */
