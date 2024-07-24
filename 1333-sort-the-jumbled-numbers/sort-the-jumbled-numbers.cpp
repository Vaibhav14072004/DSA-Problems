// TC=> for 2 loops... O(n * d) -> where d is log n generally...
// to_string()   and  stoi()  takes O(d) time...

// Overal TC= O(n * log n) + O(n log n)+ O(N)

// SC=O(N + d)

class Solution {
public:
// sort in ascending order based on val..if val same then not do any thing .
    static bool cmp(pair<int,int> &a, pair<int,int> &b)
    {
    return a.second < b.second;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n= nums.size();

        vector<pair<int,int>> vec;
        for(int i=0; i<nums.size(); i++)
        {
            string mappedStr= "";
            string str= to_string(nums[i]);

            for(char ch: str)
            {
                 mappedStr= mappedStr+ to_string(mapping[ch-'0']);
            }
            
          int val= stoi(mappedStr);
          vec.push_back({nums[i], val});
        }
        
        sort(vec.begin(), vec.end(), cmp);
        
        vector<int> ans;
        for(auto it: vec)
        {
            ans.push_back(it.first);
        }
       return ans; 
    }
};