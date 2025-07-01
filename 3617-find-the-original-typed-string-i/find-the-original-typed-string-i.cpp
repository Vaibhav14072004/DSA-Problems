// Approach 1 -> 
// TC= O(N)


class Solution {
public:
    int possibleStringCount(string word) {
        int n= word.length();

        int ans= 0;
        for(int i=1; i<n; i++)
            {
                char prev= word[i-1];
                if(word[i]== prev)
                {
                    ans++;
                } 
            }
        return ans + 1;
    }
};
