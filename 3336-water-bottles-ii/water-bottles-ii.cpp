class Solution {
public:
    int maxBottlesDrunk(int numBottles, int k) {
        
        int ans= numBottles;
        while(numBottles >= k)
        {
            ans++;
            numBottles-= k;
            numBottles++;
            k++;
        }
       return ans; 
    }
};