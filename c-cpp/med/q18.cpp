/**
 * PROBLEM:
 * You are a Bank Employee, IT Specialist.
 * One day, you were at an ATM of your branch; but the ATM is giving you a whole lot more notes than you want,
 * 
 * 
 * You think, that maybe it's Sunday, and there are only small notes inside the ATM.
 * 
 * This happens to you many times, and you couldn't figure out why...
 * 
 * So you decide to open the ATM's programming yourself,
 * 
 * CONSTRAINTS:
 * The denominations of dispensing notes are following:
 * NOTE 100
 * NOTE 500
 * NOTE 1000
 * NOTE 5000
 * 
 * OUTPUTS:
 * Expected.
 */


#include <iostream>
#include <vector>
using namespace std;

void dispenseNotes(int withdrawalAmount, vector<int>denominations) {
    
    vector<int> notesCount(denominations.size(), 0);
    
    for (int i = 1; i < denominations.size(); i++) {
        if (withdrawalAmount >= denominations[i]) {
            notesCount[i] = withdrawalAmount / denominations[i];
            withdrawalAmount = withdrawalAmount % denominations[i];
        }
    }
    
    // Output the note count
    
        cout << "ATM Dispensed Notes:" << endl;
        for (int i = 0; i < denominations.size(); i++) {
            if (notesCount[i] > 0) {
                cout << "PKR" << denominations[i] << " : " << notesCount[i] << " note(s)" << endl;
            }
        }
}

int main() {
    int amount;
    vector<int> denominations = {100, 500, 1000, 5000}; // PKR denominations
    
    //test case 1:
    amount = 12000;
    dispenseNotes(amount, denominations); // Expected Notes: PKR5000: 2 note(s), PKR1000 2 note(s).
    
    //test case 2:
    amount = 500;
    dispenseNotes(amount, denominations); // Expected Notes: PKR500: 1 note(s).
    
    // test case 3:
    amount = 15500;
    dispenseNotes(amount, denominations); // Expected Notes: PKR5000: 3 note(s), PKR500: 1 note(s).
    
    //test case 4:
    amount = 1625;
    dispenseNotes(amount, denominations); // Expected output: cannot dispense with current denominations.
    
    return 0;
}
