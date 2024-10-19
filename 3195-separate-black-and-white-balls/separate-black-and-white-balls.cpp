// We have to move all 0's to left and all 1's to right..

// Approach 1 -> Count all 1's before 0, add it in ans as we have to do that no of swaps
// TC= O(N)

class Solution{
public:
    long long minimumSteps(string s) {  
        int n= s.length();
        
        long long cnt1= 0, ans= 0;
        for(int i=0; i<n; i++)
        {
            if(s[i]== '1')
            {
                cnt1++;
            }
            else
            {
               ans+= cnt1;
            }
        }
    return ans;
    }
};





/*
// Approach 2 -> Sliding Window
// TC= O(N)

class Solution {
public:
    long long minimumSteps(string s) {
        
        int i = 0;
        int j = s.size()-1;

        long long int ans = 0;

        while(i < j) {

            if(s[i] == '1' && s[j] == '0') {
                swap(s[i], s[j]);
                ans += (j - i);
                i++;
                j--;
            }

            else if(s[i] == '0') {
                i++;
            }

            else if(s[j] == '1') {
                j--;
            }
        }

        return ans;
    }
};

*/