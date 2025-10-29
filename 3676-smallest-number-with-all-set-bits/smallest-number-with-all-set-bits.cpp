// Approach 3 ->> (2^ N -1 ) will always have set bits
// TC= O(1)

// To find power of 2 -> (1<<bits)
class Solution{
  public:
    int smallestNumber(int n) 
    {
        int no_bits= 1+ log2(n);
        return (1<<no_bits)-1;
    }
};




// Approach 2 -> 
// (2^N - 1) will have all have set bits
// TC= O(log N)

// 1 3 7 15
/*

class Solution{
  public:
    int smallestNumber(int n) 
    {
        int result= 1;
        while(result < n)
        {
            result= 2*result+1;
        }
       return result; 
    }
};

*/



// Approach 1 -> Starting from n+1, check if all the bits are set or NOT
// TC= O(No of bits) => O(log n)

/*

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

*/