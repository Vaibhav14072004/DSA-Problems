class Solution {
    bool isSamePar(int &a, int &b) {
        return (a % 2 == b % 2);
    }
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 || isSamePar(nums[i], nums[i-1])) {
                res.push_back(i); 
            } else {
                res.push_back(res.back());            }
        }

        vector<bool> ans;

        for (auto q : queries) {
            int ind = q[1];
            int req = q[0];

            ans.push_back(res[ind] <= req);
        }

        return ans;
    }
};