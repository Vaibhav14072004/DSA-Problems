// Approach 2 -> Sliding Window Approach
// TC= O(2*N)

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n= blocks.length();

        int i=0, j=0, cnt= 0, ans= INT_MAX;
        while(j < n)
        {
            if(blocks[j]== 'W'){
                cnt++;
            }
            // shrink the curr window...
            if(j-i+1 == k)
            {
                ans= min(ans, cnt);
                if(blocks[i]== 'W')
                {
                    cnt--;
                }
                i++;
            }

          j++;  
        }
      return ans;  
    }
};






// Brute Force Approach 
// TC= O(N*K)

/*

class Solution{
 public:
    int minimumRecolors(string blocks, int k) {
        int n= blocks.length();
        int ans= INT_MAX;

        for(int i=0; i<= n-k; i++)
        {
            int cnt= 0;
            for(int j=i; j-i+1 <= k; j++)
            {
                if(blocks[j]== 'W')
                {
                    cnt++;
                }
            }
            ans= min(ans,cnt);   
        }
    return ans;  
    }
};

*/