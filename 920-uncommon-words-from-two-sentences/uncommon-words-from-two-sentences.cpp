// If vector given hota, then we can directly access word, but in case of string, we use stringstream
// In case of string, streamstream is used to access its words


// Approach 2 -> Using stringstream + unordered_map
// TC= O(3* N)

class Solution{
public:
    vector<string> uncommonFromSentences(string str1, string str2) {
        stringstream ss1(str1);
        unordered_map<string,int> mp;
        string word;

        while(ss1 >> word)
        {
            mp[word]++;
        }
        
        stringstream ss2(str2);
        while(ss2 >> word)
        {
            mp[word]++;
        }
        
        vector<string> ans;
        for(auto it: mp)
        {
            if(it.second== 1)
            {
                ans.push_back(it.first);
            }
        }
      return ans;  
    }
};





// Approach 1 -> Using stringstream + 2 unordered_set
// TC= O(3* N) ->> O(N)

/*

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        stringstream ss1(s1);
        string word;
        
        unordered_set<string> st;
        unordered_set<string> duplicates;
        vector<string> ans;

        while(ss1 >> word)
        {
            if(st.find(word) == st.end())
            {
                st.insert(word);
            }
            else
            {
                duplicates.insert(word);
            }
        }

        stringstream ss2(s2);
        while(ss2 >> word)
        {
            if(st.find(word) == st.end())
            {
                st.insert(word);
            }
            else
            {
                duplicates.insert(word);
            }
        }

        for(string it: st)
        {
            if(duplicates.find(it) == duplicates.end())
            {
                ans.push_back(it);
            }
        }
    return ans; 
    }
};

*/