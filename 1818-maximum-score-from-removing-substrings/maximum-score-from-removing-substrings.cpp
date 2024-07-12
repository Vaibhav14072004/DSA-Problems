// Approach 2 -> using 2 Pointers

class Solution{
public:

// we have to make changes to original strig so we pass it call by reference..
   int solve(string &s, char firstChar, char secondChar, int pts)
  {
       int n= s.length();  
       int left= 0, right= 0, points= 0;

       while(right < n)
       {
           s[left]= s[right];

           if(left >= 1 && s[left-1]== firstChar && s[left]== secondChar)
           {
               points+= pts;
               left= left-2; // to overwrite these characters... "ab" or "ba"
           } 

           left++;
           right++;
       }

       s= s.substr(0,left);
       return points;
  } 
 
   int maximumGain(string s, int x, int y) {
      int points= 0;   

      // first call for that operation that will give max points..    
       if(x >= y)
       {
           points+= solve(s,'a','b',x);
           points+= solve(s,'b','a',y);
       }
       else
       {
           points+= solve(s,'b','a',y);
           points+= solve(s,'a','b',x);
       }
       return points;
   } 
};







// Approach 1 -> Using stack..

// TC= O(3*N)* 2
// SC= O(2*N)* 2

/*

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

*/