// Approach 1 -> Using sorting
// TC= O(N log N)

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int n= folder.size();

        // sort lexographically in ascending order...
        sort(folder.begin(),folder.end());

        vector<string> ans;
        ans.push_back(folder[0]);

        for(int i=1; i<n; i++)
        {
            string prev= ans.back();
            prev+= '/';
            
            // if prev string is NOT found in folder[i], means is NOT sub folder..
            if(folder[i].find(prev) != 0)
            {
                ans.push_back(folder[i]);
            }
        }
        return ans;
    }
};