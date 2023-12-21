//
//  Seat.cpp
//  Ticket Reservation System
//
//  Created by Macbook on 14/12/2023.
//

#include "Seat.hpp"

Seat::Seat() {
    seatNumber = 0;
    bookingStatus = "";
    passangerName = "";
    prev = NULL;
    next = NULL;
}

void Seat::setSeatNumber(int num) {
    seatNumber = num;
}
int Seat::getSeatNumber() {
    return seatNumber;
}

void Seat::setBookingStatus(string status) {
    bookingStatus = status;
}
string Seat::getBookingStatus() {
    return bookingStatus;
}

void Seat::setPassangerName(string name) {
    passangerName = name;
}
string Seat::getPassangerName() {
    return passangerName;
}

void Seat::setPrev(Seat* prev) {
    this->prev = prev;
}
Seat* Seat::getPrev() {
    return prev;
}

void Seat::setNext(Seat* next) {
    this->next = next;
}
Seat* Seat::getNext() {
    return next;
}



