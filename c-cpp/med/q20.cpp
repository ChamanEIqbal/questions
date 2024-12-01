/**
 * You are tasked to debug a friend recommendation system to calculate mutual friends based on a unique 
 * user ID in an UNDIRECTED GRAPH.
 * 
 * Core Concepts:
 * - `unordered_map<int, unordered_set<int>>`: Represents the adjacency list. Each key is a user ID, and 
 *   the value is a set of friends.
 * - `unordered_set<int>`: Efficiently stores unique friends for quick lookups.
 * - `vector<pair<int, int>>`: Stores recommendations, with each pair representing `(friendID, mutualFriendCount)`. 
 *   The list is sorted in descending order of mutual friends.

 * Key STL Functions:
 * - `.insert`: Adds a unique element to a set.
 * - `.count`: Checks if an element exists in a set (returns 1 if true, 0 otherwise).
 * - `.rbegin()`/`.rend()`: Used for iterating and sorting in reverse order.
 * 
 * Expected Output:
 * - A correct listing of vertex : vertices connected
 * - A correct sorted list of friend recommendations based on the number of mutual friends.
 */



#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

class FriendGraph {
private:
    unordered_map<int, unordered_set<int>> m_graph;

public:
    void addUser(int user) {
        m_graph[user] = {};
    }

    void addFriendship(int user1, int user2) {
        m_graph[user1].insert(user2);
    }

    vector<pair<int, int>> recommendFriends(int user) {
        unordered_map<int, int> recommendationCount; 

        cout << "Calculating friend recommendations for User " << user << endl;

        for (const auto& [otherUser, friends] : m_graph) {
            
            int mutualFriends = 0;
            for (int friendOfUser : m_graph[user]) {
                if (friends.count(friendOfUser)) { 
                    mutualFriends++;
                }
            }
            
                recommendationCount[otherUser] = mutualFriends;
                cout << "User " << otherUser << " has " << mutualFriends << " mutual friends with User " << user << endl;
        }
        
        
        vector<pair<int, int>> recommendations;
        for (const auto& [potentialFriend, count] : recommendationCount) {
            recommendations.push_back({potentialFriend, count});
        }

        sort(recommendations.rbegin(), recommendations.rend());
        return recommendations;
    }

    void displayGraph() {
        for (const auto& [user, friends] : m_graph) {
            if(friends.empty()) continue;
            cout << "User " << user << ": ";
            for (int friendUser : friends) {
                cout << friendUser << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    FriendGraph graph;
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

    cout << "Graph:" << endl;
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
    
    
    cout << "\nFriend Recommendations for User 1:" << endl;
    vector<pair<int, int>> recommendations = graph.recommendFriends(1);
    for (const auto& [count, user] : recommendations) {
        cout << "User " << user << " (Mutual Friends: " << count << ")" << endl;
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
    

    return 0;
}
