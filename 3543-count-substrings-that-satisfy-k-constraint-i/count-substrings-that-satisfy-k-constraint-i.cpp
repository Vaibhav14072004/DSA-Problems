// Ques of Sliding Window...

// Approach 2 -> Sliding Window
// TC= O(2* N) ->> O(N)

class Solution{
  public:
    int countKConstraintSubstrings(string str, int k) {
       int n= str.length();
       int ans= 0;  
       int i= 0, j= 0;
       int cnt0= 0, cnt1= 0;

       while(j < n)
       {
           if(str[j]== '0'){
              cnt0++;
           }

           else{
            cnt1++;
           }

         // shrink the curr window...
         // we use && instead of || bcoz substring is valid even if cnt0 <= k or cnt1 <= k
           while(cnt0 > k && cnt1 > k)
           {
               if(str[i]== '0'){
                cnt0--;
               }

               else{
                cnt1--;
               }

               i++;
           }

        ans+= j-i+1;  
        j++;
      }
      return ans; 
    }
};





// Approach 1 -> Brute Force ->> Generate all substrings...
// TC= O(N^2)

/*

class Solution {
public:
    int countKConstraintSubstrings(string str, int k) {
        int n= str.length();
        int ans= 0;

        for(int i=0; i<n; i++)
        {
            int cnt0= 0, cnt1= 0;
            for(int j=i; j<n; j++)
            {
               if(str[j]== '0'){
                   cnt0++;
               }

               else{
                 cnt1++;
               }
               
               if(cnt0 <= k || cnt1 <= k)
               {
                   ans++;
               }

               // check for any other subarray...
               else
               {
                  break;
               }
            }
        }
    return ans;
    }
};

*/