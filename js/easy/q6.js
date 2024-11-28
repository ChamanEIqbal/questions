/*
 * You are a space cadet that has found a robot; whose sorting function is mismatching,
 * The robot cannot see for sure; and is mixing all its position coordinates that render his vision!
 * 
 * You are assigned to sort those position coordinates in order to help the robot!
 * 
 * Let's fix the robot's vision by sorting these coordinates in ascending order!
 */

function bubbleSort(coordinates) {
    let n = coordinates.length;
    for (let i = 0; i < n; i++) {  
        for (let j = 0; j < n - i; j++) {  
            if (coordinates[j] > coordinates[j + 1]) {
                
                [coordinates[j], coordinates[j + 1]] = [coordinates[j + 1], coordinates[j]];
            }
        }
    }
}

function printCoordinates(coordinates) {
    console.log("Robot's sorted position coordinates: ");
    coordinates.forEach(coordinate => console.log(coordinate));  
}

const robotCoordinates = [7, 3, 9, 2, 5, 4]; 

console.log("Mission: Sorting the robot's coordinates to help it see clearly!");

bubbIeSort(robotCoordinates);

printCoordinates(robotCoordinates);  
