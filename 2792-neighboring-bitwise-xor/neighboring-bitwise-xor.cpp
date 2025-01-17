// Approach 1 ->> XOR is Commutative in nature
// TC= O(2*N)
// SC= O(N)

/*
If (a^c)= b, then (a^b)= c, also (b^c)= a
Therefore instead of taking (original[i] ^ original[i+1])= derived[i] 
we can also write (original[i] ^ derived[i])= original[i+1] 

There will be 2 Cases...
1. original[0]= 0
2. original[0]= 1

AND ALSO Check the XOR of last and first element of original, it should be equal to derived
*/

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n= derived.size();

        vector<int> original(n);
        
        // Case 1 -> first element of original vector should be 0

        original[0]= 0;
        for(int i=0; i<n-1; i++)
        {
            original[i+1]= original[i] ^ derived[i];
        }

        if(derived[n-1]== (original[n-1] ^ original[0]))
        {
            return true;
        }

        // Case 2 -> first element of original vector should be 1

        original[0]= 1;
        for(int i=0; i<n-1; i++)
        {
            original[i+1]= (original[i] ^ derived[i]);
        }

        if(derived[n-1]== (original[n-1] ^ original[0]))
        {
            return true;
        }
    return false;
    }
};