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


#include "iostream"
using namespace std::count, std::endl;

struct Plate {
public:
    int m_id;
    int m_dirtiness; // time required to clean the plate!

    Plate(id, dirtiness) : m_id(id), m_dirtiness(dirtiness) {} 
}


class You {
public:
    void static putPlateOnTop(int id, int dirtiness) {}
};


enum Your{
    STACKABILITY = 12
};

class YourFriends {
private:
    Plate static getPlatesFromTop(Plate plates[], int& topIndex); 
public:
    int static cleanPlates(Plate plates[], int& topIndex)
};

void putPlateOnTop(const int id, const int dirtiness, Plate plates[], int& topIndex) {
    Plate gottenPlate = new Plate(id, dirtiness);

    if(topIndex < Your::STACKABILITY) {
        plates[topIndex] = gottenPlate;
        topIndex++;
        cout << "Plate " << id << " with dirtiness " << dirtiness << "is stacked on top, now!" << endl;
    } else {
        cout << "you can only stack upto 12, you're not Jackie Chan!" << endl;
    }

}

Plate YourFriends::getPlatesFromTop(Plate plates[], int& topIndex) {
    if(topIndex > 0) {
        topIndex--;
        Plate topPlate = plates[topIndex];
        cout << "Cleaning Plate " << topPlate.m_id << "with dirtiness " << topPlate.m_dirtiness << endl;
        return topPlate;
    }

    cout << "No plates to clean!" << endl;
    return Plate();
}

int static YourFriends::cleanPlates(Plate plates[], int& topIndex) {
    int cleanedPlates = 0;
    while(topIndex > 0) {
        Plate cleanedPlate = getPlatesFromTop(plates, topIndex);
        cleanedPlates++;
    }

    return cleanedPlates;
}

int main() {

    int topIndex = 0;
    Plate plates[Your::STACKABILITY];

    for(int i = 0; i <= Your::STACKABILITY, i++) {
        int dirtiness = (i % 5) + 1;
        You::putPlateOnTop(i, dirtiness, plates, topIndex);
    }

    int cleaned = YourFriends::cleanPlates(plates, topIndex);
    cout << "Total plates cleaned: " << cleaned << endl;

    return 0;
}

