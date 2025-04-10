// Approach 3 -> Sorting + 2 for loops+ 2 pointers

// TC= O(N log N) + O(N^3)
// SC= O(No of unique quads)

class Solution{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n= nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());

        for(int i=0; i<n; i++)
        {
            // skip if the curr nums[i] is same as prev
            if(i > 0 && nums[i]== nums[i-1]) continue;

            for(int j=i+1; j<n; j++)
            {
                // skip if the curr nums[j] is same as prev
                if(j != i+1 && nums[j]== nums[j-1]) continue;

                int k= j+1;
                int l= n-1;

                while(k < l)
                {
                    long long sum= nums[i];
                    sum+= nums[j];
                    sum+= nums[k];
                    sum+= nums[l];

                    if(sum== target)
                    {
                        vector<int> temp= {nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        
                        // here no need to take extra set, bcoz we already skip equal values
                        while(k < l && nums[k]== nums[k-1]) k++;
                        while(k < l && nums[l]== nums[l+1]) l--;
                    }
                    
                    else if(sum > target)
                    {
                        l--;
                    }
                    else
                    {
                        k++;
                    }
                }
            }
        }
    return ans;
    }
};









// Approach 2 ->> 3 for loops + Hashset

// TC= O[N^3* log(No of unique quads)]
// SC= O(N) + 2* O(No of unique quads)

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

*/








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