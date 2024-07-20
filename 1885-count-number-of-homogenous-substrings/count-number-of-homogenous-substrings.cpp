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
    int countHomogenous(string str) {
       int n= str.length();
       int MOD= 1000000007;

       int ans= 0, len= 0;
       for(int i=0; i<n; i++)
       {
            if(i>0 && str[i-1]== str[i])
            {
                len++;
            }
            else
            {
                len= 1;
            }

            ans= (ans+ len) % MOD;
       }
      return ans; 
    }
};