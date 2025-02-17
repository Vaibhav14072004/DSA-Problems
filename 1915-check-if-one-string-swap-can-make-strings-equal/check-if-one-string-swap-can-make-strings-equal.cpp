// Approach 1 
// TC= O(N)

class Solution {
public:
    bool areAlmostEqual(string s1, string s2){
        // base case
        if(s1.length() != s2.length()){
            return false;
        }

        if(s1== s2) return true;
 
        int n= s1.length();
        int diffCnt= 0;

        vector<int> diffIdx;
        for(int i=0; i<n; i++)
        {
           if(s1[i] != s2[i]){
               diffCnt++;
               diffIdx.push_back(i);
           }
           if(diffCnt > 2) {
              return false;
           }
        }

      return diffCnt== 2 && (s1[diffIdx[0]]== s2[diffIdx[1]]) && (s1[diffIdx[1]]== s2[diffIdx[0]]);  
    }
};