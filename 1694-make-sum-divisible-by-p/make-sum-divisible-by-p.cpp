// Approach 2 -> 

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
       int n= nums.size();
      
       long long sum= 0;
       for(int i=0; i<n; i++)
       {
          sum+= nums[i];
       } 

       if(sum % p== 0)
       {
          return 0;
       }
 
       int target= sum % p;
       
       // {element, index}
       unordered_map<int,int> mp;
       
       // To handle the case when sum is already divisible by p
       mp[0]= -1;

       int minLen= n;
       long long prefixSum= 0;

       for(int i=0; i<n; i++)
       {
          prefixSum= (((prefixSum + nums[i]) % p)+ p) % p;

          int rem= (((prefixSum- target) % p)+ p) % p;

          if(mp.find(rem) != mp.end())
          {
              minLen= min(minLen, i- mp[rem]);
          }
        
        mp[prefixSum]= i;
       }
       
       if(minLen== n)
       {
          return -1;
       }
       
    return minLen;
    }
};





// Approach 1 -> Beats 87% 

/*

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
       int n= nums.size();
      
       long long sum= 0;
       for(int i=0; i<n; i++)
       {
          sum+= nums[i];
       } 

       if(sum % p== 0)
       {
          return 0;
       }
       
       // {element, index}
       unordered_map<int,int> mp;
       
       // To handle the case when sum is already divisible by p
       mp[0]= -1;

       int minLen= n;
       long long prefixSum= 0;

       int target= sum % p;
       for(int i=0; i<n; i++)
       {
          prefixSum= (prefixSum + nums[i]) % p;
          if(prefixSum < 0)
          {
             prefixSum+= p;
          }

          int rem= (prefixSum- target) % p;
          if(rem < 0)
          {
             rem+= p;
          }

          if(mp.find(rem) != mp.end())
          {
              minLen= min(minLen, i- mp[rem]);
          }
        
        mp[prefixSum]= i;
       }
       
       if(minLen== n)
       {
          return -1;
       }

    return minLen;
    }
};

*/