class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n= gain.size();
        int maxi= 0;

        int val= 0;
        for(int i=0; i<n; i++)
        {
            val+= gain[i];
            maxi= max(maxi,val);
        }
    return maxi;    
    }
};