// TC= O(N) + O(K/2) ->> O(N)

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n= arr.size();
        
        // remainder can vary from 0 to k-1
        vector<int> mp(k,0);

        for(int i=0; i<n; i++)
        {
            // arr[i] is -ve, handle -ve remainder as well
            int rem= ((arr[i] % k)+ k) % k;
            mp[rem]++;
        }

           // Handle the case when rem= 0, it should be in pairs, only single values like 5,10 is NOT valid
           if(mp[0] % 2 != 0)
           {
              return false;
           }
           
           // rem can vary from 0 to k-1, but we need to check only upto k/2 as these pairs are same(3,2) (2,3)
           for(int rem= 1; rem<= k/2; rem++)
           {
              if(mp[rem] != mp[k- rem])
              {
                 return false;
              }
           }
  
      return true;  
    }
};