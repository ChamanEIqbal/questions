#include <iostream>
#include <vector>
using namespace std::count, std::endl;

void bubbleSort(vector<int>& coordinates) {
    int n = coordinates.size();
    
    // Space Cadet starts the mission, but the robot's vision is clouded.
    
    for (int i = 0; i < n; i++) {  // 
        for (int j = 0; j < n - i; j++) {  
            if (coordinates[j] > coordinates[j + 1]) {
                swap(coordinates[j], coordinates[j + 1]);
            }
        }
    }
}

void printCoordinates(const vector<int>& coordinates) {
    cout << "Robot's sorted position coordinates: ";
    for (int coordinate : coordinates) {
        cout << coordinate << "\n";
    }
    cout << endl;
}

int main() {
    vector<int> robotCoordinates = {7, 3, 9, 2, 5, 4};  
    
    cout << "Mission: Sorting the robot's coordinates to help it see clearly!" << endl;

    bubbleSort(robotCoordinates);

    printCoordinates(robotCoordinates);  
    
    return 0;
}
