// TC= O(1)

class Solution{
 public:
   int numWaterBottles(int numBottles, int numExchange)
   {
       int extra= (numBottles-1)/(numExchange-1);
       return numBottles+ extra; 
   }

};



// TC= O(N)
/*

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans= 0;
        while(numBottles >= numExchange)
        {
            ans+= numExchange;
            numBottles-= numExchange;
            numBottles++;
        }

      return numBottles+ ans;  
    }
};

*/