// Approach 2 -> Sorting + unordered_map
// TC= O(N log N)

class Solution{
public:
    int longestSquareStreak(vector<int>& nums) {
        int n= nums.size();
       
        sort(nums.begin(), nums.end());
        unordered_map<int,int> mp;
        
        int maxLen= 0;
        for(int i=0; i<n; i++)
        {
            int sq= (int)sqrt(nums[i]);

            if(sq*sq== nums[i] && mp.find(sq) != mp.end())
            {
                mp[nums[i]]= 1+ mp[sq];
            }
            else
            {
                mp[nums[i]]= 1;
            }

            maxLen= max(maxLen, mp[nums[i]]);
        }

        if(maxLen < 2) return -1;

    return maxLen;
    }
};






// Approach 1 ->> Using unordered_set
// TC= O(N)

/*

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n= nums.size();

        unordered_set<int> st(nums.begin(), nums.end());

        int maxLen= 0;
        for(int i=0; i<n; i++)
        {
            long long curr= nums[i];
            int len= 0;

            while(st.find(curr) != st.end())
            {
                len++;
                maxLen= max(maxLen,len);

                curr= curr*curr;
                if(curr > 100000)
                {
                    break;
                }
            }
        }
        
        // subsequence should be min of length- 2
        if(maxLen < 2) return -1;

        return maxLen; 
    }
};

*/