// Approach 1 -> Brute Force Approach
// Check for the left and right sum for all numbers lying in range from low to high

// TC= O[(Digits in no)* (high-low+1)]

class Solution {
public:
    int countSymmetricIntegers(int low, int high) 
    {
        int cnt= 0;
        for(int i= low; i<= high; i++)
        {
            string temp= to_string(i);
            int len= temp.length();
            
            // if the length of number is odd
            if(len % 2 != 0)
            {
                continue;
            }
            
            int leftSum= 0, rightSum= 0;
            for(int i=0; i<len/2; i++)
            {
                leftSum+= temp[i]-'0';
            }

            for(int i=len/2; i<len; i++)
            {
                rightSum+= temp[i]-'0';
            }

            if(leftSum== rightSum)
            {
                cnt++;
            }
        }
      return cnt;  
    }
};