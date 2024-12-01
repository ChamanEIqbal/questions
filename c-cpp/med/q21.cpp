/**
 * Imagine you’re managing a water supply using two buckets!
 * 
 * Bucket1 is used to pour water into the system (enqueue), while Bucket2 is used to deliver water (dequeue).
 * If Bucket2 is empty when you need water, you first transfer all the water from Bucket1 into Bucket2. 
 * This process ensures you deliver water in the correct order, even though you poured it in reverse.
 *
 *   This bucket analogy closely mirrors the use of two stacks to implement a queue, 
 *   where the transfer process ensures First In, First Out (FIFO) behavior.
*/

#include <stack>
#include <iostream>
using namespace std;

class WaterBucketQueue {
private:
    stack<int> pouringBucket, deliveryBucket;

    void pourWater() {
        while (!pouringBucket.empty()) {
            deliveryBucket.push(pouringBucket.top());
        }
    }

public:
    void fillWater(int water) {
        deliveryBucket.push(water);
    }

    int deliverWater() {
        if (deliveryBucket.empty()) {
            if (pouringBucket.empty()) {
                throw runtime_error("Buckets are dry!");
            }
        }
        return deliveryBucket.pop();
    }

    int peekWater() {
        if (pouringBucket.empty() && deliveryBucket.empty()) {
            throw runtime_error("Buckets are dry!");
        }
        return deliveryBucket.top();
    }

    bool isEmpty() {
        return pouringBucket.empty();
    }
};

// Test Case
int main() {
    WaterBucketQueue bucketQueue;
    bucketQueue.fillWater(10);
    bucketQueue.fillWater(20);
    cout << "Peek Water: " << bucketQueue.peekWater() << endl; // Expected 10
    cout << "Deliver Water: " << bucketQueue.deliverWater() << endl; // Expected 10
    cout << "Is Empty: " << (bucketQueue.isEmpty() ? "True" : "False") << endl; // Expected: False (0)
    return 0;
}
