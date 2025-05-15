class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans;

        int prev = -1;
        int n = groups.size();

        for(int i=0 ; i<n ; i++){
            if(prev!=groups[i]){
                ans.push_back(words[i]);
                prev = groups[i];
            }
        }

        return ans;
    }
};