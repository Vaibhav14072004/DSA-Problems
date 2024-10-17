class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        vector<int> m ( 10 , -1);
        for(int i =0;i<s.length();i++){
            m[s[i]-'0'] = i;
        }
        string s2 = s;
        sort(s2.rbegin() , s2.rend());
        for(int i=0;i<s.length();i++){
            if(s2[i] != s[i]){
                int  it = m[s2[i]-'0'];
                swap(s[i],s[it]);
                break;
            }
        }
        return stoi(s);
    }
};