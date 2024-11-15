/*
     <<<---- NOT A QUES OF SLIDING WINDOW  ---->>>
     Bcoz we do not know when to increase, decrease i, j so that
     vowls in curr substring maintains even count...
*/


// Approach 1 -> 
// TC= O(N)

class Solution {
public:
    int findTheLongestSubstring(string str) {
        int n= str.size();

        unordered_map<string,int> mp;
        string initial= "00000";
        mp[initial]= -1;
        
        // a e i o u
        vector<int> vowelCnt(5,0);
        
        int ans= 0;
        for(int i=0; i<n; i++)
        {
            if(str[i]== 'a'){
               vowelCnt[0]= (vowelCnt[0]+1) % 2;
            }
            else if(str[i]== 'e'){
                vowelCnt[1]= (vowelCnt[1]+1) % 2;
            }
            else if(str[i]== 'i'){
                vowelCnt[2]= (vowelCnt[2]+1) % 2;
            }
            else if(str[i]== 'o'){
                vowelCnt[3]= (vowelCnt[3]+1) % 2;
            }
            else if(str[i]== 'u'){
                vowelCnt[4]= (vowelCnt[4]+1) % 2;
            }

        string curr= "";
        for(int j=0; j<5; j++)
        {
            curr+= to_string(vowelCnt[j]);
        }
        
        // if curr state is already found in map.. means this substring from that index again has even vowel cnt..
        if(mp.find(curr) != mp.end())
        {
            ans= max(ans, i- mp[curr]);
        } 
        else
        {
            mp[curr]= i;
        }
      }
    return ans;
    }
};