// Approach 2 -> Using str.find()
// TC= O(N^2)


class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n= words.size();
        int prefLen= pref.length();
        int cnt= 0;
        
        for(int i=0; i<n; i++)
        {
            // .find() return the index where the pref length is found..
           if(words[i].find(pref)== 0)
           {
              cnt++;
           }
        }

      return cnt;  
    }
};







// Approach 1 -> Using str.substr()
// TC= O(N^2)

/*

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n= words.size();
        int prefLen= pref.length();
        int cnt= 0;
        
        for(int i=0; i<n; i++)
        {
           if(words[i].substr(0,prefLen)== pref)
           {
              cnt++;
           }
        }

      return cnt;  
    }
};

*/