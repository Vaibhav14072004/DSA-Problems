// TC= O(N^2)

class Solution {
public:
    string answerString(string word, int numFriends) {
        int n= word.length();
        string maxStr;
        
        // base case
        if(numFriends ==1) return word;
        
        int canTake= n- (numFriends-1);
        for(int i=0; i<n; i++)
        {
            int minLen= min(canTake, n-i);
            maxStr= max(maxStr, word.substr(i,minLen));
        }
     return maxStr;   
    }
};