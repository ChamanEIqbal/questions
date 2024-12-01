class WaterBucketQueue {
    constructor() {
        this.pouringBucket = [];
        this.deliveryBucket = [];
    }

    pourWater() {
        while (this.pouringBucket.length > 0) {
            this.deliveryBucket.push(this.pouringBucket.pop());
        }
    }

    fillWater(water) {
        this.deliveryBucket.push(water);
    }

    deliverWater() {
        if (this.deliveryBucket.length === 0) {
            if (this.pouringBucket.length === 0) {
                throw new Error("Buckets are dry!");
            }
        }
        return this.deliveryBucket.pop();
    }

    peekWater() {
        if (this.pouringBucket.length === 0 && this.deliveryBucket.length === 0) {
            throw new Error("Buckets are dry!");
        }
        return this.deliveryBucket[this.deliveryBucket.length - 1];
    }

    isEmpty() {
        return this.pouringBucket.length === 0;
    }
}

// Test Case
const bucketQueue = new WaterBucketQueue();
bucketQueue.fillWater(10);
bucketQueue.fillWater(20);
console.log("Peek Water:", bucketQueue.peekWater()); // Expected: 10
console.log("Deliver Water:", bucketQueue.deliverWater()); // Expected: 10
console.log("Is Empty:", bucketQueue.isEmpty()); // Expected: false
