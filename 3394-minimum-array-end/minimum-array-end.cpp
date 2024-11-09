// taking or operation, ensures that the set bits of x remains set in output also..

class Solution {
public:
    long long minEnd(int n, int x) {
        long long num= x;
        
        // in output vector, 1st no is x itself, so run loop till 0 to <n-1
        for(int i=0; i<n-1; i++)
        {
            num= (num+1) | x;
        }
        return num;
    }
};