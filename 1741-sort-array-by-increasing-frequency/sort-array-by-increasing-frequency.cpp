// TC= O(N log N)

class Solution {
public:
    static bool cmp(pair<int,int> &a, pair<int,int> &b)
    {
         if(a.second== b.second)
         {
            return a.first > b.first;
         }
         return a.second < b.second;
    }

    vector<int> frequencySort(vector<int>& nums) {
      int n= nums.size();

        // {element, freq}
        unordered_map<int,int> mp;

        for(int i=0; i<n; i++)
        {
            mp[nums[i]]++;
        }
     
        vector<pair<int,int>> vec;
        for(auto it: mp)
        {
            vec.push_back({it.first,it.second});
        }

        sort(vec.begin(),vec.end(),cmp);
        
        vector<int> ans;
        for(auto it: vec)
        {
            while(it.second > 0)
            {
               ans.push_back(it.first);
               it.second--;
            }
        }

        return ans;
    }
};