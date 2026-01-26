class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n= arr.size();
        sort(arr.begin(),arr.end());

        if(n== 1) return {};

        vector<vector<int>> ans;
        int i=1;
        int minDiff= INT_MAX;
        while(i < n)
        {
            int diff= arr[i]-arr[i-1];
            if(diff < minDiff)
            {
                minDiff= diff;
                ans.clear();
                ans.push_back({arr[i-1],arr[i]});
            }
            else if(diff== minDiff)
            {
                ans.push_back({arr[i-1],arr[i]});
            }
            i++;
        }
      return ans;  
    }
};

