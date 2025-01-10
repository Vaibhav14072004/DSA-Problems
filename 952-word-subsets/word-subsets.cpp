// Subarray (substring) ->> Continuous part..
// Subsequence ->> Not continuous, but relative order must be same..
// Subset ->> Not Continuous, NO order needed, just see match freq of all elements...

// TC= O(26* N) + O[N* (26+ 26)] =>> O(N)

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2){

        // to store max cnt of freq for any char in words of words1 vector...
        vector<int> maxFreq(26,0);
        
        vector<string> ans;
        for(string word: words2)
        {
            vector<int> tempFreq(26,0);
            for(char ch: word)
            {
                tempFreq[ch-'a']++;
                maxFreq[ch-'a']= max(maxFreq[ch-'a'], tempFreq[ch-'a']);
            }
        }

        for(string word: words1)
        {
            bool flag= true;
            vector<int> freq1(26,0);
            for(auto ch: word)
            {
                freq1[ch-'a']++;
            }

            for(int i=0; i<26; i++)
            {
                if(freq1[i] < maxFreq[i])
                {
                    flag= false;
                    break;
                }
            }

            if(flag)
            {
                ans.push_back(word);
            }
        }
     return ans;   
    }
};