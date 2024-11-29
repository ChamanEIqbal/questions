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

class UFO {
    int id;
    String name;
    String destination;
    String status;
    UFO next;

    UFO(int id, String name, String destination, String status) {
        this.id = id;
        this.name = name;
        this.destination = destination;
        this.status = status;
        this.next = null;
    }
}

class UFOFleet {
    UFO head;

    public UFOFleet() {
        head = null;
    }

    public void addUFO(int id, String name, String destination, String status) {
        UFO newUFO = new UFO(id, name, destination, status);
        if (head == null) {
            head = newUFO;
        } else {
            UFO temp = head;
            while (temp.next != null) {
                temp = temp.next;
            }
            temp.next = newUFO;
        }
    }

    public void removeUFO(int id) {
        UFO temp = head;
        UFO prev = null;

        if (temp != null && temp.id == id) {
            head = temp.next;
            return;
        }

        while (temp != null && temp.id != id) {
            prev = temp;
            temp = temp.next;
        }

        if (temp == null) {
            System.out.println("UFO with ID " + id + " not found.");
            return;
        }

        prev.next = temp.next;
    }

    public void updateStatus(int id, String status) {
        UFO temp = head;
        while (temp != null && temp.id != id) {
            temp = temp.next;
        }
        if (temp != null) {
            temp.status = status;
        }
    }

    public void displayInFlight() {
        UFO temp = head;
        while (temp != null) {
            if ("In Flight.equals(temp.status)) {
                System.out.println("UFO " + temp.id + " " + temp.name + " " + temp.destination + " " + temp.status);
            }
            temp = temp.next;
        }
    }

    public void displayFleet() {
        UFO temp = head;
        while (temp != null) {
            System.out.println("UFO " + temp.id + " " + temp.name + " " + temp.destination + " " + temp.status);
            temp = temp.next;
        }
    }

    public void sortFleet() {

        for (UFO i = head; i != null; i = i.next) {
            for (UFO j = i.next; j != null; j = j.next) {
                if (i.destination.compareTo(j.destination) > 0) {
                    String tempDest = i.destination;
                    String tempName = i.name;
                    int tempId = i.id;
                    String tempStatus = i.status;

                    i.destination = j.destination;
                    i.name = j.name;
                    i.id = j.id;
                    i.status = j.status;

                    j.destination = tempDest;
                    j.name = tempName;
                    j.id = tempId;
                    j.status = tempStatus;
                }
            }
        }
    }

    public static void main(String[] args) {
        UFOFleet fleet = new UFOFleet();

        // test case 0
        fleet.displayFleet(); // Expected Output: "No UFOs in list..."
        fleet.sortFleet(); // Expected Output: "Cannot Sort empty fleet!" 

        fleet.addUFO(101, "Galactic Explorer", "Mars", "Scheduled");
        fleet.addUFO(102, "Star Voyager", "Jupiter", "Scheduled");
        // test case 1
        fleet.updateStatus(101, "in flight");
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

        // test case 2
        fleet.updateStatus(103, "In Flight"); // Expected Output: UFO with ID 103, not found to update status of...
    }
} // total output lines: 8.
