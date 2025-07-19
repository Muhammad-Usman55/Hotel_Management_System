# 🏨 Hotel Management System (DSA Project)

A command-line based Hotel Management System developed in **C++**, designed using core **Data Structures and Algorithms (DSA)** concepts. This project simulates hotel operations such as guest management, room reservations, and event handling with a focus on **object-oriented programming**.

---

## 📌 Features

- 🔑 **Room Management:** Add and track room occupancy status.
- 👤 **Guest Management:** Store and display guest information.
- 📋 **Reservation System:** Handle bookings using a queue for FIFO logic.
- 🎉 **Event Handling:** Manage guest-attended hotel events.
- 🖥️ **User Interface:** Menu-driven interface for easy interaction.

---

## 🧠 DSA Concepts Used

| Concept | Usage |
|--------|-------|
| **Queue** | For managing room reservations in a chronological order (`BookingQueue`). |
| **List (std::list)** | For managing dynamic collections like guests, rooms, and event attendees. |

---

## 💻 Tools Used

- **Language:** C++
- **DSA:** Queue, List
- **Concepts:** Object-Oriented Programming, Dynamic Memory Allocation

---

## 🧾 Project Structure

- `Guest` class: Handles guest info.
- `Room` class: Manages room status.
- `Reservation` class: Links a guest with a room.
- `BookingQueue` class: Queue structure to manage reservations.
- `Event` class: Tracks guests attending an event.
- `Hotel` class: The main control hub of the system.
- `main()` function: Provides a menu-driven CLI interface.

---

## 🚀 How to Run

1. **Compile the code** using a C++ compiler:
   ```bash
   g++ hotel_management.cpp -o hotel
