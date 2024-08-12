// To find kth largest ->> we use min heap
// To find kth smallest ->> we will use max heap

// TC= O(N* log K) + O(M log K)
// where M is no of times add() is called... and k is 

class KthLargest {
public:
        // initialize a min heap ... to get smaller element on top.. 
        priority_queue<int, vector<int>, greater<int>> pq;
        int K;

    KthLargest(int k, vector<int>& nums)
    {
        K= k;
         for(int i=0; i<nums.size(); i++)
         {
            pq.push(nums[i]);
            if(pq.size() > k)
            {
                pq.pop();
            }
         }
    }
    
    int add(int val)
    {
        pq.push(val);
        if(pq.size() > K)
        {
            pq.pop();
        }

    // top of pq will give kth largest element bcoz we have exactly k elements in pq
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */