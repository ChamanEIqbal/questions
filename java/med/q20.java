/**
 * You are tasked to debug a friend recommendation system to calculate mutual friends based on a unique 
 * user ID in an UNDIRECED GRAPH.
 * 
 * Core Concepts:
 * - `HashMap<Integer, HashSet<Integer>>`: Represents the adjacency list. Each key is a user ID, and 
 *   the value is a `HashSet` of friends.
 * - `HashSet<Integer>`: Efficiently stores unique friends and allows quick lookups.
 * - `List<int[]>`: Stores recommendations as arrays `[friendID, mutualFriendCount]`. The list is 
 *   sorted in descending order of mutual friends.

 * Key Java Methods:
 * - `.add`: Adds a unique element to a `HashSet`.
 * - `.contains`: Checks if an element exists in a `HashSet`.
 * - `Collections.sort`: Used for sorting the recommendation list, with a custom comparator for descending order.

 * Expected Output:
 * - A correct listing of vertex : vertices connected
 * - A correct sorted list of friend recommendations based on the number of mutual friends.
 */



import java.util.*;

class FriendGraph {
    private final Map<Integer, Set<Integer>> graph = new HashMap<>();

    public void addUser(int user) {
        graph.put(user, new HashSet<>());
    }

    public void addFriendship(int user1, int user2) {
        if (graph.containsKey(user1) && graph.containsKey(user2)) {
            graph.get(user1).add(user2);
        }
    }

    public List<Map.Entry<Integer, Integer>> recommendFriends(int user) {
        Map<Integer, Integer> recommendationCount = new HashMap<>();

        System.out.println("Calculating friend recommendations for User " + user);

        for (Map.Entry<Integer, Set<Integer>> entry : graph.entrySet()) {
            int otherUser = entry.getKey();
            Set<Integer> friends = entry.getValue();

            int mutualFriends = 0;
            for (int friendOfUser : graph.get(user)) {
                if (friends.contains(friendOfUser)) {
                    mutualFriends++;
                }
            }

            recommendationCount.put(otherUser, mutualFriends);
            System.out.println("User " + otherUser + " has " + mutualFriends + " mutual friends with User " + user);
        }

        List<Map.Entry<Integer, Integer>> recommendations = new ArrayList<>(recommendationCount.entrySet());
        recommendations.sort((a, b) -> b.getValue() - a.getValue());
        return recommendations;
    }

    public void displayGraph() {
        for (Map.Entry<Integer, Set<Integer>> entry : graph.entrySet()) {
            int user = entry.getKey();
            Set<Integer> friends = entry.getValue();

            if (!friends.isEmpty()) {
                System.out.print("User " + user + ": ");
                for (int friend : friends) {
                    System.out.print(friend + " ");
                }
                System.out.println();
            }
        }
    }

    public static void main(String[] args) {
        FriendGraph graph = new FriendGraph();
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

        System.out.println("Graph:");
        graph.displayGraph();

        System.out.println("\nFriend Recommendations for User 1:");
        List<Map.Entry<Integer, Integer>> recommendations = graph.recommendFriends(1);
        for (Map.Entry<Integer, Integer> entry : recommendations) {
            System.out.println("User " + entry.getKey() + " (Mutual Friends: " + entry.getValue() + ")");
        }
    }
}
