class Solution {
public:
    vector<int> sumZero(int n) {
       vector<int> res;
       for(int i=0;i<n;i++){
        res.push_back(-n + 1 + 2*i);
       } 
       return res;
    }
};