// TC= O(N^2)

class Solution {
public:
    bool isVowel(char ch)
    {
        return (ch== 'a'|| ch== 'e'|| ch== 'i'|| ch== 'o'|| ch== 'u');
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) 
    {
        unordered_set<string> visited;
        unordered_map<string,string> firstOcc;
        unordered_map<string,string> replacedVowel;

        for(auto &it: wordlist)
        {
            visited.insert(it);
            string lower= it;
            for(char &ch: lower)
            {
                ch= tolower(ch);
            }
            
            if(firstOcc.find(lower) == firstOcc.end()){
                firstOcc[lower]= it;
            }

            // convert all vowels in lowercase string to '*', bcoz we can replace vowel with any vowel
            string star= lower;
            for(int i=0; i<star.size(); i++)
            {
                if(isVowel(star[i]))
                {
                    star[i]= '*';
                }
            }

            // Only set mapping if NOT present already (preserve first word)
            if(replacedVowel.find(star)== replacedVowel.end())
            {
               replacedVowel[star]= firstOcc[lower];
            }
        }    

        vector<string> ans(queries.size(), "");
        int j= 0;

        for(auto it: queries)
        {
            if(visited.count(it))
            {
                ans[j++]= it;
                continue;
            }

            string lower= it;
            for(char &ch: lower)
            {
                ch= tolower(ch);
            }

            if(firstOcc.count(lower))
            {
                ans[j++]= firstOcc[lower];
            }
            else
            {
                for(int i=0; i<lower.size(); i++)
                {
                    if(isVowel(lower[i]))
                    {
                        lower[i]= '*';
                    }
                }

                if(replacedVowel.count(lower))
                {
                    ans[j++]= replacedVowel[lower];
                }
                else
                {
                    ans[j++]= "";
                }
            }
        }
       return ans; 
    }
};