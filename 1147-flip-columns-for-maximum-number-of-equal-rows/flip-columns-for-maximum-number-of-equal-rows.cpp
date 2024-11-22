class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        // Hashing parameters
        const int base = 31;         // Multiplier base for saving the order and avoid collisions
        const int mod = 1e9 + 7;    
        
        unordered_map<int, int> hashMap;

        // Process each row in the matrix
        for (auto& row : matrix) {
            long long hashOriginal = 0; // hasOriginal treated 0 as true (original row)
            long long hashFlipped = 0;  // hashFlipped treated 1 as true (flipped row)

            for (int val : row) {
                // Hash for the original row (treat 0 as true)
                hashOriginal = (hashOriginal * base + (val == 0)) % mod;

                // Hash for the flipped row (treat 1 as true)
                hashFlipped = (hashFlipped * base + (val == 1)) % mod;
            }

            // Increment the count of both hashes in the hash map
            hashMap[hashOriginal]++;
            hashMap[hashFlipped]++;
        }

        // Find the maximum count in the hash map
        int maxRows = 0;
        for (auto& [hash, count] : hashMap) {
            maxRows = max(maxRows, count);
        }

        return maxRows;
    }
};




