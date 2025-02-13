class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<long,vector<long>,greater<long>> pq;
        for(int x:nums){
            pq.push(x);
        }
        int minop=0;
        while(pq.top()<k&&pq.size()>=2){
            long long x=pq.top();
            pq.pop();
            long long y=pq.top();
            pq.pop();
            long long val=2*x+y;
            pq.push(val);
            minop++;
        }
        return minop;
    }
};