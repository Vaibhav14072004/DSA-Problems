class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int n= nums.size();
        unordered_set<int> st(nums.begin(),nums.end());

        while(true)
        {
            if(st.count(original))
            {
               original= 2* original;
            }
            else
            {
                break;
            }
        }
    return original;
    }
};