"""
 # In the distant future, the Chronomancers, a civilization mastering time manipulation, encounter an anomaly 
 # in their timeline. 
 # 
 # The universe’s history is connected by Temporal Links, which represent key events in the flow of time.
 # These links form a continuous chain that binds the past, present, and future in a delicate web.
 # However, a great war, caused by a series of key events, threatens the stability of the universe.
 # 
 # The Chronomancers must undo the damage done by this conflict, and to do so, they have developed the Chrono Loop.
 # The Chrono Loop allows them to reverse the order of Temporal Links in a single pass, effectively rewinding history 
 # and fixing the sequence of events.
 # 
 # You are the main protagonist of the story, Debian The Damned, despite your cynical attitude, you decide to use
 # the Chrono Loop, but there are some anomalies within the device that you must fix before time-reversals.
 """

class TemporalLink:
    def __init__(self, event_id, event_name):
        self.eventID = event_id
        self.eventName = event_name
        self.nextEvent = None


def chronoLoop(head):
    previousEvent = None
    currentEvent = head
    
    while currentEvent.nextEvent is not None:
        nextEvent = currentEvent.nextEvent

        currentEvent.nextEvent = previousEvent

        previousEvent = currentEvent

        currentEvent = nextEvent

    return currentEvent.nextEvent


def printTimeline(head):
    currentEvent = head
    while currentEvent.nextEvent is not None:
        print(f"Event {currentEvent.eventID} -> ", end="")
        currentEvent = currentEvent.nextEvent
    print("null")


if __name__ == "__main__":
    event1 = TemporalLink(1, "Assassination of Hanoka")
    event2 = TemporalLink(2, "Escalating Tensions")
    event3 = TemporalLink(3, "The Great War")
    

    print("Original Timeline:")
    printTimeline(event1)  # Expected output: 1 -> 2 -> 3 -> null

    reversedTimeline = chronoLoop(event1)

    print("Reversed Timeline:")
    printTimeline(reversedTimeline)  # Expected output: 3 -> 2 -> 1 -> null
