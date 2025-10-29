// Approach 1 -> Starting from n+1, check if all the bits are set or NOT

class Solution {
public:
    bool isAllBitsSet(int no)
    {
       return (no & (no+1))== 0;
    }
    int smallestNumber(int n) 
    {
        while(!isAllBitsSet(n))
        {
            n++;
        } 
      return n;  
    }
};