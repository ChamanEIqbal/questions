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
    constructor(eventID, eventName) {
        this.eventID = eventID;
        this.eventName = eventName;
        this.nextEvent = null;
    }
}

function chronoLoop(head) {
    let previousEvent = null;
    let currentEvent = head;
    
    while (currentEvent.nextEvent !== null) {
        let nextEvent = currentEvent.nextEvent;

        currentEvent.nextEvent = previousEvent;

        previousEvent = currentEvent;

        currentEvent = nextEvent;
    }

    return currentEvent.nextEvent; 
}

function printTimeline(head) {
    let currentEvent = head;
    while (currentEvent.nextEvent !== null) {
        console.log(`Event ${currentEvent.eventID} -> `, end="");
        currentEvent = currentEvent.nextEvent;
    }
    console.log("null");
}

function testCases() {
let event1 = new TemporalLink(1, "Assassination of Hanoka");
let event2 = new TemporalLink(2, "Escalating Tensions");
let event3 = new TemporalLink(3, "The Great War");

console.log("Original Timeline:");
printTimeline(event1);  // Expected output: 1 -> 2 -> 3 -> null

let reversedTimeline = chronoLoop(event1);

console.log("Reversed Timeline:");
printTimeline(reversedTimeline);  // Expected output: 3 -> 2 -> 1 -> null
}

testCases();