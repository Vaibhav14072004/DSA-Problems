class Solution {
public:
    bool checkOnesSegment(string str) {
        int n= str.length();

        if(n== 1) return str[0]== '1';

        for(int i=1; i<n; i++)
        {
            // There is NO leading zero, so 1  0 1 -> 2 segments of 1 -> return false;
            if(str[i-1]== '0' && str[i]== '1') return false;
        }
        return true;
    }
};