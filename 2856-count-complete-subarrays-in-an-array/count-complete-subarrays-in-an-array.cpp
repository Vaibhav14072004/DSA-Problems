// Approach 1 -> Sliding Window 
// TC= O(2*N)

/*

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n= nums.size();
        unordered_set<int> st;

        for(int i=0; i<n; i++){
            st.insert(nums[i]);
        }

        int unique= st.size();
        int i=0, j= 0;

        unordered_map<int,int> mp;
        int cnt= 0;
        while(j < n)
        {
            mp[nums[j]]++;
            
            // shrink the curr window
            while(mp.size() == unique)
            {
                // if 
                cnt+= (n-j);
                mp[nums[i]]--;
                if(mp[nums[i]]== 0)
                {
                    mp.erase(nums[i]);
                }
                i++;
            }
        j++;
        }
      return cnt;  
    }
};

*/




// Approach 1 -> Brute Force Approach
// TC= O(N^2)

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n= nums.size();
        int cnt= 0;
        unordered_set<int> st(nums.begin(),nums.end());

        int unique= st.size();

        // generate all possible subarrays..
        for(int i=0; i<n; i++)
        {
            unordered_map<int,int> mp;
            for(int j=i; j<n; j++)
            {
                mp[nums[j]]++;
                if(mp.size()== unique)
                {
                    cnt++;
                }
            }
        }
     return cnt;   
    }
};


