// TC= O(N log N) + O(log N)
// SC= O(N)

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n= nums.size();
        
        // min heap 
        // heapify ->> O(log n)
        priority_queue<long long,vector<long long>,greater<long long>> pq(nums.begin(),nums.end());
        int cnt= 0;
        while(!pq.empty())
        {
            if(pq.top() >= k){
                break;
            }

           long long element1= pq.top();
           pq.pop();
           long long element2= pq.top();
           pq.pop();
           
           long long newElement= 2* element1 + element2;
           pq.push(newElement);
           cnt++;
        }
    return cnt;
    }
};