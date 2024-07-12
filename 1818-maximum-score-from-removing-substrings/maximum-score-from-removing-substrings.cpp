// Approach 1 -> Using stack..

// TC= O(3*N)* 2
// SC= O(2*N)* 2

class Solution {
public:
 // we have to make changes to original string .. pass call by reference..

    int solve(string &s, string target, int pts)
    { 
        stack<char> st;
        int points= 0;
        for(int i=0; i<s.length(); i++)
        {
            if(!st.empty() && st.top()== target[0] && s[i]== target[1])
            {
                points+= pts;
                st.pop();  
            }
            else
            {
                st.push(s[i]);
            }
        }

     // change the original string after doing (removing) all "ab" or "ba" which ever has been done first
       s= "";
      while(!st.empty())
      {
           s+= st.top();
           st.pop();
      }

      reverse(s.begin(), s.end());
       
        return points;
    }


      int maximumGain(string s, int x, int y) {
             string s1= "ab";
             string s2= "ba";

            // first call for operation with max points..
            if(x < y)
            {
                swap(x,y);
                swap(s1,s2);
            }

            return solve(s,s1,x)+ solve(s,s2,y);
      }
};