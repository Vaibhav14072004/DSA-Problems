// Approach 1 -> Using stringstream
// TC= O(N)
// SC= O(N)

/*

temp.find(searchWord) == 0 ->> returns the starting position of the substring searchWord in word.
If searchWord is a prefix of word, it will start at position 0

temp.find(searchWord)!= string:: npos is NOT used bcoz it is used when we would check whether searchWord 
exists anywhere in word, not just as a prefix.
*/

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n= sentence.length();
        int w= searchWord.length();
        
        stringstream ss(sentence);
        string temp;
        
        int no= 1;
        while(ss >> temp)
        {
            // temp.find(searchWord)!= string:: npos CANNOT be used here
            if(temp.find(searchWord)== 0)
            {
                return no;
            }
            no++;
        }

        return -1;
    }
};








/*
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int wordIndex = 1; // To track the 1-based index of words
        int i = 0; // Iterator for the sentence

        while (i < sentence.size()) {
            // Find the start of the word
            if (sentence[i] == ' ') {
                i++;
                wordIndex++;
                continue;
            }

            // Check if the current word starts with searchWord
            int k = 0; // Iterator for searchWord
            int start = i; // Mark the start of the word
            while (i < sentence.size() && sentence[i] != ' ' && k < searchWord.size()) {
                if (sentence[i] != searchWord[k]) {
                    break;
                }
                i++;
                k++;
            }

            // If we have matched the entire searchWord, return the current word index
            if (k == searchWord.size()) {
                return wordIndex;
            }

            // Skip the rest of the current word
            while (i < sentence.size() && sentence[i] != ' ') {
                i++;
            }
        }

        // If no prefix match is found
        return -1;
    }
};
*/