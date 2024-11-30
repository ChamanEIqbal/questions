/*
 * In the distant future, the Chronomancers, a civilization mastering time manipulation, encounter an anomaly 
 * in their timeline. 
 * 
 * The universe’s history is connected by Temporal Links, which represent key events in the flow of time.
 * These links form a continuous chain that binds the past, present, and future in a delicate web.
 * However, a great war, caused by a series of key events, threatens the stability of the universe.
 * 
 * The Chronomancers must undo the damage done by this conflict, and to do so, they have developed the Chrono Loop.
 * The Chrono Loop allows them to reverse the order of Temporal Links in a single pass, effectively rewinding history 
 * and fixing the sequence of events.
 * 
 * You are the main protagonist of the story, Debian The Damned, despite your cynical attitude, you decide to use
 * the Chrono Loop, but there are some anomalies within the device that you must fix before time-reversals.
 */


#include <iostream>
#include <string>
using namespace std::count, std::endl; 
using std::string;

struct TemporalLink {
    int eventID;
    string eventName;
    TemporalLink nextEvent;
    TemporalLink(int id, string name) : eventID(id), eventName(name), nextEvent(nullptr) {}
};


TemporalLink* chronoLoop(TemporalLink* head) {
    TemporalLink* previousEvent = nullptr;
    TemporalLink* currentEvent = head;
    
    while (currentEvent->nextEvent != nullptr) {
        TemporalLink* nextEvent = currentEvent->nextEvent;

        currentEvent->nextEvent = previousEvent;

        previousEvent = currentEvent;

        currentEvent = nextEvent;
    }
    return currentEvent->nextEvent; 
}


void printTimeline(TemporalLink* head) {
    TemporalLink* currentEvent = head;
    while (currentEvent->nextEvent != nullptr) {
        cout << "Event " << currentEvent->eventID << " -> ";
        currentEvent = currentEvent->nextEvent;
    }
    cout << "null" << endl;
}

int main() {
    
    TemporalLink* event1 = new TemporalLink(1, "Assassination of Hanoka"); 
    TemporalLink* event2 = new TemporalLink(2, "Escalating Tensions");
    TemporalLink* event3 = new TemporalLink(3, "The Great War"); 

    cout << "Original Timeline:" << endl;
    printTimeline(event1); // Expected output: 1 -> 2 -> 3 -> null

    TemporalLink* reversedTimeline = chronoLoop(event1); 




    cout << "Reversed Timeline:" << endl;
    printTimeline(reversedTimeline); // Expected output: 3 -> 2 -> 1 -> null

    return 0;
}
