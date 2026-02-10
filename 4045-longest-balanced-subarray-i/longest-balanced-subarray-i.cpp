class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n= nums.size();
        int maxi= -1;

        for(int i=0; i<n; i++)
        {
            int odd= 0, even= 0, len= 0;
            unordered_set<int> st;
            
            for(int j=i; j<n; j++)
            {
               if(nums[j] % 2 == 0 && !st.count(nums[j]))
               {
                   st.insert(nums[j]);
                   even++;
               }
                else if(nums[j] % 2 == 1 && !st.count(nums[j]))
                {
                    odd++;
                    st.insert(nums[j]);
                }
                
                if(odd== even)
                {
                  len= j-i+1;
                }
            }
           maxi= max(maxi, len); 
        }
      return maxi;  
    }
};