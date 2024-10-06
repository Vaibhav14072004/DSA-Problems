// TC= O(M+N)
// SC= O(N+M)

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2)
    {
        // assuming sentence 1 must always greater than sentence2
        if(sentence1.length() < sentence2.length())
        {
            swap(sentence1,sentence2);
        }

        stringstream ss1(sentence1);
        vector<string> vec1;
        string token;

        while(ss1 >> token)
        {
           vec1.push_back(token);
        }

        stringstream ss2(sentence2);
        vector<string> vec2;
        
        while(ss2 >> token)
        {
            vec2.push_back(token);
        }

        int i=0, j= vec1.size()-1;
        int k=0, l= vec2.size()- 1;

        while(k < vec2.size() && vec1[i]== vec2[k])
        {
            i++;
            k++;
        }

        while(k<= l && vec1[j]== vec2[l])
        {
            j--;
            l--;
        }
    
    // if k crosses l , return true
    return k> l;
    }
};