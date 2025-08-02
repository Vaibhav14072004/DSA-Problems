class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> freq ;
        for(int X : basket1) freq[X]++ ;
        for(int X : basket2) freq[X]-- ;

        vector<int> extra ;
        int minival = INT_MAX ;
        for(auto& [p, q] : freq){
            if(q%2) return -1 ;
            for(int i = 0; i<abs(q)/2; i++)
            extra.push_back(p) ;
            minival = min(minival, p) ;
        }
        sort(extra.begin(), extra.end()) ;
        long long cost = 0;
        for(int i = 0; i<extra.size()/2; i++)
        cost = cost + min(extra[i], 2*minival);
        return cost ;
    }
};