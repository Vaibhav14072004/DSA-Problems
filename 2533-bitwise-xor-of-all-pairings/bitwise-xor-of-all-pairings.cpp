// Approach 3 -> WITHOUT using map

/*
XOR of same elements will be 0
Therefore XOR of even freq elements will be 0
So need to calculate XOR of ODD elements only..
Elements of nums1 will appear n2 times
Elements of nums2 will appear n1 times

If n1 is odd but n2 is even, directly take XOR of elements of nums2 
If n1 is EVEN but n2 is ODD, directly take XOR of elements of nums1
*/

// TC= O(N+M)
// SC= O(1)

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1= nums1.size();
        int n2= nums2.size();
        int ans= 0;
        
        // if n1 is ODD but n2 is EVEN, take XOR of nums2
        if((n1 % 2 == 1) && (n2 % 2 == 0))
        {
            for(auto it: nums2)
            {
               ans^= it;
            }
        }

        // if n1 is EVEN but n2 is ODD, take XOR of nums1
        else if((n1 % 2== 0) && (n2 % 2 == 1))
        {
            for(auto it: nums1)
            {
                ans^= it;
            }
        }

        // if both n1 and n2 is ODD, take XOR of all elements of nums1 as well as nums2
        else if((n1 % 2== 1) && (n2 % 2== 1))
        {
           for(auto it: nums1)
           {
              ans^= it;
           }
           for(auto it: nums2)
           {
              ans^= it;
           }
        }

        // if both n1 and n2 is EVEN, XOR will be 0
        else
        {
            return 0;
        }
      return ans;
    }
};






// Approach 2 ->> Using unordered_map
// Elements of arr1 will appear n2 no of times, and elements of arr2 will appear n1 no of times
// Even freq will cancel each other as XOR of same elements is 0, ans will be xor of odd elements

// TC= O(N+M)
// SC= O(N)

/*

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1= nums1.size();
        int n2= nums2.size();

        unordered_map<int,long long> mp;
        int i= 0, j= 0, ans= 0;

        // elements of arr1 will appear n2 no of times..
        while(i < n1)
        {
            mp[nums1[i]]+= n2;
            i++;
        }
        
        // elements of arr2 will appear n1 no of times..
        while(j< n2)
        {
           mp[nums2[j]]+= n1;
           j++;
        }
 
        // ans will be the XOR of odd freq elements as XOR of same elements will be 0
        for(auto it: mp)
        {
            if(it.second % 2 == 1)
            {
                ans= ans ^ (it.first);
            }
        }
      return ans;
    }
};

*/








//  ------ TLE ---------
// Approach 1 -> Brute Force
// TC= O(N^2)+ O(N) ->> O(N^2)

/*

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n= nums1.size();
        vector<int> nums3;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                nums3.push_back(nums1[i] ^ nums2[j]);
            }
        }
        
        int ans=0;
        for(int i=0; i<nums3.size(); i++)
        {
           ans= ans ^ nums3[i];
        }
      return ans;  
    }
};
*/