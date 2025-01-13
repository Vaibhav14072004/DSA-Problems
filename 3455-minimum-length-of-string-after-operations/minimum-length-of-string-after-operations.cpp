// Approach 1 

class Solution{
public: 
   int minimumLength(string str){
        int n= str.length();
        
        vector<int> freq(26,0);
        int deleted= 0, ans= n;

        for(int i=0; i<n; i++)
        {
           freq[str[i]-'a']++;
           if(freq[str[i]-'a']== 3)
           {
              freq[str[i]-'a']-= 2;
              deleted+= 2;
           }
        }
      return (ans-deleted);  
   }
};






/*

class Solution {
public:
    int minimumLength(string s){
        int n= s.length();
        int len= n;

        // To store freq of elements..
        unordered_map<int, int> mp;

        for(int i=0; i<n; i++)
        {
            mp[s[i]]++;
        }

        for(int i=0; i<n; i++)
        {
            if(mp.find(s[i]) != mp.end() && mp[s[i]] >=3)
            {
                len-=2;
                mp[s[i]]-= 2;
                
                if(len== 0)
                {
                    return 0;
                }
            }
        }
       return len; 
    }
};

*/