class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int ans =-1;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int dominant;
        int maxi=0;
        for(auto i: mp){
            if(i.second>maxi){
            maxi = i.second;
            dominant = i.first;
            }
        }

        cout<<dominant<<endl;
        int countleft=0;

        for(int i=0;i<n-1;i++){
            if(nums[i]==dominant){
                countleft++;
            }
            int countright = maxi-countleft;
            int lenleft = i+1;
            int lenright = n-lenleft;
            if(countleft*2>lenleft && countright*2>lenright){
                ans=i;
                return ans;
            }
            
        }
        return ans;
    }
};