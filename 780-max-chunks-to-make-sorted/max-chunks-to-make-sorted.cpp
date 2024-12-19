/*
 If the curr partition is sorted...
   Max of prev Partition < Min of curr partition

   0 ....  i | i+1 ..... j

so whenever maximum val of curr becomes = arr[i], do partition
*/

// TC= O(N)

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n= arr.size();
        int cnt= 0;
        int maxi= 0;

        for(int i=0; i<n; i++)
        {
            maxi= max(maxi, arr[i]);
            if(maxi== i)
            {
                cnt++;
            }
        }
        return cnt;
    }
};