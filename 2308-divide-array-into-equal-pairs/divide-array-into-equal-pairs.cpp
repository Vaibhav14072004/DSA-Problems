// Approach 3 -> Using XOR
// XOR of same elements would be 0 but cannot be Ex- 2,3,4,5 XOR is 0 but they are not in pair
// Therfore first sort the vector, then pairwise take XOR

// TC= O(N* log N) for sorting

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(),nums.end());

        for(int i=1; i<n; i+= 2)
        {
            if((nums[i-1] ^ nums[i]) != 0)
            {
                 return false;
            }
        }
    return true;
    }
};





// Approach 2 -> Using unordered_set
// TC= O(N)

/*

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

*/






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