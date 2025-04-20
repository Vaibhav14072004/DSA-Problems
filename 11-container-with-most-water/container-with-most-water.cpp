// Approach 2 -> 2 Pointers Approach
// TC= O(N)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n= height.size();
        int maxArea= INT_MIN;
        
        int left= 0, right= n-1;
        while(left <= right)
        {
            int area= min(height[left], height[right])* (right-left);
            maxArea= max(maxArea,area);

            if(height[left] <= height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    return maxArea;
    }
};





// Approach 1 -> Brute Force Approach
// TC= O(N^2)

/*

class Solution{
  public:
    int maxArea(vector<int> &height)
    {
        int n= height.size();
        int maxArea= INT_MIN;

        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                 int area= min(height[i],height[j])* (j-i);
                 maxArea= max(maxArea,area);
            }
        }
        return maxArea;
    }
};

*/