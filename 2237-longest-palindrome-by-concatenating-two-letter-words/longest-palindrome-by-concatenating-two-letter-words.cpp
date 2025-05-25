// Approach -> Using unordered_map
// TC= O(N)

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n= words.size();
        unordered_map<string,int> mp;
        int cnt= 0, equalChars= 0;

        // for case like 'aa' 'aa' already handled
        for(int i=0; i<n; i++)
        {
            string rev= words[i];
            swap(rev[0],rev[1]);

            if(mp[rev] > 0)
            {
                cnt+= 4;
                mp[rev]--;
            }
            else
            {
                mp[words[i]]++;
            }
        }

        // to handle case like 'gg' 'aa', we can only consider one pair in between 
        for(auto it: mp)
        {
            string curr= it.first;
            int freq= it.second;
            if(curr[0]== curr[1] && freq > 0)
            {
                cnt+= 2;
                break;
            }
        }
     return cnt;   
    }
};