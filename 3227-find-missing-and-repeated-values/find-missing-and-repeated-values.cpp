// TC= O(N) + O(2501)
// Sc= O(2501)

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n= grid.size();
        vector<int> freq(2501,0);
        int repeat= -1;
        int missing= -1;
        
        for(int i=0; i<n; i++)
        {
            for(auto it: grid[i])
            {
                freq[it]++;
                if(freq[it]== 2)
                {
                    repeat= it;
                }
            }
        }

        for(int i=1; i<2501; i++)
        {
            if(freq[i]== 0)
            {
                missing= i;
                break;
            }
        }

        return {repeat,missing};
    }
};