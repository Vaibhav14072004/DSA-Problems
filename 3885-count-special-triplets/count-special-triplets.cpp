class Solution {
public:
    const int MOD= 1000000007;
    int specialTriplets(vector<int>& nums)
    {
        int n= nums.size();
        unordered_map<long,long> rightMap;

        for(int i=0; i<n; i++){
            rightMap[nums[i]]++;
        }

        unordered_map<long,long> leftMap;

        long long cnt= 0;

        // considering the i'th index as middle element, find whether 2*nums[i] exists in left and right map also
        for(int i=0; i<n; i++)
        {
            rightMap[nums[i]]--;

            long long target= 2LL*nums[i];

            cnt= (cnt+ (leftMap[target]*rightMap[target]) % MOD) % MOD; 
            
            leftMap[nums[i]]++;
        }

    return static_cast<int> (cnt);  
    }
};



