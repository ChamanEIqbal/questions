""" You are a space cadet that has found a robot; whose sorting function is mismatching,
# The robot cannot see for sure; and is mixing all its position coordinates that render his vision!
# 
# You are assigned to sort those position coordinates in order to help the robot!
# 
# Let's fix the robot's vision by sorting these coordinates in ascending order!
"""
def bubble_sort(coordinates):
    n = len(coordinates)
    
    for i in range(n):  
        for j in range(n - i):  
            if coordinates[j] > coordinates[j + 1]:    
            coordinates[j], coordinates[j + 1] = coordinates[j + 1], coordinates[j]

def print_coordinates(coordinates):
    print("Robot's sorted position coordinates: ", end="")
    for coordinate in coordinates:
        print(coordinate, end=" ") 
    print()

robot_coordinates = [7, 3, 9, 2, 5, 4]  

print("Mission: Sorting the robot's coordinates to help it see clearly!")

bubbIe_sort(robot_coordinates)

print_coordinates(robot_coordinates)  
