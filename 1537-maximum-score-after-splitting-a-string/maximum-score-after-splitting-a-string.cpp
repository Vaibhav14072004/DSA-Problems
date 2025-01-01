// Approach 3 ->> 1 Iteration -> only2 varibales 
// TC= O(N)

class Solution{
public:
    int maxScore(string str) {
      int n= str.length();

      int total1= 0;
      for(int i=0; i<n; i++)
      {
          if(str[i]== '1')
          {
             total1++;
          }
      }
      
      int cnt0= 0, maxi= 0;
      for(int i=0; i<n-1; i++)
      {
          if(str[i]== '1')
          {
             total1--; 
          }
          else
          {
             cnt0++;
          }
          maxi= max(maxi, cnt0 + total1);
      }
    return maxi; 
   }
};





// Approach 2 ->> 2 Iterations...
// TC= O(2*N)

/*

class Solution{
public: 
   int maxScore(string str) {
      int n= str.length();

      vector<int> rightOne(n,0);
      rightOne[n-1]= (str[n-1]- '0');

      for(int i=n-2;i>=0; i--)
      {
          rightOne[i]= rightOne[i+1] + (str[i]- '0');
      }
      
      int maxi= 0, cnt= 0;
      if(str[0]== '0') cnt= 1;

      for(int i=1; i<n; i++)
      {
          maxi= max(maxi, cnt+ rightOne[i]);
          if(str[i]== '0'){
            cnt++;
          }
      }
      return maxi;
   }
};

*/








// Approach 1 -> Using seperate vec for cnt of zeroes on left side and ones on right side
// TC= O(3*N)

/*

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

*/