// Approach 1 -> 
// TC= O(N*d) + O(N)

class Solution {
public:
    int countLargestGroup(int n) {
        int maxSize= 0;
        
        // given that n= 10^4, maximum sum of 9999 can be 36
        // vector<int> vec(37,0);

        unordered_map<int,int> mp;
        for(int i=1; i<=n; i++)
        {
            string temp= to_string(i);
            int sum= 0;
            for(auto it: temp){
                sum+= (it-'0');
            }

            mp[sum]++;
            if(mp[sum] > maxSize)
            {
                maxSize= mp[sum];
            }
        }
        
        int cnt= 0;
        for(auto it: mp)
        {
            if(it.second== maxSize)
            {
                cnt++;
            }
        }

        return cnt;
    }
};