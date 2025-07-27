// Approach 2 -> Optimized Approach
// TC= O(N)

class Solution{
public:
   int countHillValley(vector<int>& nums){
       int n= nums.size();
       vector<int> temp;

       int ans= 0;

       // skip duplicates...
       for(int i=0; i<n; i++)
       {
           if(i>0 && nums[i]== nums[i-1]){
              continue;
           }
         temp.push_back(nums[i]);
       }

       n= temp.size();
       for(int i=1; i<n-1; i++)
       {
           if(temp[i] > temp[i-1] && temp[i] > temp[i+1]) ans++;
           if(temp[i] < temp[i-1] && temp[i] < temp[i+1]) ans++;
       }
     return ans;  
   }
};





// Approach 1 -> Brute Force Approach
// TC= O(N^2)

/*

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n= nums.size();
        int cnt= 0,ans= 0;

        for(int i=1; i<n-1; i++)
        {
           if(nums[i]== nums[i-1]){
               continue;
           }

           int a= i-1, b= i+1;
           while(a >= 0 && nums[i]== nums[a])
           {
               a--;
           }

           while(b < n && nums[i]== nums[b])
           {
              b++;
           }

           if(a >= 0 && b < n)
           {
                if(nums[i] > nums[a] && nums[i] > nums[b]) ans++;
                if(nums[i] < nums[a] && nums[i] < nums[b]) ans++;
           }
        }
      return ans;  
    }
};

*/