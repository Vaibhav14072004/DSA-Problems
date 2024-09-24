// Approach 1 -> Using set

/*
Store all prefixes of every number of arr1 in set.....
Now run a loop on arr2 and find all prefixes of every number of arr2, if that exists in set, calculate max len of prefix found till now....

**** To find no of digits of a number ->> [log10 (num) + 1]
*/

// TC= O(N*d) + O(M*d) where d -> digits of no -> [1 + log10(num)]

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;
        
        // Insert all prefixes of every no of arr1 in set...
        for(int i=0; i<arr1.size(); i++)
        {
            int val= arr1[i];
            while(val > 0)
            {
                st.insert(val);
                val= val/10;
            }
        }
        
        // Now check for all prefixes of every no of arr2... if that exists update maxLen
        int maxLen= 0;
        for(int i=0; i<arr2.size(); i++)
        {
            int val= arr2[i];
            
            // now check all prefixes of curr no....
            while(!st.count(val) && val > 0)
            {
                val= val/10;
            }
            
            // if this prefix found in set... update maxLen with (no of digits of this prefix) ->[log10 (n) + 1]
            if(val > 0)
            {
                maxLen= max(maxLen, static_cast<int>(log10 (val) + 1));
            }
        }
    return maxLen;
    }
};