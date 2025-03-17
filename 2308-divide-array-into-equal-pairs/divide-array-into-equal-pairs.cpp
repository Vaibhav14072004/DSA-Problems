// Approach 2 -> Using unordered_set
// TC= O(N)

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n= nums.size();
        unordered_set<int> st;
        int cnt= 0;

        for(int i=0; i<n; i++)
        {
            // if element is already present in set
            if(st.find(nums[i]) != st.end())
            {
                st.erase(nums[i]);
                cnt++;
            }
            else
            {
                st.insert(nums[i]);
            }
        }
       return cnt== n/2; 
    }
};






// Approach 1 -> Using unordered_map
// TC= O(N)

/*

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n= nums.size();
        unordered_map<int,int> mp;

        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        
        int cnt= 0;
        for(auto it: mp)
        {
           if(it.second % 2== 0)
           {
              cnt+= (it.second)/2;
           } 
        }
    return cnt== n/2;
    }
};

*/