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
 * The denominations of dispensing notes are as follows:
 * NOTE 100
 * NOTE 500
 * NOTE 1000
 * NOTE 5000
 * 
 * OUTPUTS:
 * Expected.
 * 
 * INPUTS: Cannot be changed.
 */

import java.util.ArrayList;
import java.util.List;

public class ATM {
    
    public static void dispenseNotes(int withdrawalAmount, List<Integer> denominations) {
        List<Integer> notesCount = new ArrayList<>();
        for (int i = 0; i < denominations.size(); i++) {
            notesCount.add(0);  // Initialize with 0
        }
        
        for (int i = 1; i < denominations.size(); i++) {
            if (withdrawalAmount >= denominations.get(i)) {
                notesCount.set(i, withdrawalAmount / denominations.get(i));
                withdrawalAmount = withdrawalAmount % denominations.get(i);
            }
        }
        
        // Output the note count
        System.out.println("ATM Dispensed Notes:");
        for (int i = 0; i < denominations.size(); i++) {
            if (notesCount.get(i) > 0) {
                System.out.println("PKR" + denominations.get(i) + " : " + notesCount.get(i) + " note(s)");
            }
        }
    }

    public static void main(String[] args) {
        List<Integer> denominations = new ArrayList<>();
        denominations.add(100);
        denominations.add(500);
        denominations.add(1000);
        denominations.add(5000);  // PKR denominations
        
        // test case 1:
        int amount = 12000;
        dispenseNotes(amount, denominations); // Expected Notes: PKR5000: 2 note(s), PKR1000 2 note(s).
        
        // test case 2:
        amount = 500;
        dispenseNotes(amount, denominations); // Expected Notes: PKR500: 1 note(s).
        
        // test case 3:
        amount = 15500;
        dispenseNotes(amount, denominations); // Expected Notes: PKR5000: 3 note(s), PKR500: 1 note(s).
        
        // test case 4:
        amount = 1625;
        dispenseNotes(amount, denominations); // Expected output: cannot dispense with current denominations.
    }
}
