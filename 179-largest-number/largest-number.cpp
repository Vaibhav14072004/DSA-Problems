class Solution {
public:
    static bool comp(string& a, string& b){
        return ((a+b)>(b+a));
    }
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for(auto x:nums){
            v.push_back(to_string(x));
        }
        sort(v.begin(),v.end(),comp);
        // Handle case where the largest number is "0" (e.g., [0,0])
        if (v[0] == "0") return "0";
        string res;
        for(auto x:v){
            res+=x;
        }
        return res;
    }
};