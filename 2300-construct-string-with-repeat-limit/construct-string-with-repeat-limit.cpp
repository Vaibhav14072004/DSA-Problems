// Approach 1 -> Sliding Window
// TC= O(N) + O(26 + N)  ->> O(N)
// SC= O(26) -> O(1)

// ans+=string(cnt,ch) or ans.append(cnt,ch) ->> Takes O(N) time

class Solution {
public:
    string repeatLimitedString(string str, int repeatLimit) {
        int n= str.length();
        vector<int> freq(26,0);

        for(int i=0; i<n; i++)
        {
            freq[str[i]-'a']++;
        }

        int j= 25;
        string ans= "";
        while(j >=0)
        {
            if(freq[j]== 0)
            {
                j--;
                continue;
            }

            int cnt= min(freq[j],repeatLimit);
            char ch= j + 'a';
            ans+= string(cnt, ch);  // Takes O(N) Time 
            // ans.append(cnt, ch);

            freq[j]-= cnt;

            // now append one previous char..
                if(freq[j] > 0)
                {
                   int i= j-1;
                   while(i>=0 && freq[i]== 0)
                   {
                      i--;
                   }

                   if(i< 0)
                     break;

                   ans+= (char) (i+ 'a');
                   freq[i]--;
                }
        }
        return ans;
    }
};