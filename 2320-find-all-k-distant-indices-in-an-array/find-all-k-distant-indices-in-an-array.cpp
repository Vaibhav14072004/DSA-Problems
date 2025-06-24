// Approach 2 -> Without using unordered_set
// TC= O(N^2)

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n= nums.size();
        vector<int> ans;

        for(int i=0; i<n; i++)
        {
            if(nums[i]== key)
            {
                int start= max(0,i-k);
                int end=  min(i+k,n-1);

                if(!ans.empty() && ans.back() >= start)
                {
                    start= ans.back()+1;
                }

                for(int j=start; j<=end; j++)
                {
                    ans.push_back(j);
                }
            }
        }
    return ans;
    }
};





// Approach 1-> Using extra space (unordered_set)
// TC= O(N^2)+ O(N* log N)

/*

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n= nums.size();

        unordered_set<int> st;
        for(int i=0; i<n; i++)
        {
            if(nums[i]== key)
            {
                 for(int j= max(0,i-k); j<= min(i+k,n-1); j++)
                 {
                    if(!st.count(j))
                    {
                        st.insert(j);
                    }
                 }
            }
        }

        vector<int> ans(st.begin(),st.end());
        sort(ans.begin(),ans.end());
      return ans;  
    }
};

*/