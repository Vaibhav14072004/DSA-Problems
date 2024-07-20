/*
1 element =>    a -> 1
2 elements =>  aa -> subarrays will be a,a,aa ->> 3
3 elements => aaa -> subarrays will be a,a,a,aa,aa,aaa -> 6
4 elements => aaaa -> subarrays will be a,a,a,a,aa,aa,aa,aaa,aaa,aaaa -> 10

Which is equal to summation upto length....
 Ex-  4 elements -> 1 + 2 + 3 + 4 => 10 subarrays...

*/

// TC= O(N)

class Solution {
public:
    int numSub(string s) {
        int n= s.length();

        int MOD= 1e9+7;
        int ans= 0, len= 0;
        for(int i= 0; i<n; i++)
        {
            if(s[i]== '1')
            {
               len++;
            }
            else
            {
                len= 0;
            }

            ans= (ans+len) % MOD;
        }
      return ans;  
    }
};