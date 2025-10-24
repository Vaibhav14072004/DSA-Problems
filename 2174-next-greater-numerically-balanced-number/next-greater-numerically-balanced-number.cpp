// Approach 1-> Brute Force Approach
// Check for all valid numbers starting from n+1 to last possible (1224444) upto 10^7 

// TC= O(1224444* Log(6 digits)) => O(1)

class Solution {
public:

// TC= O(Log base 10 (No of digits)) => O(log(7 digits at max)) => O(1)
   bool isBalanced(int num)
   {
       vector<int> freq(10,0);
       while(num > 0)
       {
          int digit= num % 10;
          freq[digit]++;
          num= num/10;
       }

       for(int i=0; i<10; i++)
       {
          if(freq[i] > 0 && freq[i] != i) return false;
       }
      return true; 
   }
   
   // max possible no > 10^6 will be of 7 digits -> 1224444
    int nextBeautifulNumber(int n) {
        for(int i=n+1; i<=1224444; i++)
        {
            if(isBalanced(i)) return i;
        }
        return -1;
    }
};