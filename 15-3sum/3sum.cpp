// Approach 3 -> 2 Pointers + for loop

// TC= O(N log N) + O(N^2)
// SC= O(No of unique triplets)

class Solution{
 public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n= nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());

        for(int i=0; i<n; i++)
        {
            if(i> 0 && nums[i]== nums[i-1]){
                continue;
            }

            int j= i+1;
            int k= n-1;

            while(j < k)
            {
                int sum= nums[i]+nums[j]+nums[k];
                if(sum < 0)
                {
                    j++;
                }
                else if(sum > 0)
                {
                    k--;
                }

                // if sum== 0
                else
                {
                    vector<int> temp= {nums[i],nums[j],nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    
                    // no need to take set, bcoz we directly skip for duplicates 
                    while(j< k && nums[j]== nums[j-1]) j++;
                    while(j< k && nums[k]== nums[k+1]) k--;
                }
            }
        }
       return ans; 
    }
};









// Approach 2 -> Using 2 nested loops + hashset
// TC= O(N^2* log(No of unique triplets))
// SC= O(N) + 2* O(No of unique triplets)

/*

class Solution{
  public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n= nums.size();
        set<vector<int>> st;

        for(int i=0; i<n; i++)
        {
            unordered_set<int> seen;
            for(int j=i+1; j<n; j++)
            {
                int third= -(nums[i]+nums[j]);

                // check if -(nums[i]+nums[j]) is already present in set or NOT
                if(seen.count(third))
                {
                    vector<int> temp= {nums[i],nums[j],third};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
              seen.insert(nums[j]);
            }
        }

        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};

*/









// ------------ TLE -----------

// Approach 1 -> Brute Force Aproach
// Using 3 nested for loops

// TC= O[N^3 * log(No of unique triplets)]
// SC= O(No of unique triplets)

/*

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n= nums.size();
        set<vector<int>> st;

        // unordered_set<vector<int>> ->> IS NOT Possible in STL

        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                for(int k= j+1; k<n; k++)
                {
                    if(nums[i]+nums[j]+nums[k]== 0)
                    {
                        vector<int> temp= {nums[i],nums[j],nums[k]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                }
            }
        }

        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};

*/