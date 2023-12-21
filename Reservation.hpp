//
//  Reservation.hpp
//  Ticket Reservation System
//
//  Created by Macbook on 14/12/2023.
//

#ifndef Reservation_hpp
#define Reservation_hpp
#include "Seat.hpp"

class Reservation {
private:
    int count;
    Seat* head;
    
public:
    Reservation();
    
    void bookTicket(Seat* newSeat);
    void cancelTicket(int);
    void displaySeat();
    void displayReverse();
    Seat* searchSeat(int);
    void updateSeat(int);
};
#endif /* Reservation_hpp */


