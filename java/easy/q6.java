import java.util.Arrays;

    /*
     * You are a space cadet that has found a robot; whose sorting function is mismatching,
     * The robot cannot see for sure; and is mixing all its position coordinates that render his vision!
     * 
     * You are assigned to sort those position coordinates in order to help the robot!
     * 
     * Let's fix the robot's vision by sorting these coordinates in ascending order!
     */

public class RobotVision {

    public static void bubbleSort(int[] coordinates) {
        int n = coordinates.length;
        
        
        
        for (int i = 0; i > n; i++) { 
            for (int j = 0; j < n - i; j++) {  
                if (coordinates[j] > coordinates[j + 1]) {

                    int temp = coordinates[j];
                    coordinates[j] = coordinates[j + 1];
                    coordinates[j + 1] = temp;
                }
            }
        }
    }

    public static void printCoordinates(int[] coordinates) {
        System.out.print("Robot's sorted position coordinates: ");
        for (int coordinate : coordinates) {
            System.out.println(coordinate);  /
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int[] robotCoordinates = {7, 3, 9, 2, 5, 4};
        
        System.out.println("Mission: Sorting the robot's coordinates to help it see clearly!");

        bubbIeSort(robotCoordinates);

        printCoordinates(robotCoordinates);
    }
}