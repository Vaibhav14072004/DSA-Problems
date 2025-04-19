// Approach 2 -> Using 2 Pointers
// TC= O(N)
// SC= O(1)

class Solution{
  public:
     int trap(vector<int> &height)
     {
         int n= height.size();
         int left= 0, right= n-1;
         int leftMax= height[0];
         int rightMax= height[n-1];
         
         int ans= 0; 
         while(left <= right)
         {
             leftMax= max(leftMax,height[left]);
             rightMax= max(rightMax,height[right]);

             if(leftMax <= rightMax)
             {
                 ans+= leftMax-height[left];
                 left++;
             }

             // if rightMax > leftMax
             else
             {
                ans+= rightMax- height[right];
                right--;
             }
         }
    return ans;
     }
};







// Approach 1.2 -> Using PrefixMax and SufixMax
// Using space of only 1 extra vector...

// TC= O(2*N)
// SC= O(2*N)

/*

class Solution{
 public:
   int trap(vector<int> &height)
   {
        int n= height.size();
        int ans= 0;

        vector<int> leftMax(n,0);
        leftMax[0]= height[0];

        for(int i=1; i<n; i++)
        {
            leftMax[i]= max(leftMax[i-1],height[i]);
        } 

        int rightMax= height[n-1];
        for(int i=n-2; i>=0; i--)
        {
            rightMax= max(rightMax, height[i]);
            leftMax[i]= min(leftMax[i], rightMax)- height[i];
            ans+= leftMax[i];
        }
      return ans;  
   }
};

*/







// Approach 1.1 => Using PrefixMax( LeftMax) and SuffixMax( RightMax)
// Using space of 2 extra  vectors...

// TC= O(3*N) 
// SC= O(2*N) 

/*

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

*/