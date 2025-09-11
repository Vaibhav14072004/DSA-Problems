// Approach 3.2 ->  Without sorting, storing freq in unordered_map,using while loop
// TC= O(N)

class Solution {
public:
    string sortVowels(string str) {
        int n= str.length();

        // sorted order of vowels acc to ascii codes
        string vowels= "AEIOUaeiou";

        unordered_map<char,int> mp;
        for(int i=0; i<n; i++)
        {
            if(str[i]== 'A' || str[i]== 'E' || str[i]== 'I' || str[i]== 'O' || str[i]== 'U' ||
               str[i]== 'a' || str[i]== 'e' || str[i]== 'i' || str[i]== 'o' || str[i]== 'u')
               {
                  mp[str[i]]++;
               }
        }
        
        int j=0;
        for(int i=0; i<n; i++)
        {
            if(str[i]== 'A' || str[i]== 'E' || str[i]== 'I' || str[i]== 'O' || str[i]== 'U' ||
               str[i]== 'a' || str[i]== 'e' || str[i]== 'i' || str[i]== 'o' || str[i]== 'u')
               {
                   while(j < vowels.size() && mp[vowels[j]] == 0)
                   {
                      j++;
                   }
                   str[i]= vowels[j];
                   mp[vowels[j]]--;
               }
        }
    return str;
    }
};







// Approach 3.1 -> Without sorting, storing freq in unordered_map, using if loop
// TC= O(N)

/*

class Solution {
public:
    string sortVowels(string str) {
        int n= str.length();

        // sorted order of vowels acc to ascii codes
        string vowels= "AEIOUaeiou";

        unordered_map<char,int> mp;
        for(int i=0; i<n; i++)
        {
            if(str[i]== 'A' || str[i]== 'E' || str[i]== 'I' || str[i]== 'O' || str[i]== 'U' ||
               str[i]== 'a' || str[i]== 'e' || str[i]== 'i' || str[i]== 'o' || str[i]== 'u')
               {
                  mp[str[i]]++;
               }
        }
        
        int j=0;
        for(int i=0; i<n; i++)
        {
            if(str[i]== 'A' || str[i]== 'E' || str[i]== 'I' || str[i]== 'O' || str[i]== 'U' ||
               str[i]== 'a' || str[i]== 'e' || str[i]== 'i' || str[i]== 'o' || str[i]== 'u')
               {

                  if(mp[vowels[j]] > 0)
                  {
                      str[i]= vowels[j];
                      mp[vowels[j]]--;
                      if(mp[vowels[j]]== 0)
                      {
                          j++;
                      }
                  }
                  else
                  {
                     j++;
                     i--; 
                  }
               }
        }
    return str;
    }
};

*/







// Approach 2 -> Using only 1 vector, Changing the given string, 
// TC= O(N)+ O(N* log N) + O(N)

/*

class Solution {
public:
    string sortVowels(string str) {
        int n= str.length();
        vector<char> vowels;

        for(int i=0; i<n; i++)
        {
            if(str[i]== 'A' || str[i]== 'E' || str[i]== 'I' || str[i]== 'O' || str[i]== 'U' ||
               str[i]== 'a' || str[i]== 'e' || str[i]== 'i' || str[i]== 'o' || str[i]== 'u')
               {
                  vowels.push_back(str[i]);
               }
        }

        sort(vowels.begin(),vowels.end());
        int j=0;

        for(int i=0; i<n; i++)
        {
            if(str[i]== 'A' || str[i]== 'E' || str[i]== 'I' || str[i]== 'O' || str[i]== 'U' ||
               str[i]== 'a' || str[i]== 'e' || str[i]== 'i' || str[i]== 'o' || str[i]== 'u')
               {
                  str[i]= vowels[j++];
               }
        }
    return str;
    }
};

*/






// Approach 1
// TC= O(N)+ O(N* LOG N)+ O(N)

/*

class Solution {
public:
    string sortVowels(string str) {
        int n= str.length();
        vector<char> vowels;
        vector<int> indexes;

       vector<string> ans(n);
        for(int i=0; i<n; i++)
        {
            if(str[i]== 'A' || str[i]== 'E' || str[i]== 'I' || str[i]== 'O' || str[i]== 'U' ||
               str[i]== 'a' || str[i]== 'e' || str[i]== 'i' || str[i]== 'o' || str[i]== 'u')
               {
                  vowels.push_back(str[i]);
                  indexes.push_back(i);
               }
               else
               {
                 ans[i]= str[i]; 
               }
        }

        sort(vowels.begin(),vowels.end());
        int i=0;
        int len= vowels.size();

        while(i < len)
        {
            int idx= indexes[i];
            ans[idx]= vowels[i];
            i++;
        }
        
        string output= "";
        for(auto it: ans)
        {
            output+= it;
        }
        return output;
    }
};

*/