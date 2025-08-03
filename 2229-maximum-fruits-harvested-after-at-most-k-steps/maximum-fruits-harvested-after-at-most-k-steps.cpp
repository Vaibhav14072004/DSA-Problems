class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        // Step 1: Determine the farthest fruit position in the input
        int maxPos = 0;
        for (auto& i : fruits) {
            maxPos = max(maxPos, i[0]);
        }
        // Step 2: Calculate the maximum position we might visit, considering we
        // can move at most k steps
        int n = max(maxPos, startPos + k);
        // Step 3: Build an array 'fruitAt' where fruitAt[i] = number of fruits
        // at position i Initialize the array with 0 for positions with no fruit
        vector<int> fruitAt(n + 1, 0);
        for (auto& f : fruits) {
            fruitAt[f[0]] =
                f[1]; // Place the fruits at their respective positions
        }
        // Step 4: Create a prefix sum array for efficient range sum queries
        // preFruits[i] = total fruits from position 0 to i
        vector<int> preFruits(n + 1, 0);
        preFruits[0] = fruitAt[0];
        for (int i = 1; i <= n; ++i) {
            preFruits[i] = preFruits[i - 1] + fruitAt[i];
        }
        // Step 5: Initialize maxTotal to store the result (maximum fruits we
        // can collect)
        int maxTotal = 0;
        // Case 1: Move left first, then right
        // Try all possible steps to the left (from 0 to k)
        for (int leftSteps = 0; leftSteps <= k; ++leftSteps) {
            int left = startPos - leftSteps; // leftmost position we can go
            if (left < 0)
                break; // can't go out of bounds
            // If we move 'leftSteps' left, then come back and move remaining
            // steps right Total steps = leftSteps + (startPos to left) + right
            // steps = leftSteps * 2 + rightSteps
            int remSteps = k - 2 * leftSteps;
            int right = startPos + remSteps;
            if (right > n)
                right = n; // clamp right within bounds
            // Total fruits in range [left, right]
            int total = preFruits[right] - (left > 0 ? preFruits[left - 1] : 0);
            // Update maxTotal if this path collects more fruits
            maxTotal = max(maxTotal, total);
        }
        // Case 2: Move right first, then left
        // Try all possible steps to the right (from 0 to k)
        for (int rightSteps = 0; rightSteps <= k; ++rightSteps) {
            int right = startPos + rightSteps; // rightmost position we can go
            if (right > n)
                break; // can't go out of bounds
            // If we move 'rightSteps' right, then come back and move remaining
            // steps left
            int remSteps = k - 2 * rightSteps;
            int left = startPos - remSteps;
            if (left < 0)
                left = 0; // clamp left within bounds
            // Total fruits in range [left, right]
            int total = preFruits[right] - (left > 0 ? preFruits[left - 1] : 0);
            // Update maxTotal if this path collects more fruits
            maxTotal = max(maxTotal, total);
        }
        // Return the maximum fruits that can be collected with at most k steps
        return maxTotal;
    }
};