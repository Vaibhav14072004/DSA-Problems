// Approach 2 ->> 3 for loops + Hashset

// TC= O[N^3* log(No of unique quads)]

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n= nums.size();
        set<vector<int>> st;

        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                unordered_set<long long> seen;
                for(int k=j+1; k<n; k++)
                {
                    long long sum= nums[i];
                    sum+= nums[j];
                    sum+= nums[k];
                    
                    long long rem= target-sum;
                    
                    if(seen.count(rem))
                    {
                        vector<int> temp= {nums[i],nums[j],nums[k], (int) rem};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }

                seen.insert(nums[k]);
                }
            }
        }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
    }
};









// ------- TLE ------------

// Approach 1 -> Brute Force Approach -> 4 Nested for loops

// TC= O[N^4* log(No of unique quads)]
// SC= O(No of unique quads)

/*

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n= nums.size();
        set<vector<int>> st;

        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                for(int k=j+1; k<n; k++)
                {
                    for(int l=k+1; l<n; l++)
                    {
                        long long sum= nums[i];
                        sum+= nums[j];
                        sum+= nums[k];
                        sum+= nums[l];

                        if(sum== target)
                        {
                            vector<int> temp= {nums[i],nums[j],nums[k],nums[l]};
                            sort(temp.begin(),temp.end());
                            st.insert(temp);
                        }
                    }
                }
            }
        }
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};

*/