/**
 * You and your friends have eaten at a fancy restaurant, and in a moment of frenzy;
 * you all remember that you do not have your wallets and have collectively forgotten
 * them at your homes! It is late in the night, and the restaurant manager wants you to
 * clean the plates! The guests were not much tonight... they were only 12 :/
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

class Plate {
    constructor(id, dirtiness) {
        this.id = id;
        this.dirtiness = dirtiness;
    }
}

class You {
    static putPlateOnTop() {}
}

const Your = {
    STACKABILITY: 12
}

class YourFriends {
    static getPlatesFromTop() {}

    static cleanPlates(plates, topIndex) {
        let cleanedPlates = 0;
        while (topIndex > 0) {
            let cleanedPlate = YourFriends.getPlatesFromTop(plates, topIndex);
            cleanedPlates++;
        }
        return cleanedPlates;
    }
}

function putPlateOnTop(id, dirtiness, plates, topIndex) {
    let gottenPlate = new Plate(id, dirtiness);

    if (topIndex < Your.STACKABILITY) {
        plates[topIndex] = gottenPlate;
        topIndex++;
        console.log(`Plate ${id} with dirtiness ${dirtiness} is stacked on top now!`);
    } else {
        console.log("You can only stack up to 12 plates, you're not Jackie Chan!");
    }
}

function getPlatesFromTop(plates, topIndex) {
    if (topIndex > 0) {
        let topPlate = plates[topIndex];
        topIndex--;
        console.log(`Cleaning Plate ${topPlate.id} with dirtiness ${topPlate.dirtiness}`);
        return topPlate;
    }

    console.log("No plates to clean!");
    return new Plate(-1, -1);
}

function cleanPlates(plates, topIndex) {
    let cleanedPlates = 0;
    while (topIndex > 0) {
        let cleanedPlate = getPlatesFromTop(plates, topIndex);
        cleanedPlates++;
    }

    return cleanedPlates;
}

function main() {
    let topIndex = 0;
    let plates = new Array(Your.STACKABILITY);

    for (let i = 0; i <= Your.STACKABILITY; i++) { 
        let dirtiness = (i % 5) + 1;
        You.putPlateOnTop(i, dirtiness); 
    }

    let cleaned = YourFriends.cleanPlates(plates, topIndex);
    console.log("Total plates cleaned: " + cleaned)
}

main();

