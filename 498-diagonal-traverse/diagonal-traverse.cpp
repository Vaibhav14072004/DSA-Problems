/*

i+j   No
----------
0->   1
1->   2,4
2->   3,5,7
3->   6,8
4->   9
-----------
*/

// Approach -> Using unordered_map
// TC= O(N)

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int row= mat.size();
        int col= mat[0].size();

        map<int,vector<int>> mp;
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                mp[i+j].push_back(mat[i][j]);
            }
        }
        
        bool flip= true;
        vector<int> ans;

        for(auto &it: mp)
        {
            vector<int> temp= it.second;

            // if flip is true, reverse 
            if(flip)
            {
               reverse(temp.begin(),temp.end());
            }
            
            for(int i=0; i<temp.size(); i++)
            {
                ans.push_back(temp[i]);
            }
            flip= !flip;
        }
      return ans;  
    }
};
