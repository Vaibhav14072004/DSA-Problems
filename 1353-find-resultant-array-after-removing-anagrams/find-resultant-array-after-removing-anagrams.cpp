class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        int n = words.size();
        ans.push_back(words[0]);
        string prev = words[0];
        sort(prev.begin(), prev.end());
        for(int i = 1; i < n; i++) {
            string temp = words[i];
            sort(temp.begin(), temp.end());
            if(temp == prev) continue;
            else {
                prev = temp;
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};