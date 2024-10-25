// Approach 2 -> Using unordered_set
// TC= O(N^2)

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int n= folder.size();
        
        unordered_set<string> st(folder.begin(), folder.end());
        vector<string> ans;

        for(int i=0; i<n; i++)
        {
            string str= folder[i];
            bool flag= false;

            // first find position of last '/'
            for(int j=str.length()-1; j>=0; j--)
            {
                if(str[j]== '/')
                {
                    string curr= str.substr(0,j);

                    // if front portion of curr string is found in set, it is subfolder
                    if(st.find(curr) != st.end())
                    {
                        flag= true;
                        break;
                    }
                }
            }

            if(!flag)
            {
                ans.push_back(folder[i]);
            }
        }
    return ans;
    }
};








// Approach 1 -> Using sorting
// TC= O(N log N)

/*

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

*/