// Approach 2 -> Using 26 size freq (WITHOUT Sorting)
// TC= O(N* (M+26))

class Solution{
  public: 
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mp;

        for(string it: strs)
        {
            vector<char> temp(26,0);
            for(char ch: it)
            {
                temp[ch-'a']++;
            }

            string sortedString= "";
            for(int i=0; i<26; i++)
            {
                while(temp[i]-- > 0) sortedString+= (i+'a');
            }

            mp[sortedString].push_back(it);
        }

        for(auto it: mp)
        {
            ans.push_back(it.second);
        }
      return ans;  
    }
};






// Approach 1 -> Using unordered_map + Sorting
// TC= O[N* (m* log m)]

/*

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        
        unordered_map<string,vector<string>> mp;
        for(auto it: strs)
        {
            string temp= it;
            sort(temp.begin(),temp.end());
            mp[temp].push_back(it);
        }

       for(auto it: mp)
       {
           ans.push_back(it.second);
       } 
     return ans;  
    }
};

*/