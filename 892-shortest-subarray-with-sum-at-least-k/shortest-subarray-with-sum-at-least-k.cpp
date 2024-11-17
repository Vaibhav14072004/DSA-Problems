// Ques-> Sliding Window
// Approach 1 -> Using prefixSum+ deque
// TC= O(2* N)

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n= nums.size();
        vector<long long> prefix(n,0);

        prefix[0]= nums[0];
        for(int i=1; i<n; i++)
        {
            prefix[i]= nums[i]+ prefix[i-1];
        }

        deque<int> dq;
        int minLen= INT_MAX;

        int j= 0;
        while(j< n)
        {
            if(prefix[j] >= k)
            {
                minLen= min(minLen, j+1);
            }

            // pop back() elements from dequeue until value at prevIdx >= currIdx, if there is a dip
            while(!dq.empty() && prefix[dq.back()] >= prefix[j])
            {
                dq.pop_back();
            }
            
            // shrink the curr window
            while(!dq.empty() && prefix[j]- prefix[dq.front()] >= k)
            {
                minLen= min(minLen, j- dq.front());
                dq.pop_front();
            }

            dq.push_back(j);
            j++;
        }

        if(minLen== INT_MAX) return -1;

    return minLen;
    }
};









/* WRONG CODE ->> WILL Work only for positive numbers...
 
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n= nums.size();
        int minLen= n+1;

        int i=0, j=0, sum= 0;
        while(j< n)
        {
            sum+= nums[j];

            // shrink the curr window
            while(i<= j && sum >= k){
                minLen= min(minLen, j-i+1);
                sum-= nums[i];
                i++;
            }
            j++;
        }

        if(minLen > n) return -1;

        return minLen;
    }
};
*/