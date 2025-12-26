// Approach 2 -> 
// TC= O(N)

class Solution{
  public: 
    int bestClosingTime(string &customers)
    {
        int n= customers.size();
        vector<int> cntN(n,0);

        int cnt= 0;
        for(int i=0; i<n; i++)
        {
            if(customers[i]== 'N') cnt++;
            cntN[i]= cnt;
        }
         
        vector<int> cntY(n,0);
        cnt= 0;

        for(int i=n-1; i>=0; i--)
        {
            if(customers[i]== 'Y') cnt++;
            cntY[i]= cnt;
        }

        int mini= cntY[0];
        int minHr= 0;


        for(int i=1; i<n; i++)
        {
            int temp= cntN[i-1] + cntY[i];
            if(temp < mini)
            {
                mini= temp;
                minHr= i;
            }
        }

        if(cntN[n-1] < mini)
        {
            mini= cntN[n-1];
            minHr= n;
        }

    return minHr;
    }
};




// ----- TLE --------
// Approach 1 -> Brute Force Approach
// TC= O(N^2)

/*

class Solution {
public:
    int bestClosingTime(string customers) 
    {
        int n= customers.size();
        int mini= INT_MAX;
        int minHr= INT_MAX;

        for(int i=0; i<= n; i++)
        {
            // start from i-1 till >= 0 to check no of 'N'
            int cnt= 0;
            for(int j=i-1; j>=0; j--)
            {
                if(customers[j]== 'N') cnt++;
            }

            // start from i and check no of 'Y'
            for(int j=i; j<n; j++)
            {
                if(customers[j]== 'Y') cnt++;
            }

            if(cnt < mini)
            {
                mini= cnt;
                minHr= i;
            }
        }
      return minHr;  
    }
};

*/