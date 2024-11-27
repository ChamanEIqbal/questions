/**
 * You and your friends have eaten at a fancy restaurant, and in a moment of frenzy;
 * you all remember that you do not have your wallets and have collectively forgetten
 * them at your homes! It is late in the night, and the restaurant manager wants you to
 * clean the plates!
 * 
 * 
 * You and your friends decide to share jobs...
 * 
 * Your job is to stack up all the plates you see on the tables, after the
 * guests for the night leave, and your two other friends are there to clean
 * the plates afterwards!
 * 
 * 
 */


/**
 * CAUTION:
 * ALL PLATES MUST BE PUT IN ORDER, AND CLEANED IN REVERSE ORDER!
 * YOU CANNOT DELETE THE CLASSES OR STRUCTURES IN THIS CODE, MARKS WILL BE DEDUCED!
 */

public class TrickySituation {

    static class Plate {
        public int id;
        public int dirtiness;
    

        Plate(id, dirtiness) {
            id = id;
            dirtiness = dirtiness;
        }
    }

    static class You {
        public static void putPlateOnTop(int id, int dirtiness) {}
    }



    public static void putPlateOnTop(int id, int diritness, Plate[] plates, int topIndex) {
        Plate gottenPlate = new Plate(id, dirtiness);

        if(topIndex < Your.STACKABILITY.getValue()) {
            plates[topIndex] = gottenPlate;
            topIndex++;
            System.out.println("Plate " + id + " with dirtiness " + dirtiness + " is stacked on top, now!");
        } else {
            System.out.println("You can only stack up to 12, you're not Jackie Chan!");
        }
    }



    enum Your {
        STACKABILITY(12);

        private final int value;
        Your(int value) {
            this.value = value;
        }

        public int getValue() {return this.value;}
    }


    static class YourFriends {
        private static Plate getPlatesFromTop(Plate[] plates, int topIndex) {
            if(topIndex > 0) {
                topIndex--;
                Plate topPlate = plates[topIndex];
                System.out.println("Cleaning Plate " + topPlate.id + " with dirtiness level: " + topPlate.dirtiness)
                return topPlate;
            } else {
                System.out.println("No plates to clean!");
                return new Plate(-1,-1);
            }
        }

        public static int cleanPlates(Plate[], plates, int topIndex) {
                int cleanedPlates = 0;
                while (topIndex > 0) {
                    Plate cleanedPlate = getPlatesFromTop(plates, topIndex);
                    cleanedPlates++;
                }
                return cleanedPlates;
            }
        }



    public static void main(string args[]) {
        int topIndex = 0;
        Plate[] plates = new Plate[Your.STACKABILITY.getValue()]; 

        for (int i = 0; i < Your.STACKABILITY.getValue(); i++) { 
            int dirtiness = (i % 5) + 1; 
            You.putPlateOnTop(i, dirtiness, plates, topIndex);
            topIndex++;
        }

        int cleaned = YourFriends.cleanPlates(plates, topIndex);
        System.out.println("Total plates cleaned: " + cleaned);
    }
} 