class Solution {
    int binarysearch(vector<int>&nums,int mul,long long success) {
        int low = 0;
        int n = nums.size();
        int high = n-1;
        int ans = -1;
        while(low<=high) {
            int mid = (low+high)/2;
            if(1ll*nums[mid]*1ll*mul>=success) {
                ans = mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return ans;
    }
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int> ans;
        int n = potions.size();
        int count;
        for(int i=0;i<spells.size();i++) {
            count = 0;
            int index = binarysearch(potions,spells[i],success); 
            if(index!=-1) {
                count+=n-index;
            }
            else {
                count = 0;
            }
           ans.push_back(count); 
        }
        return ans;
    }
};