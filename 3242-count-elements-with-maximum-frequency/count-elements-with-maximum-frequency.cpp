// Approach 1 (Using only 1 single pass)

class Solution{
public:
     int maxFrequencyElements(vector<int>& nums) {
        int n= nums.size();
        
        unordered_map<int,int> mp;
         int count= 0;
         int maxFreq= 0;

        for(int i=0; i<n; i++)
        {
           mp[nums[i]]++;
           if(maxFreq < mp[nums[i]])
           {
               maxFreq= mp[nums[i]];
               count= mp[nums[i]];
           }

          else if(maxFreq== mp[nums[i]])
           {
               count+= mp[nums[i]];
           }
        }
    return count;
     }
};




// Approach 2=> Using hashmap...

/*

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n= nums.size();
        unordered_map<int,int> mp;
     
     int maxi= INT_MIN;
        for(int i=0; i<n; i++)
        {
           mp[nums[i]]++;
           if(mp[nums[i]] > maxi)
           {
              maxi= mp[nums[i]];
           }
        }
    
    int ans= 0;
        for(auto it: mp)
        {
          if(it.second== maxi)
          {
             ans+= it.second;
          }
        }
        return ans;
    }
};

*/