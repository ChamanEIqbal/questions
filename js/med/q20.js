/**
 * You are tasked to debug a friend recommendation system to calculate mutual friends based on a unique 
 * user ID in an UNDIRECTED GRAPH.
 * 
 * Core Concepts:
 * - `Map`: Represents the adjacency list. Each key is a user ID, and the value is a `Set` of friends.
 * - `Set`: Efficiently stores unique friends and allows quick lookups.
 * - `Array`: Stores recommendations as `[friendID, mutualFriendCount]`. The array is sorted in descending 
 *   order of mutual friends.

 * Key JavaScript Methods:
 * - `.add`: Adds a unique element to a `Set`.
 * - `.has`: Checks if an element exists in a `Set`.
 * - `.sort`: Sorts the recommendation list. Use a custom comparison function for descending order.

 * Expected Output:
 * - A correct listing of vertex : vertices connected
 * - A correct sorted array of friend recommendations based on the number of mutual friends.
 */


class FriendGraph {
    constructor() {
        this.graph = new Map();
    }

    addUser(user) {
        this.graph.set(user, new Set());
    }

    addFriendship(user1, user2) {
        if (this.graph.has(user1) && this.graph.has(user2)) {
            this.graph.get(user1).add(user2);
        }
    }

    recommendFriends(user) {
        const recommendationCount = new Map();
        console.log(`Calculating friend recommendations for User ${user}`);

        for (const [otherUser, friends] of this.graph.entries()) {

            let mutualFriends = 0;
            for (const friendOfUser of this.graph.get(user)) {
                if (friends.has(friendOfUser)) {
                    mutualFriends++;
                }
            }

            recommendationCount.set(otherUser, mutualFriends);
            console.log(`User ${otherUser} has ${mutualFriends} mutual friends with User ${user}`);
        }

        const recommendations = Array.from(recommendationCount.entries())
            .sort((a, b) => b[1] - a[1]);
        return recommendations;
    }

    displayGraph() {
        for (const [user, friends] of this.graph.entries()) {
            if (friends.size > 0) {
                console.log(`User ${user}: ${[...friends].join(' ')}`);
            }
        }
    }
}

const graph = new FriendGraph();
graph.addUser(1);
graph.addUser(2);
graph.addUser(3);
graph.addUser(4);
graph.addUser(5);
graph.addUser(6);
graph.addFriendship(1, 2);
graph.addFriendship(6, 2);
graph.addFriendship(1, 3);
graph.addFriendship(2, 4);
graph.addFriendship(3, 4);

console.log("Graph:");
graph.displayGraph();

    // Expected Output (flexible):
    /*
     *  User 6: 2
        User 5:
        User 4: 3 2 
        User 3: 4 1 
        User 2: 4 1 
        User 1: 3 2
    */
    

console.log("\nFriend Recommendations for User 1:");
const recommendations = graph.recommendFriends(1);
for (const [user, count] of recommendations) {
    console.log(`User ${user} (Mutual Friends: ${count})`);
}


// Expected Output:
    /**
     * Friend Recommendations for User 1:
     * Calculating Friend Recommendations for User 1
     * User 4 has 2 mutual friends with User 1
     * User 6 has 1 mutual friends with User 1
     * User 4 (Mutual Friends: 2)
     * User 6 (Mutual Friends: 1)
     */