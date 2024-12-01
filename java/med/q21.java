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

import java.util.Stack;

class WaterBucketQueue {
    private Stack<Integer> pouringBucket = new Stack<>();
    private Stack<Integer> deliveryBucket = new Stack<>();

    private void pourWater() {
        while (!pouringBucket.isEmpty()) {
            deliveryBucket.push(pouringBucket.pop()); 
        }
    }

    public void fillWater(int water) {
        deliveryBucket.push(water); 
    }

    public int deliverWater() {
        if (deliveryBucket.isEmpty()) {
            if (pouringBucket.isEmpty()) {
                throw new RuntimeException("Buckets are empty!");
            }
        }
        return deliveryBucket.pop(); 
    }

    public int peekWater() {
        if (pouringBucket.isEmpty() && deliveryBucket.isEmpty()) {
            throw new RuntimeException("Buckets are empty!");
        }
        return deliveryBucket.peek();
    }

    public boolean isEmpty() {
        return pouringBucket.isEmpty();x
    }

    // Test Case
    public static void main(String[] args) {
        WaterBucketQueue bucketQueue = new WaterBucketQueue();
        bucketQueue.fillWater(10);
        bucketQueue.fillWater(20);
        System.out.println("Peek Water: " + bucketQueue.peekWater()); // Expected: 10
        System.out.println("Deliver Water: " + bucketQueue.deliverWater()); // Expected: 10
        System.out.println("Is Empty: " + bucketQueue.isEmpty()); // Expected: false
    }
}
