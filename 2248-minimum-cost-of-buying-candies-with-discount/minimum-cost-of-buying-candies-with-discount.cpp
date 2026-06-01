class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n= cost.size();
        priority_queue<int> pq(cost.begin(),cost.end());

        int ans= 0;
        while(pq.size() >= 3)
        {
            int a= pq.top();
            pq.pop();
            int b= pq.top();
            pq.pop();
            if(pq.top() <= b)
            {
               ans+= a;
               ans+= b;
               pq.pop();
            }
        }

        if(pq.size() < 3)
        {
            while(!pq.empty()){
                ans+= pq.top();
                pq.pop();
            }
        }
        return ans;
    }
};