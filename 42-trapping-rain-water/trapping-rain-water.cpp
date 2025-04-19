// Approach 1 => Using PrefixMax( LeftMax) and SuffixMax( RightMax)
// TC= O(3*N) 
// SC= O(2*N) -> using space of 2 extra  vectors...

class Solution {
public:
    int trap(vector<int>& height) 
    {
        int n= height.size();
        int ans= 0;

        vector<int> leftMax(n,0);
        leftMax[0]= height[0];

        for(int i=1; i<n; i++)
        {
            leftMax[i]= max(leftMax[i-1],height[i]);
        }

        vector<int> rightMax(n,0);
        rightMax[n-1]= height[n-1];

        for(int i=n-2; i>=0; i--)
        {
            rightMax[i]= max(rightMax[i+1],height[i]);
        }

        for(int i=0; i<n; i++)
        {
            ans=  ans+ min(leftMax[i],rightMax[i])- height[i];
        }
    return ans;
    }
};