// Sliding Window Approach
// TC= O(2*N)

class Solution {
public:
    bool isVowel(char ch)
    {
        return (ch== 'a' || ch== 'e' || ch== 'i' || ch== 'o'|| ch== 'u'); 
    }

    long long countOfSubstrings(string word, int k) {
        int n= word.length();
        unordered_map<char,int> mp; 

        // first store the index of next consonant for every index..
        vector<int> nextConsonant(n,n);

        int nextIdx= n;
        for(int i=n-1; i>=0; i--)
        {
            nextConsonant[i]= nextIdx;
            if(!isVowel(word[i]))
            {
                nextIdx= i;
            }
        }

        long long ans= 0;
        int i=0, j= 0, consonant= 0;
        while(j < n)
        {
            if(isVowel(word[j]))
            {
                mp[word[j]]++;
            }
            else
            {
                consonant++;
            }

            // shrink the window if const > k, i++
            while(consonant > k)
            {
                if(isVowel(word[i]))
                {
                    mp[word[i]]--;
                    if(mp[word[i]]== 0)
                    {
                        mp.erase(word[i]);
                    }
                }
                else
                {
                    consonant--;
                }
                i++;
            }
            
            // shrink the window if it mets the condition.. i++ 
            while(mp.size()== 5 && consonant== k)
            {
                ans+= nextConsonant[j]-j;

                if(isVowel(word[i]))
                {
                    mp[word[i]]--;
                    if(mp[word[i]]== 0)
                    {
                        mp.erase(word[i]);
                    }
                }
                else
                {
                  consonant--;
                }
                i++;
            }

            j++;
        }
        return ans;
    }
};