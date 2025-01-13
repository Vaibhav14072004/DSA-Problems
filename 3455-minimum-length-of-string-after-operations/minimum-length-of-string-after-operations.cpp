// Approach 2

class Solution{
public: 
   int minimumLength(string str){
        int n= str.length();
        
        vector<int> freq(26,0);
        for(int i=0; i<n; i++)
        {
            freq[str[i]-'a']++;
        }
        
        int ans= 0;
        for(int i=0; i<26; i++)
        {
            if(freq[i]== 0)
            {
                continue;
            }

            // if freq is odd, add 1 
            else if(freq[i] % 2 == 1)
            {
               ans+= 1;
            }

            // if freq is even, add 2 
            else
            {
                ans+= 2;
            }
        }
    return ans;
   }
};





// Approach 1 

/*

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

*/





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