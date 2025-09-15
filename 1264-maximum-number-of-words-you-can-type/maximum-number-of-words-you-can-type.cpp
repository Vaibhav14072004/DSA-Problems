// TC= O(N)

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int ans=0;

        unordered_set<char> st;
        for(int i=0; i<brokenLetters.size(); i++){
            st.insert(brokenLetters[i]);
        }

        bool flag= true;
        for(int i=0; i<text.size(); i++)
        {
            // if there is start of next char
            if(text[i]== ' ')
            {
                if(flag)
                {
                   ans++;
                }

                // if flag is false,make it true for next word
                flag= true;
                continue;
            }

            else if(st.count(text[i]))
            {
                flag= false;
            }
        }

        // check for last word separately after loop ends.
        if(flag) ans++;
      return ans;  
    }
};