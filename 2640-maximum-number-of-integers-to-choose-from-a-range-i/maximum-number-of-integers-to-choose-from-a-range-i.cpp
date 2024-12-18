// Approach 1 -> Using unordered_set
// TC= O(N)

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
         int ans= 0;
         unordered_set<int> st(banned.begin(),banned.end());
         
         int currSum= 0;
         for(int i=1; i<=n; i++)
         {
             if(st.find(i) == st.end() && currSum+i <= maxSum){
                 currSum+= i;
                 ans++;
             }
         }
      return ans;
    }
};