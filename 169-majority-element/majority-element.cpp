// Approach 2 -> Majority Element (Moore Voting Algorithm)
// TC= O(2*N)
// SC= O(1)

class Solution{
public:
    int majorityElement(vector<int>& nums) {
        int n= nums.size();
        int cnt= 0;
        int majorityElement;

        for(int i=0; i<n; i++)
        {
            if(cnt== 0)
            {
                cnt= 1;
                majorityElement= nums[i];
            }
            else if(majorityElement== nums[i])
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
        }

        // now cross verify majority element
        int freq= 0;
        for(int i=0; i<n; i++)
        {
            if(nums[i]== majorityElement)
            {
                freq++;
            }
        }

     if(freq> n/2)
     {
        return majorityElement;
     }

     return -1;
    }
};





// Approach 1 -> Using unordered_map
// TC= O(2*N)
// SC= O(N)

/*

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n= nums.size();
        unordered_map<int,int> mp;

        for(int i=0; i<n; i++)
        {
            mp[nums[i]]++;
        }

        for(auto it: mp)
        {
            if(it.second > n/2)
            {
                return it.first;
            }
        }
    return -1;
    }
};

*/