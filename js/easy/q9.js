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
    constructor(id, name, destination, status) {
        this.id = id;
        this.name = name;
        this.destination = destination;
        this.status = status;
        this.next = null;
    }
}

class UFOFleet {
    constructor() {
        this.head = null;
    }

    addUFO(id, name, destination, status) {
        const newUFO = new UFO(id, name, destination, status);
        if (!this.head) {
            this.head = newUFO;
        } else {
            let temp = this.head;
            while (temp.next) {
                temp = temp.next;
            }
            temp.next = newUFO;
        }
    }

    removeUFO(id) {
        let temp = this.head;
        let prev = null;

        if (temp !== null && temp.id === id) {
            this.head = temp.next;
            return;
        }

        while (temp !== null && temp.id !== id) {
            prev = temp;
            temp = temp.next;
        }

        if (temp === null) {
            console.log(`UFO with ID ${id} not found.`);
            return;
        }

        prev.next = temp.next;
    }

    updateStatus(id, status) {
        let temp = this.head;
        while (temp !== null && temp.id !== id) {
            temp = temp.next;
        }
        if (temp) {
            temp.status = status;
        }
    }

    displayInFlight() {
        let temp = this.head;
        while (temp !== null) {
            if (temp.status === "In Flight) {
                console.log(`UFO ${temp.id} ${temp.name} ${temp.destination} ${temp.status}`);
                found = true;
            }
            temp = temp.next;
        }
    }

    displayFleet() {
        let temp = this.head;
        while (temp !== null) {
            console.log(`UFO ${temp.id} ${temp.name} ${temp.destination} ${temp.status}`);
            temp = temp.next;
        }
    }

    sortFleet() {

        for (let i = this.head; i !== null; i = i.next) {
            for (let j = i.next; j !== null; j = j.next) {
                if (i.destination > j.destination) {
                    let tempDest = i.destination;
                    let tempName = i.name;
                    let tempId = i.id;
                    let tempStatus = i.status;

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
}

function testCases() {
const fleet = new UFOFleet();

// test case 0
fleet.displayFleet(); // Expected Output: "No UFOs in list..."
fleet.sortFleet(); // Expected Output: "No fleet to sort."

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

fleet.updateStatus(103, "In Flight"); // Expected Output: UFO with ID 103, not found to update status of...
}

testCases(); // all should be passed, total output lines: 8.