// Append freq first, then element itself
// TC= O(N)

class Solution {
public:
    string countAndSay(int n) {
        // base case
        if(n== 1){
            return "1";
        } 

        string str= countAndSay(n-1);

        string ans= "";

        int i=0;
        while(i < str.length())
        {
            int cnt= 1;
            while(i+1 < str.length() && str[i]== str[i+1])
            {
                cnt++;
               i++;
            }

            ans+= to_string(cnt) + str[i];
            i++;
        }
    return ans;
    }
};