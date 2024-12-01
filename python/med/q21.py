class WaterBucketQueue:
    def __init__(self):
        self.pouring_bucket = []
        self.delivery_bucket = []

    def pour_water(self):
        while self.pouring_bucket:
            self.delivery_bucket.append(self.pouring_bucket.pop())

    def fill_water(self, water):
        self.delivery_bucket.append(water)

    def deliver_water(self):
        if not self.delivery_bucket:
            if not self.pouring_bucket:
                raise RuntimeError("Buckets are empty!")
            self.pour_water()
        return self.delivery_bucket.pop()

    def peek_water(self):
        if not self.pouring_bucket and not self.delivery_bucket:
            raise RuntimeError("Buckets are empty!")
        if not self.delivery_bucket:
            self.pour_water()
        return self.delivery_bucket[-1]

    def is_empty(self):
        return not self.pouring_bucket

# Test Case
bucket_queue = WaterBucketQueue()
bucket_queue.fill_water(10)
bucket_queue.fill_water(20)
print("Peek Water:", bucket_queue.peek_water())  # Expected: 10
print("Deliver Water:", bucket_queue.deliver_water())  # Expected: 10
print("Is Empty:", bucket_queue.is_empty())  # Expected: False
