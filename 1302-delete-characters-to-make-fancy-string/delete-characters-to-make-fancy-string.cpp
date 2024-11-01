// Approach 2 
// TC= O(N)

class Solution{
public:
   string makeFancyString(string s) {
        int n= s.length();
        
        if(n < 3){
          return s;
        }
        
        int i=0, cnt= 0;
        string ans= "";

        while(i< n)
        {
            cnt++;
            if(!ans.empty() && ans.back() != s[i])
            {
                cnt= 1;
            }

            if(cnt < 3)
            {
                ans+= s[i];
            }
        i++;
        }
    return ans;
   }
};







// Approach 1 
// TC= O(N)

/*
class Solution {
public:
    string makeFancyString(string s) {
        int n= s.length();
        
        if(n < 3)
        {
            return s;
        }

        string ans= "";
        for(int i=0; i<n; i++)
        {
            if(i>= 2 && s[i]== s[i-1] && s[i-1]== s[i-2])
            {
                 if(!ans.empty()) 
                  ans.pop_back();
            }
         ans+= s[i];
        }
      return ans;  
    }
};

*/