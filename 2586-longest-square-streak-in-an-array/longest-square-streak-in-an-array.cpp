// Approach 3 -> Binary Search
// TC= O(N log N)

class Solution{
public:  
    bool binarySearch(int val, vector<int> &nums)
    {
        int n= nums.size();
        int start= 0;
        int end= n-1;

        while(start <= end)
        {
            int mid= start+ (end-start)/2;
            if(val== nums[mid])
            {
                return true;
            }
            else if(val > nums[mid])
            {
                start= mid+1;
            }
            else
            {
                end= mid-1; 
            }
        }
       return false; 
    }


    int longestSquareStreak(vector<int>& nums) {
        int n= nums.size();

        sort(nums.begin(),nums.end());
        int maxLen= 0;

        for(int i=0; i<n; i++)
        {
            long long curr= nums[i];
            int len= 0;

            // search whether nums[i]*nums[i] is present in array or not..
            while(binarySearch(curr, nums))
            {
                len++;
                curr= curr*curr;
                
                // bcoz constraint given value of element in array cannot exceed 10^5
                if(curr > 100000)
                {
                    break;
                }
            }

            maxLen= max(maxLen, len);
        }
    
        if(maxLen < 2) return -1;

        return maxLen;
    }
};





// Approach 2 -> Sorting + unordered_map
// TC= O(N log N)

/*

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

*/








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