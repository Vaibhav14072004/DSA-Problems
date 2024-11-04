// Approach 2 -> Using while loop
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

        int i=0;
        string ans= "";

        while(i < n)
        {
            char curr= word[i];
            int cnt= 1;
            while(i+1 < n && curr== word[i+1])
            {
                cnt++;
                i++;
            }

            if(cnt <= 9)
            {
                ans+= to_string(cnt);
                ans+= curr;
            }
            else
            {
                int d= cnt/9;
                int rem= cnt % 9;
                while(d > 0)
                {
                    ans+= to_string(9);
                    ans+= curr;
                    d--;;
                }

                if(rem != 0)
                {
                    ans+= to_string(rem);
                    ans+= curr;
                }
            }
            i++;
        }
    return ans;
    }
};





// Approach 1 -> Using for loop
// TC= O(N)

/*

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

*/