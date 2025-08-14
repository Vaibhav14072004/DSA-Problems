class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        string ans = "";
        for(int i =0; i<=n-3; i++){
            if(num[i] == num[i+1] and num[i] == num[i+2]){
                
                string curr = num.substr(i, 3);
                if(curr > ans) ans = curr;
                
            }
        }
        
        return ans;
    }
};