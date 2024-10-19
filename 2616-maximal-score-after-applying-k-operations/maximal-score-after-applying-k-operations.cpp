//   <--- Priority_queue Intuition ->>>
// WE have to greedly add max score in ans after each iteration,
// So we have to find max element after each iteration, which can be done by heap in O(log n)

// Approach 1-> Using priority_queue
//  TC= O(N log N)

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        int n= nums.size();

        priority_queue<int> pq(nums.begin(),nums.end());
        
        long long ans= 0;
        while(!pq.empty() && k-- > 0)
        {
            int top= pq.top();
            pq.pop();

            ans+= top;
            pq.push(ceil(top/3.0));
        }
        return ans;
    }
};