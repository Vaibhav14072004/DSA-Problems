class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans = "";
        for(auto c : s){
            ans.push_back(c);
            if(ans.size()>=part.size() && ans.substr(ans.size()-part.size()) == part){
                int popCount = part.size();
                while(popCount){
                    ans.pop_back();
                    popCount--;
                }
            }
        }
        return ans;
    }
};