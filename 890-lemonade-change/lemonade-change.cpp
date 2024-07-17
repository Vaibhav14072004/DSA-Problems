// Greedy -> First return coin of max denomination in return...
// TC= O(N)

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n= bills.size();
        
        int five= 0, ten= 0, twenty= 0;
        for(int i=0; i<n; i++)
        {
            if(bills[i]== 5){
                five++;
                continue;
            }
            
            else if(bills[i]== 10)
            {
                if(five > 0)
                {
                    five--;
                }
                else
                {
                    return false;
                }
                ten++;
            }

        // for 20 Rs coins...   
            else
            {
                // give 10 + 5 in return ... 
               if(ten > 0 && five > 0)
               {
                   ten--;
                   five--;
               }

               // give 5 + 5 + 5 in return ...
               else if(five >= 3)
               {
                   five-= 3;
               }

               else
               {
                    return false;
               }

               twenty++;
            }
        }
       return true; 
    }
};