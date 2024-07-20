// Approach 1 ->> Using stack
// Remove larger digits at first...

// TC= O(N + K)

class Solution {
public:
    string removeKdigits(string nums, int k) {
         int n= nums.length();
         stack<char> st;

         // base case
         if(k== n){
             return "0";
         }

         for(int i=0; i<n; i++)
         {
             // Remove until st.top() is > than curr element..
              while(!st.empty() && k > 0 && (st.top()-'0') > (nums[i]-'0'))
              {
                  st.pop();
                  k--;
              }
            st.push(nums[i]);
         }

        // if the elements are in increasing order - 1 2 3 4 5
        // stack will NOT remove anything, but k remains intact..
        // In this way remove last k digits..

        while(!st.empty() && k> 0)
        {
            st.pop();
            k--;
        }

         if(st.empty()){
            return "0";
         }

         string ans= "";

         // we get ans in reverse order..
         while(!st.empty())
         {
           ans+= st.top();
            st.pop();
         }

        reverse(ans.begin(), ans.end());

        // Skip leading zeroes if any.. Ex- 001542 ->> 1542
        int i=0;
        while(i<ans.length() && ans[i]== '0')
        {
            i++;
        }

        if(i== ans.length())
        {
            return "0";
        }
        
        // Return the substring from the first non-zero character
        return ans.substr(i);
    }
};