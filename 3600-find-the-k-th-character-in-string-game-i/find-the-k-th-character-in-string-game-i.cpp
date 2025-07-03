class Solution {
public:
    char kthCharacter(int k) {
        string word= "a";

        while(word.length() < k)
        {
            string temp= "";

            for(int i=0; i<word.length(); i++)
            {
               int val= ((word[i]-'a')+1) % 26;
               char ch= val+ 'a';
               temp+= ch;
            }
          word+= temp;  
        }
      return word[k-1]; 
    }
};


/*

class Solution {
public:
    char kthCharacter(int k) {
        string word= "a";

        while(word.size() < k)
        {
            string temp= "";
            for(char ch: word)
            {
                int idx= ch-'a'+1;
                temp+= idx + 'a';
            }
            word= word+temp;
        }

        return word[k-1];
    }
};

*/



