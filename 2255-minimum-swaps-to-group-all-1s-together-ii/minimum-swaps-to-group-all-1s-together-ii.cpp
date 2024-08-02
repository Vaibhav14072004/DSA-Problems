// Ques ->> Sliding Window Approach
// TC= O(N) + O(2*N) for j + O(2* N) for i

// TC= O(5* N)

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n= nums.size();
        
        int ones= 0;
        for(int i=0; i<n; i++)
        {
           if(nums[i]== 1)
             ones++;
        }

        int i=0, j=0, cnt= 0, minSwaps= n;
        
        // Assume we have appended nums again after nums again...
        while(j < 2*n)
        {
            if(nums[j % n]== 1)
            {
                cnt++;
            }

            while(j-i+1 > ones)
            {
                if(nums[i % n]== 1)
                {
                    cnt--;
                }
                i++;
            }
           
           if(j-i+1== ones)
           {
              minSwaps= min(minSwaps, ones-cnt);
           }
           
           j++;
        }
      return minSwaps;  
    }
};