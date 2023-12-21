//
//  Reservation.cpp
//  Ticket Reservation System
//
//  Created by Macbook on 14/12/2023.
//

#include "Reservation.hpp"

// Reservation::Reservation() {
//     count = 0;
//     head = NULL;
// }

void Reservation::bookTicket(Seat *newSeat)
{
    if (head == NULL)
    {
        head = newSeat;
        newSeat->setNext(NULL);
        newSeat->setPrev(head);

        count++;
        newSeat->setBookingStatus("Booked");
        newSeat->setSeatNumber(count);

        cout << "\nThe seat is booked successfully.";
        return;
    }

    Seat *temp = head;

    while (temp->getNext() != NULL)
    {
        temp = temp->getNext();
    }
    temp->setNext(newSeat);
    newSeat->setNext(NULL);
    newSeat->setPrev(temp);

    count++;
    newSeat->setBookingStatus("Booked");
    newSeat->setSeatNumber(count);

    cout << "\nThe seat is booked successfully.";
}

void Reservation::displaySeat()
{
    if (head == NULL)
    {
        cout << "\nThe reservation list is empty.";
        return;
    }

    if (head->getNext() == NULL)
    {
        cout << "Seat number: " << head->getSeatNumber();
        cout << "\nPassanger name: " << head->getPassangerName();
    }

    Seat *temp = head;

    int i = 0;
    while (i < count)
    {
        cout << "Seat number: " << temp->getSeatNumber();
        cout << "\t\tPassanger name: " << temp->getPassangerName();
        temp = temp->getNext();

        cout << "\n";
        i++;
    }
}

void Reservation::cancelTicket(int seatNum)
{
    if (head == NULL)
    {
        cout << "\nThe seat list is empty.";
        return;
    }

    Seat *temp = head;
    while (temp != NULL)
    {
        if (temp->getSeatNumber() == seatNum)
        {
            if (temp == head)
            {
                head = temp->getNext();
                if (head != NULL)
                {
                    head->setPrev(NULL);
                }
            }
            else
            {
                Seat *prevSeat = temp->getPrev();
                prevSeat->setNext(temp->getNext());
                if (temp->getNext() != NULL)
                {
                    temp->getNext()->setPrev(prevSeat);
                }
            }

            cout << "\nThe reservation for seat number " << seatNum << " has been canceled.";
            delete temp;
            count--;
            return;
        }
        temp = temp->getNext();
    }

    cout << "\nSeat number " << seatNum << " not found in the reservation list.";
}

Seat *Reservation::searchSeat(int seatNum)
{
    if (head == NULL)
    {
        cout << "\nThe seat list is empty.";
        return NULL;
    }

    Seat *temp = head;
    while (temp != NULL)
    {
        if (temp->getSeatNumber() == seatNum)
        {
            return temp;
        }
        temp = temp->getNext();
    }

    cout << "\nSeat number " << seatNum << " not found in the reservation list.";
    return NULL;
}

void Reservation::updateSeat(int seatNum)
{
    Seat *seatToUpdate = searchSeat(seatNum);

    if (seatToUpdate != NULL)
    {

        cout << "\nSeat " << seatNum << " found. Enter new details:\n";

        string newBookingStatus;
        string newPassengerName;

        cout << "Enter new booking status (Booked/Available): ";
        cin >> newBookingStatus;
        seatToUpdate->setBookingStatus(newBookingStatus);

        cout << "Enter new passenger name: ";
        cin >> newPassengerName;
        seatToUpdate->setPassangerName(newPassengerName);

        cout << "\nSeat " << seatNum << " information updated.";
        count--;
    }
}

void displayReverseHelper(Seat *current)
{
    if (current == NULL)
    {
        return;
    }
    displayReverseHelper(current->getNext());
    cout << "Seat number: " << current->getSeatNumber() << "\tPassenger name: " << current->getPassangerName() << endl;
}

void Reservation::displayReverse()
{
    if (head == NULL)
    {
        cout << "\nThe seat list is empty.";
        return;
    }

    cout << "\nReserved Seats Information (in reverse order):\n";
    displayReverseHelper(head);
}
