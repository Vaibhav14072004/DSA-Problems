class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int>count;
        int mex=0;
        for(int n:nums){
            int mod=((n%value)+value)%value;
            count[mod]++;
        }
        while(true){
            int mod=mex%value;
            if(count[mod]>0){
                count[mod]--;
            }
            else{
                return mex;
            }
            mex++;
        }

    }
};