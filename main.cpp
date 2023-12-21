//
//  main.cpp
//  Ticket Reservation System
//
//  Created by Macbook on 14/12/2023.
//

#include <iostream>
#include "Reservation.hpp"

int main() {
    Reservation* reserve = new Reservation();
    
    int choice;
    char ch = 'Y';
    
    do {
        cout<<"\n***** Ticket Reservation System ******";
        cout<<"\n* 1. Book Ticket                     *";
        cout<<"\n* 2. Cancel Ticket                   *";
        cout<<"\n* 3. Display Reserved Seats          *";
        cout<<"\n* 4. Dis[lay Reverse                 *";
        cout<<"\n* 5. Search a Seat                   *";
        cout<<"\n* 6. Update Seat Info                *";
        cout<<"\n& 7. Exit                            *";
        cout<<"\n**************************************";
        cout<<"\nEnter your choiec: ";
        cin>>choice;
        
        switch(choice) {
            case 1: {
                cin.ignore();
                
                string name;
                cout<<"\nEnter passanger name: ";
                getline(cin, name);
                
                Seat* newSeat = new Seat();
                newSeat->setPassangerName(name);
                
                reserve->bookTicket(newSeat);
                break;
            }
            case 2: {
                int sNum;
                cout<<"\nEnter seat number: ";
                cin>>sNum;
                
                reserve->cancelTicket(sNum);
                break;
            }
            case 3: {
                reserve->displaySeat();
                break;
            }
            case 4: {
                reserve->displayReverse();
                break;
            }
            case 5: {
                Seat* searchSeat = new Seat();
                
                int sNum;
                cout<<"\nEnter seat number: ";
                cin>>sNum;
                
                searchSeat = reserve->searchSeat(sNum);
                
                if(searchSeat == NULL) {
                    cout<<"\nThe seat not found.";
                }
                else if(searchSeat->getBookingStatus() == "Booked") {
                    cout<<"\nThe seat is booked.";
                    cout<<"\nPassanger name "<<searchSeat->getPassangerName();
                }
                else {
                    cout<<"\nThe seat is available";
                }
                break;
            }
            case 6: {
                int sNum;
                cout<<"\nEnter seat number: ";
                cin>>sNum;
                
                reserve->updateSeat(sNum);
                break;
            }
            case 7: {
                cout<<"\nExiting...\n";
                return 0;
            }
        }
        cout<<"\nDo you want to repeat? Press Y: ";
        cin>>ch;
        
    }while(ch == 'y' || ch == 'Y');
}
