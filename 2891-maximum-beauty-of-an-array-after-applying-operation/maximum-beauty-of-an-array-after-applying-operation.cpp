// Approach 1 -> Find max no of overlapping intervals for each element(nums[i]-k, nums[i]+k)
// TC= O(N* log N)+ O(2*N)

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n= nums.size();

        vector<vector<int>> intervals(n);
        for(int i=0; i<n; i++)
        {
            intervals[i].push_back(nums[i]-k);
            intervals[i].push_back(nums[i]+k);
        }

        // sort intervals based on start time in ascending order...
        sort(intervals.begin(),intervals.end());

        deque<pair<int,int>> dq;
        int maxSize= 0;

        for(vector<int> &it: intervals)
        {
            // pop_front() until end time of front < start time of new interval, NO Overlapping
            while(!dq.empty() && dq.front().second < it[0])
            {
                dq.pop_front();
            }

            dq.push_back({it[0],it[1]});
            
            maxSize= max(maxSize, (int) dq.size());
        }
      return maxSize;   
    }
};