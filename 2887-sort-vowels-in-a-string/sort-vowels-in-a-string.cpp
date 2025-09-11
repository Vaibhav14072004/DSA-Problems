// TC= O(N)+ O(N* LOG N)+ O(N)

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