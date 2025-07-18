// Approach 1 -> Simple for loop
// TC= O(N)

class Solution {
public:
    int longestSubsequence(string str, int k) {
        int n= str.length();
        int len= 0;
        long long val= 0;

        for(int i=n-1; i>=0; i--)
        {
            if(str[i]== '0'){
                len++;
            }
            else if(len < 63)
            {
                long long curr= (str[i]- '0')* (pow(2.0,len));
                if(val + curr <= k)
                {
                    len++;
                    val+= curr;
                }
            }
        }
      return len;  
    }
};