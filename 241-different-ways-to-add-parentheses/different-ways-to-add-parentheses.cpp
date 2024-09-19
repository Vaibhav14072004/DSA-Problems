class Solution {
public:
    vector<int> solve(string &s, int i, int j){

        vector<int> res;
        for(int k=i; k<=j; k++){
            if(s[k] == '+' || s[k] == '-' || s[k] == '*'){
                vector<int> left_res = solve(s, i, k - 1);
                vector<int> right_res = solve(s, k + 1, j);

                for(auto &x : left_res){
                    for(auto &y : right_res){
                        if(s[k] == '+'){
                            res.push_back(x + y);
                        }
                        else if(s[k] == '-'){
                            res.push_back(x - y);
                        }
                        else{
                            res.push_back(x * y);
                        }
                    }
                }

            }
        }

        if(res.empty()){
            res.push_back(stoi(s.substr(i, j - i + 1)));
        }

        return res;

    }

    vector<int> diffWaysToCompute(string s) {
        return solve(s, 0, s.size() - 1);
    }
};