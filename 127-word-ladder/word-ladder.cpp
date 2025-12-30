// Approach -> Using BFS
// TC= O(W* N* 26)

// Trying out every combination for every char of given word.. 
// changing it from 'a' to 'z'
// and checking whether it is present in set or NOT

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        // base case
        if(beginWord== endWord) return 1;

        queue<pair<string,int>> q;
        q.push({beginWord,1});

        unordered_set<string> st(wordList.begin(),wordList.end());

        // Queue will run atmost W times (size of wordList) times -> TC= O(W)
        while(!q.empty())
        {
            string word= q.front().first;
            int level= q.front().second;
            q.pop();
            
            // if we have reached the endWord, directly return level
            if(word== endWord) return level;

           // TC= O(N* 26)
           for(int i=0; i<word.size(); i++)
           {
               char ch= word[i];
               for(int j=0; j<26; j++)
               {
                   word[i]= (j+'a');
                   
                   // check if this word exists in set, put it in queue & erase it from queue
                   if(st.count(word)) 
                   {
                       q.push({word,level+1});
                       st.erase(word); 
                   }  
               }
               word[i]= ch; // make it original
           }  
        }

    // if it is NOT possible
    return 0;
    }
};