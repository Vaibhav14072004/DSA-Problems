class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(), s.end());
        sort(g.begin(),g.end());

        int ans= 0, i= 0, j= 0;

        while(i < g.size() && j < s.size())
        {
            if(g[i] <= s[j])
            {
                i++;
                ans++;
            }
            j++;
        }

       return ans; 
    }
};