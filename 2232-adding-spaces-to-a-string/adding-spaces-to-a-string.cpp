// TC= O(N)

class Solution {
public:
    string addSpaces(string str, vector<int>& spaces) {
        int n= str.length();
        string ans= "";
        
        int j=0;
        for(int i=0; i<n; i++)
        {
           if(j< spaces.size() && i== spaces[j])
           {
              ans+= ' ';
              j++;
           }
           ans+= str[i];
        }
      return ans;
    }
};