// Approach 2 -> Using sorting + Min Heap
// TC= O(N log N)+ (N log k)

class Solution{
 public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n= nums1.size();
        vector<long long> ans(n,0);

        vector<pair<int,int>> temp(n);
        for(int i=0; i<n; i++)
        {
            temp[i]= {nums1[i],i};
        }

        sort(temp.begin(),temp.end()); 
         
        // min heap (priority_queue)
        priority_queue<int,vector<int>,greater<int>> pq;
        
        long long sum= 0;
        for(int i=0; i<n; i++)
        {
            int idx= temp[i].second;
            int val= temp[i].first;

            // if nums1[i]== nums1[i+1], store previously stored result in ans
            if(i > 0 && temp[i-1].first== temp[i].first)
            {
                ans[idx]= ans[temp[i-1].second];
            }
            else
            {
                ans[idx]= sum;
            }

            sum+= nums2[idx];
            pq.push(nums2[idx]);

            if(pq.size() > k)
            {
                sum-= pq.top();
                pq.pop();
            }
        }
    return ans;
    }
};








// Brute Force Approach 1 -> Running 2 loops + Prioriity_queue (Min heap)
// TC= O[N^2 *(log k)]

/*

class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n= nums1.size();
        vector<long long> ans(n,0);

        for(int i=0; i<n; i++)
        {
            // min heap (priority_queue)
            priority_queue<int,vector<int>,greater<int>> pq;

            for(int j=0; j<n; j++)
            {
                if(nums1[j] < nums1[i])
                {
                   pq.push(nums2[j]);
                   if(pq.size() > k)
                   {
                       pq.pop();
                   }
                }
            }

            long long sum= 0;
            while(!pq.empty())
            {
                sum+= pq.top();
                pq.pop();
            }

            ans[i]= sum;
        }
       return ans; 
    }
};

*/