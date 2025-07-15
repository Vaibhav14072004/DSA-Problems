class Solution {
public:
    bool isValid(string word)
    {
        int n= word.length();
        if(n < 3) return false;
        
        int vowel= 0, consonant= 0, chars= 0;
        for(int i=0; i<n; i++)
        {
            int ascii= word[i];
            if((ascii >= 65 && ascii <= 90) || ascii >= 97 && ascii <= 122)
            {
               if(word[i]== 'a' || word[i]== 'e' || word[i]== 'i' || word[i]=='o' || word[i]=='u' ||     word[i]=='A' || word[i]=='E' || word[i]=='I' || word[i]=='O' || word[i]=='U'){
                   vowel++; 
               }
               else{
                consonant++;
               }
               chars++;
            }

            // ascii value of digits is 48 to 57
            else if(ascii >= 48 && ascii <= 57)
            {
                chars++;
            }
            else
            {
                return false;
            }
        }
      return vowel >= 1 && consonant >= 1 && chars >= 3;  
    }
};