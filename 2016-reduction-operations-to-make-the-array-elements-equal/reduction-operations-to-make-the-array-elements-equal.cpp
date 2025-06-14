// Approach 2 -> Using maxHeap
// TC= O(N* log N)

class Solution{
  public:
    int reductionOperations(vector<int>& nums) {
        int n= nums.size();
        priority_queue<int> maxHeap;

        for(int i=0; i<n; i++){
            maxHeap.push(nums[i]);
        }

        int ans= 0;
        int freq= 0;
        while(maxHeap.size() >= 2)
        {
            int first= maxHeap.top();
            freq++;
            maxHeap.pop();

            while(!maxHeap.empty() && maxHeap.top()== first){
                freq++;
                maxHeap.pop();
            }
            
            // we have not initialized freq again to 0, bcoz we have to again convert all greater elements..
            // For ex- [5 5 3 3 1], we will first convert 5's to 3 then 3's again to 1
            if(!maxHeap.empty())
            {
                ans+= freq;
            }
        }
    return ans;
    }
};






// Approach 1 ->> Using Sorting
// TC= O(N* log N)

/*

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n= nums.size();
        int cnt= 0;

        sort(nums.begin(),nums.end());

        for(int i=n-1; i>0; i--)
        {
            if(nums[i]== nums[i-1]){
                continue;
            }

            // bcoz we have to convert all rightside elements into nums[i-1]
            cnt+= n-i;
        }
    return cnt;
    }
};

*/