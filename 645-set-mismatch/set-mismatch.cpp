// Approach 2 -> Using maths
/*
    long long val1= sum-Sn;     // x-y
    long long val2= sumSq-Sn2;  // x^2 - y^2

    // val1= x-y
    // val2= (x+y)*(x-y) => val1* (x+y)
    // x+y= val2/val1
    // x-y= val1

    // x= (val2/va1  + val1)/2
    // y= x - val1
*/


// TC= O(N)

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n= nums.size();
        long long sum= 0, sumSq= 0;
        
        for(int i=0; i<n; i++)
        {
            sum+= nums[i];
            sumSq+= 1LL* nums[i]* nums[i];
        }

        long long Sn= (long long) n* (n+1)/2;
        long long Sn2= (long long) n* (n+1)* (2*n+1)/6;

        long long val1= sum-Sn;     // x-y
        long long val2= sumSq-Sn2;  // x^2 - y^2

        long long x= val2/val1;
        x+= val1;
        x= x/2;

        long long y= x - val1;

       return {(int) x, (int) y};
    }
};






// Approach 1 -> Using unordered_map
// TC= O(N)

/*

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n= nums.size();
        int repeat= -1, missing= -1;
        unordered_map<int,int> mp;

        for(int i=0; i<n; i++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]]== 2)
            {
                repeat= nums[i];
            }
        }

        for(int i=1; i<=n; i++)
        {
            if(mp[i]== 0)
            {
                missing= i;
            }
        }
    return {repeat, missing};
    }
};

*/