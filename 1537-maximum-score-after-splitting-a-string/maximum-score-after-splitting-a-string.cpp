// Approach 1 -> Using seperate vec for cnt of zeroes on left side and ones on right side
// TC= O(3*N)

class Solution {
public:
    int maxScore(string str) {
        int n= str.length();

        vector<int> leftZeroes(n,0);
        if(str[0]== '0')
        {
            leftZeroes[0]= 1;
        }

        for(int i=1;i<n;i++)
        {
            if(str[i]== '0')
            {
                leftZeroes[i]= leftZeroes[i-1]+ 1; 
            }
            else
            {
                leftZeroes[i]= leftZeroes[i-1];
            }
        }

        vector<int> rightOnes(n,0);
        if(str[n-1]== '1')
        {
            rightOnes[n-1]= 1;
        }

        for(int i=n-2; i>=0; i--)
        {
            rightOnes[i]= rightOnes[i+1] + (str[i]-'0');
        }

        int maxi= 0;
        for(int i=1; i<n; i++)
        {
            maxi= max(maxi, leftZeroes[i-1]+ rightOnes[i]);
        }
      return maxi;  
    }
};