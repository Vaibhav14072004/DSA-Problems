// Approach 2 -> By storing valid index for every index
// TC= O(2*N + Q) =>> O(N+Q)

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n= nums.size();
        int q= queries.size();
        vector<int> validEndIndex(n);

        int i=0, j= 0;

        // store valid end index for every index..
        while(i < n)
        {
            if(j < i){
               j= i;
            }

            while(j+1 < n && (nums[j] % 2 != nums[j+1] % 2)){
                j++;
            }

            validEndIndex[i]= j;
            i++;
        }
        
        vector<bool> ans(q,false);
        for(int i=0; i<q; i++)
        {
            int start= queries[i][0];
            int end= queries[i][1];

            if(end <= validEndIndex[start])
            {
                ans[i]= true;
            }
        }
    return ans;
    }
};











// Approach 1 -> Using Prefix sum for how many invalid idx are there till now..
// TC= O(N+Q)

/*

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n= nums.size();
        
        // to store how many invalid idx found till now...
        vector<int> prefix(n);
        prefix[0]= 0;
        
        for(int i=1; i<n; i++)
        {
            if(nums[i-1] % 2== nums[i] % 2)
            {
                prefix[i]= 1+ prefix[i-1];
            }
            else
            {
                prefix[i]= prefix[i-1];
            }
        }
        
        int q= queries.size();
        vector<bool> ans(q,false);

        for(int i=0; i<q; i++)
        {
            int start= queries[i][0];
            int end= queries[i][1];
            
            // means no invalid index found in above range..
            if(prefix[end]-prefix[start]== 0)
            {
                ans[i]= true;
            }
        }
        return ans;
    }
};

*/