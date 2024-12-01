"""
You are tasked to debug a friend recommendation system to calculate mutual friends based on a unique 
user ID in an UNDIRECTED GRAPH.

Core Concepts:
- `defaultdict(set)`: Represents the adjacency list. Each key is a user ID, and the value is a `set` 
  of friends.
- `set`: Efficiently stores unique friends and allows quick lookups.
- `list[tuple[int, int]]`: Stores recommendations as tuples `(friendID, mutualFriendCount)`. The list 
  is sorted in descending order of mutual friends.

Key Python Methods:
- `.add`: Adds a unique element to a `set`.
- `in`: Checks if an element exists in a `set`.
- `sorted`: Sorts the recommendation list using `key=lambda x: x[1]` for mutual friends, 
  with `reverse=True` for descending order.

Expected Output:
- A correct listing of vertex : vertices connected
- A correct sorted list of friend recommendations based on the number of mutual friends.
"""

class FriendGraph:
    def __init__(self):
        self.graph = {}

    def add_user(self, user):
        self.graph[user] = set()

    def add_friendship(self, user1, user2):
        if user1 in self.graph and user2 in self.graph:
            self.graph[user1].add(user2)

    def recommend_friends(self, user):
        recommendation_count = {}
        print(f"Calculating friend recommendations for User {user}")

        for other_user, friends in self.graph.items():

            mutual_friends = sum(1 for friend_of_user in self.graph[user] if friend_of_user in friends)

            recommendation_count[other_user] = mutual_friends
            print(f"User {other_user} has {mutual_friends} mutual friends with User {user}")

        recommendations = sorted(recommendation_count.items(), key=lambda x: -x[1])
        return recommendations

    def display_graph(self):
        for user, friends in self.graph.items():
            if friends:
                print(f"User {user}: {' '.join(map(str, friends))}")


graph = FriendGraph()
graph.add_user(1)
graph.add_user(2)
graph.add_user(3)
graph.add_user(4)
graph.add_user(5)
graph.add_user(6)
graph.add_friendship(1, 2)
graph.add_friendship(6, 2)
graph.add_friendship(1, 3)
graph.add_friendship(2, 4)
graph.add_friendship(3, 4)

print("Graph:")
graph.display_graph()

print("\nFriend Recommendations for User 1:")
recommendations = graph.recommend_friends(1)
for user, count in recommendations:
    print(f"User {user} (Mutual Friends: {count})")
