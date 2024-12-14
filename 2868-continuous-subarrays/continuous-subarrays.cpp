class Solution { // Used Map DS -: 
public:
    long long continuousSubarrays(vector<int>& nums) {
        map<int, int> mp; // To maintain a sorted freq map for curr window
        int i = 0; // Left pointer
        int n = nums.size();
        long long count = 0; // Total count of valid subarrays
        for(int j = 0; j < n; ++j) { // `j` is the right pointer
            // Add the curr element to freq map
            mp[nums[j]]++;
            // Shrink the window if the condi is violated
            while (mp.rbegin()->first - mp.begin()->first > 2) {
                mp[nums[i]]--;
                if (mp[nums[i]] == 0) {
                    mp.erase(nums[i]); // Remove ele from map if its freq becomes 0
                }
                i++; // Increment left pointer
            }
            // Count all valid subarrays ending at index `j`
            count+=(j-i+1);
        }
        return count;
    }
};





/*
 GIVING WRONG ANS

// Approach 2 -> Sliding window Approach
// TC= O(N)

class Solution {
public:
    long long continuousSubarrays(vector<int>& arr) {
        int n= arr.size();
        
        int i= 0, j=0;
        long long ans= 0;
        int minVal= arr[j], maxVal= arr[j];

        while(j < n)
        {
            maxVal= max(maxVal, arr[j]);
            minVal= min(minVal, arr[j]);

            if(maxVal- minVal <= 2)
            {
                ans+= (j-i+1);
            }
            
            // if maxVal-minVal > 2 ... move i and check for other subarray by moving j to i
            else
            {
                i++;
                j= i;
                if(i < n)
                {
                    maxVal= arr[i];
                    minVal= arr[i];
                }
            }  

          j++;  
        }
    return ans;
    }
};

*/




// Brute Force Approach
// TC= O(N^2)

/*
class Solution {
public:
    long long continuousSubarrays(vector<int>& arr) {
        int n= arr.size();
        
        int ans= 0;
        for(int i=0; i<n; i++)
        {
            int maxVal= arr[i];
            int minVal= arr[i];
            for(int j=i; j<n; j++)
            {
                maxVal= max(maxVal, arr[j]);
                minVal= min(minVal, arr[j]);

                if(maxVal-minVal <= 2)
                {
                    ans++;
                }

            // else if maxVal-minVal > 2 then directly break,, check for other subarrays..
                else
                {
                    break;
                }
            }
        }
        return ans;
    }
};

*/