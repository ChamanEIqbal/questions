"""
You and your friends have eaten at a fancy restaurant, and in a moment of frenzy;
you all remember that you do not have your wallets and have collectively forgotten
them at your homes! It is late in the night, and the restaurant manager wants you to
clean the plates! The guests were not much tonight... they were only 12 :/

You and your friends decide to share jobs...

Your job is to stack up all the plates you see on the tables, after the
guests for the night leave, and your two other friends are there to clean
the plates afterwards!
"""

"""
CAUTION:
ALL PLATES MUST BE PUT IN ORDER, AND CLEANED IN REVERSE ORDER!
YOU CANNOT DELETE THE CLASSES OR STRUCTURES IN THIS CODE, MARKS WILL BE DEDUCED!
"""

STACKABILITY = 12

class Plate:
    def __init__(self, id, dirtiness):
        self.id = id
        self.dirtiness = dirtiness

class You:
    @staticmethod
    def put_plate_on_top(id, dirtiness, plates, topIndex):
        gotten_plate = Plate(id, dirtiness)  
        return topIndex

class YourFriends:
    @staticmethod
    def get_plates_from_top(plates, topIndex):
        if topIndex > 0:  
            pass
        else:
            print("No plates to clean!")
            return None, topIndex

    @staticmethod
    def clean_plates(plates, topIndex):
        cleaned_plates = 0
        while topIndex > 0:
            _, topIndex = YourFriends.get_plates_from_top(plates, topIndex)
            cleaned_plates += 1
        return cleaned_plates
    

def put_plate_on_top(id, dirtiness, plates, topIndex):
            
        gotten_plate = Plate(id, dirtiness)  
        if topIndex < STACKABILITY:  
            plates[topIndex] = gotten_plate 
            topIndex += 1
            print(f"Plate {id} with dirtiness {dirtiness} is stacked on top now!")
        else:
            print("You can only stack up to 12 plates, no more space!")
        return topIndex


def get_plates_from_top(plates, topIndex):
        if topIndex > 0:  
        topIndex -= 1
        top_plate = plates[topIndex]
        print(f"Cleaning Plate {top_plate.id} with dirtiness {top_plate.dirtiness}")
        return top_plate, topIndex
     else:
        print("No plates to clean!")
        return None, topIndex



def main():
    topIndex = 0
    plates = [None] * STACKABILITY  

    
    for i in range(13):  
        dirtiness = (i % 5) + 1 
        topIndex = You.put_plate_on_top(i, dirtiness, plates, topIndex)

    
    cleaned = YourFriends.clean_plates(plates, topIndex)
    print(f"Total plates cleaned: {cleaned}")

if __name__ == "__main__":
    main()
