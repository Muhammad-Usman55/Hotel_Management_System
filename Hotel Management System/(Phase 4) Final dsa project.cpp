//HOTEL MANAGEMENT SYSTEMs

#include <iostream>
#include <cstring>
#include <list>
#include <queue>
using namespace std;

const int MAX_ROOMS = 100; // Defining max. number of rooms as constant

class Guest {
private:
    char name[50];
    int age;

public:
    Guest(const char* guestName, int guestAge) : age(guestAge) {
        strncpy(name, guestName, sizeof(name) - 1);
        name[sizeof(name) - 1] = '\0';
    }

    void displayInformation() const {
        cout << "Guest Name: " << name << " | Age: " << age << endl;
    }
};

class Room {
private:
    int roomNumber;
    bool isOccupied;

public:
    Room() : roomNumber(0), isOccupied(false) {}

    Room(int number) : roomNumber(number), isOccupied(false) {}

    void occupyRoom() {
        isOccupied = true;
    }

    void vacateRoom() {
        isOccupied = false;
    }

    void displayInformation() {
        cout << "Room Number: " << roomNumber << " | Status: " << (isOccupied ? "Occupied" : "Vacant") << endl;
    }
};

class Reservation {
public:
    Room* room;
    Guest* guest;

    Reservation(Room* reservationRoom, Guest* reservationGuest)
        : room(reservationRoom), guest(reservationGuest) {}

    void displayInformation()  {
        cout << "Reservation Details:" << endl;
        room->displayInformation();
        guest->displayInformation();
    }
};

class BookingQueue {
private:
    mutable std::queue<Reservation*> reservations;

public:
    void bookRoom(Reservation* reservation) const {
        reservations.push(reservation);
        reservation->room->occupyRoom();
    }

    Reservation* cancelBooking() const {
        if (!reservations.empty()) {
            Reservation* canceledReservation = reservations.front();
            reservations.pop();
            canceledReservation->room->vacateRoom();
            return canceledReservation;
        }
        return NULL;
    }

    const std::queue<Reservation*>& getReservations() const {
        return reservations;
    }
};

class Event {
private:
    char eventName[50];
    std::list<Guest*> attendees;

public:
    Event(const char* name) {
        strncpy(eventName, name, sizeof(eventName) - 1);
        eventName[sizeof(eventName) - 1] = '\0';
    }

    void addAttendee(Guest* guest) {
        attendees.push_back(guest);
    }

    void displayInformation() const {
        cout << "Event Name: " << eventName << endl;
        cout << "Number of Attendees: " << attendees.size() << endl;

        for (auto attendee : attendees) {
            attendee->displayInformation();
        }
    }
};

class Hotel {
private:
    char name[50];
    Room* roomsArray; // Array for easy access to rooms
    int numRooms;
    std::list<Room*> roomsList; // Linked list for managing rooms
    std::list<Guest*> guests;
    BookingQueue bookingQueue;
    Event* currentEvent;

public:
    Hotel(const char* hotelName, int maxRooms) : numRooms(0), currentEvent(NULL) {
        strncpy(name, hotelName, sizeof(name) - 1);
        name[sizeof(name) - 1] = '\0';
        roomsArray = new Room[maxRooms];
    }

    ~Hotel() {
        delete[] roomsArray;
        delete currentEvent;
    }

    Room* getRoomsArray() const {
        return roomsArray;
    }

    const BookingQueue& getBookingQueue() const {
        return bookingQueue;
    }

    void addRoom(int roomNumber) {
        if (numRooms < MAX_ROOMS) {
            roomsArray[numRooms] = Room(roomNumber);
            roomsList.push_back(&roomsArray[numRooms]);
            ++numRooms;
        } else {
            cout << "Cannot add more rooms. Maximum limit reached." << endl;
        }
    }

    void addGuest(Guest* guest) {
        guests.push_back(guest);
    }

    Reservation* makeReservation(Guest* guest, Room* room) const {
        if (room && guest) {
            Reservation* reservation = new Reservation(room, guest);
            bookingQueue.bookRoom(reservation);
            return reservation;
        }
        return NULL;
    }

    void startEvent(const char* eventName) {
        if (currentEvent == NULL) {
            currentEvent = new Event(eventName);
        } else {
            cout << "An event is already in progress." << endl;
        }
    }

    void endEvent()  {
        delete currentEvent;
        currentEvent = NULL;
    }

    void addGuestToEvent(Guest* guest) const {
        if (currentEvent != NULL) {
            currentEvent->addAttendee(guest);
        } else {
            cout << "No event in progress to add guests to." << endl;
        }
    }

    void displayInformation() const {
        cout << "Hotel Name: " << name << endl;
        cout << "Number of Rooms: " << numRooms << endl;

        for (auto room : roomsList) {
            room->displayInformation();
        }

        cout << "Number of Guests: " << guests.size() << endl;

        for (auto guest : guests) {
            guest->displayInformation();
        }

        if (currentEvent != NULL) {
            currentEvent->displayInformation();
        }
    }
};

int main() {
    // Main Code for the Hotel Management System
    const int MAX_ROOMS = 100;
    Hotel hotel("Grand Hotel", MAX_ROOMS);    
    int choice;
    do {
        cout << "Hotel Management System Menu:" << endl;
        cout << "1. Add Room" << endl;
        cout << "2. Add Guest" << endl;
        cout << "3. Make Reservation" << endl;
        cout << "4. Cancel Reservation" << endl;
        cout << "5. Start Event" << endl;
        cout << "6. End Event" << endl;
        cout << "7. Add Guest to Event" << endl;
        cout << "8. Display Information" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int roomNumber;
                cout << "Enter Room Number: ";
                cin >> roomNumber;
                hotel.addRoom(roomNumber);
                break;
            }
            case 2: {
                char guestName[50];
                int guestAge;
                cout << "Enter Guest Name: ";
                cin.ignore(); // Ignore any leftover newline characters
                cin.getline(guestName, sizeof(guestName));
                cout << "Enter Guest Age: ";
                cin >> guestAge;
                Guest* guest = new Guest(guestName, guestAge);
                hotel.addGuest(guest);
                break;
            }
            case 3: {
                // Implementation for making a reservation
                break;
            }
            case 4: {
                // Implementation for canceling a reservation
                break;
            }
            case 5: {
                char eventName[50];
                cout << "Enter Event Name: ";
                cin.ignore();
                cin.getline(eventName, sizeof(eventName));
                hotel.startEvent(eventName);
                break;
            }
            case 6: {
                hotel.endEvent();
                break;
            }
            case 7: {
                // Implementation for adding a guest to an event
                break;
            }
            case 8: {
                hotel.displayInformation();
                break;
            }
            case 0: {
                cout << "Exiting program." << endl;
                break;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}