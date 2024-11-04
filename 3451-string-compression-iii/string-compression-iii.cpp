// TC= O(N)

class Solution {
public:
    string compressedString(string word) {
        int n= word.length();

        // base case
        if(n== 0){
         return "";
        }

        if(n==1){
          string temp= to_string(1);
          temp+= word[0];
          return temp;
        }
        
        string ans= "";
        int cnt= 1;

        for(int i=1; i<= n; i++)
        {
            if(i<n  && word[i]== word[i-1] && cnt < 9)
            {
                cnt++;
            }
            else
            {
                ans+= to_string(cnt);
                ans+= word[i-1];
                cnt= 1;
            }
        }
       return ans;  
    }
};