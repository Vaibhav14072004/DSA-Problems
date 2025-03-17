// Approach 1 -> Using unordered_map
// TC= O(N)

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