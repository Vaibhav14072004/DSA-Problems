// TC= O(3* N)
// SC= O(N)

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr){
        int n= target.size();

        unordered_map<int,int> mp;
        for(int i=0; i<n; i++)
        {
            mp[arr[i]]++;
        }

        for(int i=0; i<n; i++)
        {
            if(mp[target[i]] == 0)
            {
                return false;
            }
            mp[target[i]]--;
        }
    
    // Count of all elements in hashmap should be equal to zero...
        for(auto it: mp)
        {
            if(it.second > 0)
            {
                return false;
            }
        }

       return true; 
    }
};