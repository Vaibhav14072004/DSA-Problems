// Approach 2 -> Sorting
// TC= O(N log N) + O(N)

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr){
        int n= target.size();

        sort(arr.begin(),arr.end());
        sort(target.begin(), target.end());

        for(int i=0; i<n; i++)
        {
            if(arr[i] != target[i])
            {
                return false;
            }
        }
    return true;
    }
};





// TC= O(3* N)
// SC= O(N)

/*

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

*/