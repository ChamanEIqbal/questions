/**
 * Welcome to the UFO Flight Management System (UFOMS)! The Earth has just discovered a fleet of UFOs, and we need a system to manage their takeoffs, landings, and flight details. The system should be built using a linked list to keep track of the UFOs currently in flight.

Each UFO has the following information:

    UFO ID: A unique integer identifier.
    UFO Name: A descriptive name of the UFO.
    Destination: The destination planet the UFO is heading to.
    Flight Status: Whether the UFO is currently "In Flight", "Landed", or "Scheduled" for departure.

Your job is to implement a linked list to manage the UFO fleet. Here's the list of required operations you need to perform:

    Add UFO to Fleet: Insert a UFO at the end of the linked list.
    Remove UFO from Fleet: Remove a UFO by its ID.
    Update UFO Status: Change the flight status of a UFO to either "In Flight", "Landed", or "Scheduled".
    Display UFOs in Flight: Display the UFOs that are currently "In Flight".
    Find UFO by ID: Given a UFO ID, return the details of the UFO if it exists.
    Sort UFO Fleet: Sort the UFOs by their destination in alphabetical order.

Problem Description:

Your task is to implement the linked list operations for the UFO Flight Management System (UFOMS). However, you will face bugs in the code that are intentionally placed to test your debugging skills.
Bugs and Challenges!

Your Task:

    Debug the Code: Given a partially implemented flight management system, fix the bugs to ensure all operations work correctly.
    Test the System: After fixing the issues, run test cases to ensure all the functions work as expected.

Input/Output Format:

    Input: A sequence of commands to manage UFOs.
    Output: Print the updated fleet after each operation and display the correct information.
    Follow "Expected" comments, carefully.
 */

#include <iostream>
#include <string>
using namespace std;

struct UFO {
    int id;
    string name;
    string destination;
    string status;
    UFO* next;
};

class UFOFleet {
private:
    UFO* head;
    
public:
    UFOFleet() : head(nullptr) {}

    
    void addUFO(int id, string name, string destination, string status) {
        UFO* newUFO = new UFO{id, name, destination, status, nullptr};
        if (!head) {
            head = newUFO;
        } else {
            UFO* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newUFO;
        }
    }

    
    void removeUFO(int id) {
        UFO* temp = head;
        UFO* prev = nullptr;
        
    
        if (temp != nullptr && temp->id == id) {
            head = temp->next; 
            delete temp; 
            return;
        }

    
        while (temp != nullptr && temp->id != id) {
            prev = temp;
            temp = temp->next;
        }

    
        if (temp == nullptr) {
            cout << "UFO with ID " << id << " not found." << endl;
            return;
        }

    
        prev->next = temp->next;
        delete temp; 
    }

    
    void updateStatus(int id, string status) {
        UFO* temp = head;
        while (temp != nullptr && temp->id != id) {
            temp = temp->next;
        }
        if (temp) {
            temp->status = status;
        }
    }

    
    void displayInFlight() {
        UFO* temp = head;
        bool found = false;
        while (temp) {
            if (temp->status == "In Flight) {
                cout << "UFO " << temp->id << " " << temp->name << " " << temp->destination << " " << temp->status << endl;
                found = true;
            }
            temp = temp->next;
        }
        if (!found) {
            cout << "No UFOs currently in flight." << endl;
        }
    }

    void displayFleet() {
        UFO* temp = head;
        while (temp) {
            cout << "UFO " << temp->id << " " << temp->name << " " << temp->destination << " " << temp->status << endl;
            temp = temp->next;
        }
    }


    void sortFleet() {
        for (UFO* i = head; i != nullptr; i = i->next) {
            for (UFO* j = i->next; j != nullptr; j = j->next) {

                if (i->destination > j->destination) {
                    swap(i->destination, j->destination);
                    swap(i->name, j->name);
                    swap(i->id, j->id);
                    swap(i->status, j->status);
                }
            }
        }
    }
};

int main() {
    UFOFleet fleet;

    // test case 0
    fleet.displayFleet(); // Expected Output: No UFOs in list...
    fleet.sortFleet(); // Expected Output: No fleet to sort!
    
    fleet.addUFO(101, "Galactic Explorer", "Mars", "Scheduled");
    fleet.addUFO(102, "Star Voyager", "Jupiter", "Scheduled");
    // test case 1
    fleet.updateStatus(101, "In flight");
    fleet.displayInFlight(); // Expected Output: "UFO 101 Galactic Explorer Mars In Flight"
    

    fleet.displayFleet(); 
    /**
     * Expected Output:
     * UFO 101 Galactic Explorer Mars In Flight
     * UFO 102 Star Voyager Jupiter In Flight
     */
    fleet.sortFleet();  // Sorting fleet by destination

    fleet.displayFleet();  
    /**
     * Expected Output:
     * UFO 102 Star Voyager Jupiter In Flight
     * UFO 101 Galactic Explorer Mars In Flight
     */

    //test case 2
    fleet.updateStatus(103, "In Flight"); // Expected Output: UFO with ID 103, not found to update status of...

    return 0;
} // total output lines: 8.
