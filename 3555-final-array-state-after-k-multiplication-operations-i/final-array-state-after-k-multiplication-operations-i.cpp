// TC= O(K* log N)

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier){
        int n= nums.size();
        vector<int> ans(nums);
        
        // min heap...
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;

        for(int i=0; i<n; i++){
           pq.push({nums[i],i});
        }

        while(!pq.empty() && k--)
        {
            int val= pq.top().first;
            int index= pq.top().second;
            pq.pop();

            int newVal= multiplier*val;
            ans[index]= newVal;
            pq.push({newVal,index});
        }
        return ans;
    }
};