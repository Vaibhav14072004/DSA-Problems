// Ques of strigstream

// Approach 1.2 -> Directly using vec.back() to access last char
// TC= O(N)
// SC= O(N)

class Solution {
public:
    bool isCircularSentence(string sentence) {
        stringstream ss(sentence);
        string word;

        vector<string> vec;
        while(ss >> word)
        { 
           vec.push_back(word);
        }
        
        int n=vec.size();

        // base case -> if only one word, directly compare its first and last
        if(n== 1)
        {
           return vec[0][0]== vec[0].back();
        }

        // compare bikul first to bilkul last character
        if(vec[0][0] != vec[n-1].back())
        {
            return false;
        }
        
        // now start comparing consecutive charcaters, first and last
        for(int i=1; i<n; i++)
        {
            if(vec[i-1].back() != vec[i][0])
            {
                return false;
            }
        }
    return true;
    }
};





// Approach 1.1  -> Beats 14.55 % 
// TC= O(N)
// SC= O(N)

/*

class Solution {
public:
    bool isCircularSentence(string sentence){
        stringstream ss(sentence);
        string word;
        
        vector<string> vec;
        while(ss >> word)
        {
            vec.push_back(word);
        }
        
        int n= vec.size();

        // base case ->> when only one word is present... check for its first and last char
        if(n== 1)
        {
            return vec[0][0]== vec[0][vec[0].size()-1];
        }

        int lastLen= vec[n-1].size();
        
        // check for bilkul first and bilkul last character
        if(n > 1 && vec[0][0] != vec[n-1][lastLen-1])
        {
            return false;
        }
        
        // now check for consecutive words, first and last
        int i=0,j=1;
        while(i< j && j < n)
        {
            char last= vec[i][vec[i].size()-1];
            char first= vec[j][0];

            if(last != first)
            {
                return false;
            }
        i++;
        j++;    
        }

        return true;
    }
};

*/