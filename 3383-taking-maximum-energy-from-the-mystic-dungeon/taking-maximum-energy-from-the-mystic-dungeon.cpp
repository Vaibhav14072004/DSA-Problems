class Solution {
public:
    int f(int i,vector<int>& energy, int k,int s){
        if(i>=energy.size()){
            return 0;
        }
       return s = energy[i] + f(i+k,energy,k,s);
    }
    int maximumEnergy(vector<int>& energy, int k) {
        int s = 0;
        map<int,int>hash;
        int maxi = INT_MIN;
        int t =0;
        for(int i = energy.size()-1;i>=0;i--){
            if(hash.find(i+k) == hash.end()){
            t = energy[i]+f(i+k,energy,k,s);
            }
            else{
            t = energy[i]+hash[i+k];
            }
                hash[i] = t;
            maxi = max(maxi,hash[i]);

        }
        return maxi;
    }
};