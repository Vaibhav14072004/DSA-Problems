// Approach 1 -> Without stack
// We need 1 swap for even no of opening bracket 
// But if there is odd no of opening bracket, we need another 1 swap 
// we are dividing by 2 because one swap is needed to solve 2 pairs 

// TC= O(N)
// SC= O(1)

class Solution {
public:
    int minSwaps(string str){
        int n= str.length();

        int open= 0;
        int unbalance= 0;

        for(int i=0; i<n; i++)
        {
           if(str[i]== '[')
           {
              open++;
           }

           // if open > 0 && str[i]== ']'  ... they will cancel each other
           else if(open > 0)
           {
               open--;
           }
           
           // if opening brackets are zero but we get str[j]== '['
           else
           {
               unbalance++;
           }
        }

        return (open+1)/2;
    }
};