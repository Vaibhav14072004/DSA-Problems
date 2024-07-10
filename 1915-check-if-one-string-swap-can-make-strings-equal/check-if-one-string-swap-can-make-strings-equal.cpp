class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n= s1.length();
        int m= s2.length();

        // base case
        if(n != m) return false;

        vector<int> diff;
        int i=0;
        while(i< n)
        {
            if(s1[i] != s2[i])
            {
                diff.push_back(i);
            }
            i++;
        }
    
    // max allowed operations are 0 or 1 only..
        if(diff.size()== 0)
        {
            return true;
        }

        if(diff.size()== 2)
        {
            int i= diff[0], j= diff[1];
            if(s1[i]== s2[j] && s1[j]== s2[i])
            {
                return true;
            }
        }

      // else return false;
        return false;
    }
};