// Sum of 2 sides must be > third side

class Solution {
public:
    string triangleType(vector<int>& nums) {
        int n= nums.size();
        int a= nums[0];
        int b= nums[1];
        int c= nums[2];

        if(a+b <= c || a+c <= b || b+c <= a)
        {
            return "none";
        }
        else if(a== b && b== c)
        {
            return "equilateral";
        }
        else if(a== b || b== c || a== c)
        {
            return "isosceles";
        }
     return "scalene";   
    }
};