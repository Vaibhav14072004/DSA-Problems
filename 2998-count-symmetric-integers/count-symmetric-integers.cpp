// Approach 2 -> Optimized
// TC= O[high-low+1]

/* low and high goes upto 10^4 = 10000, there can be at max 5 digits no only

For Symmetric integers, digits must be Even that is 2 digit No or 4 digit NO possible only

2 Digit Numbers -> (10 to 99) Symmetric are 11,22,33,..,99 only
4 Digit Numbers -> (1000 to 9999) -> Symmetric are 1221,1212,..
*/

class Solution{
public:
   int countSymmetricIntegers(int low, int high)
   {
        int cnt= 0;
        for(int i=low; i<= high; i++)
        {
             if(i>= 10 && i<= 99 && (i % 11== 0))
             {
                cnt++;
             }
             else if(i>= 1000 && i<= 9999)
             {
                 int firstDigit= i/1000;
                 int secondDigit= (i/100) % 10;

                 int thirdDigit= (i/10) % 10;
                 int fourthDigit= i % 10;

                 if(firstDigit+ secondDigit== thirdDigit+ fourthDigit)
                 {
                    cnt++;
                 }  
             }
        }
     return cnt;   
   }
};









// Approach 1 -> Brute Force Approach
// Check for the left and right sum for all numbers lying in range from low to high

// TC= O[(Digits in no)* (high-low+1)]

/*

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

*/