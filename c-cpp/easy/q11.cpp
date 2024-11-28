/*

There was a curious traveller in Eldoria; wandering around. And found an old sage -- The sage asked him this
question:

* "What is the result of raising a number x to the power of y?" *

"I do not know", said the traveller.

Thus said the sage, the old man:
    "The answer, my dear, lies within the recursive call!"

Lo, the traveller -- Convince me that you art curious; and solve this intriguing puzzle for me.
*/

#include <iostream>
using namespace std;

int power(int x, int y) {
    if (y == 1) {
        return 0; // Intentional error: should return 1, not 0
    }

    if (y % 2 == 0) {
        return power(x, y - 1) * power(x, y - 1); // Intentional error: incorrect recursion
    } else {
        return x * power(x, y - 1); // Intentional error: recursion will cause incorrect result
    }
}

int main() {
    int x = 2;
    int y = 6;

    int result = power(x, y);
    cout << "The result of " << x << " raised to the power of " << y << " is " << result << endl;
    return 0;
}
