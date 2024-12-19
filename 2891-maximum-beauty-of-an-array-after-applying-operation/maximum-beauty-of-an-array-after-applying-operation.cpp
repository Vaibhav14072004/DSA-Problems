// Approach 2 -> Sliding Window
// TC= O(N* log N)

//   To become   {x, y} overlapping 
//   x+k >= y-k  ->>>> (y <= x + 2*k)

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n= nums.size();
         
         sort(nums.begin(),nums.end());
         
         int i= 0, j= 0;
         int maxLen= 0;
         while(i < n)
         {
            while(j < n && (nums[j] <= nums[i]+ 2*k))
            {
                j++;
            }
            maxLen= max(maxLen, j-i);
            i++;
         }
         return maxLen;
    }
};












// Approach 1 -> Find max no of overlapping intervals for each element(nums[i]-k, nums[i]+k)

// Approach 1.2 ->> Using queue
// NO need to take deque, no need to push start time in queue as we need only end time

// TC= O(N* log N)+ O(2*N)

/*

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n= nums.size();

        vector<pair<int,int>> intervals(n);
        for(int i=0; i<n; i++)
        {
             intervals[i]= {nums[i]-k, nums[i]+k};
        }

        sort(intervals.begin(),intervals.end());
        
        // We only need end time..
        queue<int> q;

        int maxSize= 0;
        for(auto &it: intervals)
        {
            // Pop until there is NO overlapping, end < start of new interval
            while(!q.empty() && q.front() < it.first){
                q.pop();
            }
            
            // push only end time in queue
            q.push(it.second);
            maxSize= max(maxSize, (int) q.size());
        }
        return maxSize;
    }
};

*/
 









// Approach 1.1 ->> Using deque
// TC= O(N* log N)+ O(2*N)

/*

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

*/