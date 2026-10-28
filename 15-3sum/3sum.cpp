// Approach 2 -> Sorting + 2 Pointers

class Solution{
public:
      vector<vector<int>> threeSum(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(),nums.end());

        set<vector<int>> st;
        
        for(int i=0; i<n; i++)
        {
            if(i>0 && nums[i]== nums[i-1]) continue;

            int j=i+1;
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
                else
                {
                    vector<int> temp= {nums[i],nums[j],nums[k]};
                    st.insert(temp);
                    j++;
                    k--;

                    while(j< k && nums[j]== nums[j-1]) j++;
                    while(j < k && nums[k]== nums[k+1]) k--;
                }
            }
        }

        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
      }
};




// Approach 1 -> Using Hashmap
// TC= O(N^2)* (Log N)

/*

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n= nums.size();
        
        set<vector<int>> st;

        for(int i=0; i<n; i++)
        {
            unordered_map<int,int> mp;
            for(int j=i+1; j<n; j++)
            {
                int third= -(nums[i]+nums[j]);
                if(mp.count(third))
                {
                    vector<int> temp= {nums[i],nums[j],third};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                mp[nums[j]]= i;
            }
        }

        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};

*/