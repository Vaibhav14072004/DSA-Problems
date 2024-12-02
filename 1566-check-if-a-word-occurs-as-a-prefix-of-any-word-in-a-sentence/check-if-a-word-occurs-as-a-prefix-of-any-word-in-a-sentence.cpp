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
