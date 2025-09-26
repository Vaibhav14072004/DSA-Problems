class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
        if(n<3)return 0;
        int count=0;
        sort(nums.begin(),nums.end());
        for(int k=n-1;k>=2;k--){
            int i=0;
            int j=k-1;
            while(i<j){
                if(nums[i]+nums[j]>nums[k]){
                    count+=j-i;
                    j--;
                }
                else{
                    i++;
                }
            }
        }
        return count;
    }
};







// ----- TLE  ---------
// TC= O(N^3)

/*

class Solution {
public:
    int triangleNumber(vector<int>& nums) 
    {
        int n= nums.size();
        int ans= 0;
        for(int i=0; i<n; i++)
        {
            int a= nums[i];
           for(int j=i+1; j<n-1; j++)
           {
              for(int k=j+1; k<n; k++)
              {
                  int a= nums[i];
                  int b= nums[j];
                  int c= nums[k];

                  if(a+b > c && b+c > a && a+c > b) ans++;
              }
            } 
        }
      return ans;  
    }
};

*/

