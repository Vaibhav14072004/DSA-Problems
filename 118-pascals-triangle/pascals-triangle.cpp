// TC= O(N^2)

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        if(numRows== 1) return ans;

        ans.push_back({1,1});   
        if(numRows== 2) return ans;

        for(int i=3; i<= numRows; i++)
        {
            vector<int> curr;
            curr.push_back(1);

            vector<int> temp= ans.back();
            for(int j=1; j<temp.size(); j++)
            {
                int sum= temp[j-1]+ temp[j];
                curr.push_back(sum);
            }

            curr.push_back(1);
          ans.push_back(curr);  
        }
     return ans;   
    }
};