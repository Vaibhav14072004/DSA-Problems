class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> words;
        stringstream ss(s1);
        string word;

        unordered_map<string, int>flag;

        while (ss >> word) {
            if(flag[word]!=-1)
                flag[word]++;
            if(flag[word]>1)
                flag[word]=-1;
        }
        
        stringstream ss2(s2);
        
        while (ss2 >> word) {
            if(flag[word]!=-1)
                flag[word]++;
            if(flag[word]>1)
                flag[word]=-1;
        }

        vector<string>res;

        for(auto const&pair:flag) {
            if(pair.second==1)
                res.push_back(pair.first);
        }
        
        return res;
    }
};