// Approach 1 ->  Recursion
// TC= O(N log N) + O(N* 2^N)

class Solution {
public:
    void solve(int index,vector<int> &candidates, int target, vector<vector<int>> &output, vector<int> ans)
    {
        // base case
        if(target < 0)
        {
            return;
        }

        if(target ==0)
        {
            output.push_back(ans);
            return;
        }

        for(int i= index; i<candidates.size(); i++)
        {
            // bcoz each no can be used only once...
            if(i > index && candidates[i]== candidates[i-1])
            {
                continue;
            }
            ans.push_back(candidates[i]);

            solve(i+1, candidates, target-candidates[i], output, ans);

            ans.pop_back(); // backtracking....
        }
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
         vector<int> ans;
         vector<vector<int>>output;
         sort(candidates.begin(), candidates.end()); // sort in asceding order...
         solve(0,candidates, target, output, ans);
         return output;
    }
};