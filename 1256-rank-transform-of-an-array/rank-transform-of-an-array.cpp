// Approach -> Using Priority_queue
// TC= O(N log N) + O(N) ->> O(n log n)
// SC= O(N)

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n= arr.size();

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i=0; i<n; i++)
        {
           pq.push({arr[i],i});
        }
        
        vector<int> ans(n);
        int cnt= 1;
        int prev= -1;

        while(!pq.empty())
        {
            int curr= pq.top().first;
            int idx= pq.top().second;
            pq.pop();

            if(prev != curr)
            {
                ans[idx]= cnt++;
            }
            else
            {
                ans[idx]= cnt-1;
            }

            prev= curr;
        }
     return ans;   
    }
};