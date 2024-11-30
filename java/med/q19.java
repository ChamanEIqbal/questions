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

class TemporalLink {
    int eventID;
    String eventName;
    TemporalLink nextEvent;

    public TemporalLink(int eventID, String eventName) {
        this.eventID = eventID;
        this.eventName = eventName;
        this.nextEvent = null;
    }
}

public class Chronomancy {
    
    public static TemporalLink chronoLoop(TemporalLink head) {
        TemporalLink previousEvent = null;
        TemporalLink currentEvent = head;
        
        while (currentEvent.nextEvent != null) {
            TemporalLink nextEvent = currentEvent.nextEvent;

            currentEvent.nextEvent = previousEvent;

            previousEvent = currentEvent;

            currentEvent = nextEvent;
        }

        return currentEvent.nextEvent; 
    }

    public static void printTimeline(TemporalLink head) {
        TemporalLink currentEvent = head;
        while (currentEvent.nextEvent != null) {
            System.out.print("Event " + currentEvent.eventID + " -> ");
            currentEvent = currentEvent.nextEvent;
        }
        System.out.println("null");
    }

    public static void main(String[] args) {
        
        TemporalLink event1 = new TemporalLink(1, "Assassination of Hanoka");
        TemporalLink event2 = new TemporalLink(2, "Escalating Tensions");
        TemporalLink event3 = new TemporalLink(3, "The Great War");

        System.out.println("Original Timeline:");
        printTimeline(event1);  // Expected output: 1 -> 2 -> 3 -> null

        TemporalLink reversedTimeline = chronoLoop(event1);

        System.out.println("Reversed Timeline:");
        printTimeline(reversedTimeline);  // Expected output: 3 -> 2 -> 1 -> null
    }
}
