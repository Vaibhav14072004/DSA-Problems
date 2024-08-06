// TC= O(N) + O(26* log 26) + O(26)

// TC= O(N)
// SC= O(26) ->> O(1)

class Solution {
public:
    int minimumPushes(string word) {
        int n= word.length();

        vector<int> freq(26,0);
        for(int i=0; i<n; i++)
        {
            freq[word[i]- 'a']++;
        }
        
        // sort by descending order of frequency..
        // sort(freq.begin(), freq.end(), greater<int> ());
        sort(freq.rbegin(), freq.rend());
        
        int ans= 0;
        for(int i=0; i<26; i++)
        {
            ans+= (freq[i])* (1 + i/8);
        }
    return ans;
    }
};