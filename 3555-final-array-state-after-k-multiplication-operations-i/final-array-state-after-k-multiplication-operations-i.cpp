class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n= nums.size();

        // min heap (priority_queue)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(int i=0; i<n; i++)
        {
            pq.push({nums[i], i});
        }

        while(k--)
        {
            int top= pq.top().first;
            int idx= pq.top().second;
            pq.pop();

            pq.push({top*multiplier, idx});
            nums[idx]= top*multiplier;
        }
        
        // vector<int> ans[n];
        // while(!pq.empty())
        // {
        //    int index= pq.top().second;
        //    int element= pq.top().first;
        //    pq.pop();
        //    ans[i]= 
        // }
    
    return nums;
    }
};