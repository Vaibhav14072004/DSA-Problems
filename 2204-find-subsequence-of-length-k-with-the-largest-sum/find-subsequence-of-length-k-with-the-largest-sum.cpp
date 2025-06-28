// TC= O(2N* log N) + O(2*N)

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) 
    {
        int n= nums.size();
        if(k > n) return {};

        vector<pair<int,int>> vec;
        for(int i=0; i<n; i++){
            vec.push_back({nums[i],i});
        }

        sort(vec.begin(),vec.end());  
        vector<pair<int,int>> temp;
                
        int i=n-k;
        while(i < n)
        {
            int idx= vec[i].second;
            int val= vec[i].first;
            temp.push_back({idx,val});
            i++;
        }

        sort(temp.begin(),temp.end());

        vector<int> ans(k);
        for(int i=0; i<k; i++)
        {
            ans[i]= temp[i].second;
        }
      return ans;  
    }
};