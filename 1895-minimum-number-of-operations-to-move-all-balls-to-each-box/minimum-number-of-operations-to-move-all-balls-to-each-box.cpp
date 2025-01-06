// Approach 2.1 ->> Calculation sum of prefixSum till i-1 and suffixSum upto till i+1 
// TC= O(N)
// Sc= O(N)

class Solution{
public: 
     vector<int> minOperations(string boxes) {
        int n= boxes.length();
        vector<int> ans(n,0);
        
        // calculate prefix sum...
        vector<int> prefixSum(n,0);
        if(boxes[0]== '1'){
            prefixSum[0]= 1;
        }

        for(int i=1; i<n; i++)
        {
           if(boxes[i]== '1')
           {
              prefixSum[i]+= prefixSum[i-1] + 1;
           }
           else
           {
              prefixSum[i]+= prefixSum[i-1];  
           }
        }
        
        // calculate suffix sum...
        vector<int> suffixSum(n,0);
        suffixSum[n-1]= (boxes[n-1]== '1') ? 1 : 0;

        for(int i=n-2; i>=0; i--)
        {
            if(boxes[i]== '1')
            {
                suffixSum[i]+= suffixSum[i+1]+ 1;
            }
            else
            {
               suffixSum[i]+= suffixSum[i+1];
            }
        }
        
        int leftOps= 0;
        for(int i=0; i<n; i++)
        {
            ans[i]+= leftOps;
            leftOps+= prefixSum[i];
        }

        int rightOps= 0;
        for(int i=n-1; i>=0; i--)
        {
            ans[i]+= rightOps;
            rightOps+= suffixSum[i];
        }
    return ans;  
    }
};







//  ------  TLE ------
// Approach 1.2 ->> Brute Force ->> Using Set
// TC= O[N* (size of set)]

/*

class Solution{
public: 
    vector<int> minOperations(string boxes) {
        int n= boxes.length();
        vector<int> ans(n,0);
        
        // put all those indexes in set, at which boxes[i]= 1
        unordered_set<int> st;
        for(int i=0; i<n; i++)
        {
            if(boxes[i]== '1'){
                st.insert(i);
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int it: st)
            {
                ans[i]+= abs(it-i);
            }
        }
    return ans;
    }
};

*/








//   -----  TLE  --------
// Approach 1.1 ->> Brute Force -> WithOUT using set
// TC= O(N^2)

/*

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n= boxes.length();
        vector<int> ans(n,0);

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(boxes[j]== '1')
                {
                    ans[i]+= abs(i-j);
                }
            }
        }
    return ans;
    }
};

*/