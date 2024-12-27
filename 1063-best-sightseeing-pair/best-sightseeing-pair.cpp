// Approach 3 ->> Max heap instead of prefixMax variable or vector
// TC= O(N log N)

class Solution{
 public: 
    int maxScoreSightseeingPair(vector<int>& values) {
        int n= values.size();

        priority_queue<int> pq;
        pq.push(values[0]);
        
        int maxi= INT_MIN;
        for(int i=1; i<n; i++)
        {
            int prefixMax= pq.top();
            maxi= max(maxi, prefixMax + values[i]-i);
            pq.push(values[i] + i);
        }
    return maxi;
    }
};






// Approach 2.2 ->> Using prefixMax variable instead of prefixMax variable
// TC= O(N)
// SC= O(1)

/*

class Solution{
public: 
    int maxScoreSightseeingPair(vector<int>& values) {
        int n= values.size();
        int maxi= INT_MIN;

        int prefixMax= values[0];
        for(int i=1; i<n; i++)
        {
           maxi= max(maxi, prefixMax + values[i]-i);
           prefixMax= max(prefixMax, values[i]+i);
        }
        return maxi;
    }
};

*/







// Approach 2.1 -> Prefix Maximum
// TC= O(N)
// SC= O(N)

/*

class Solution{
public:  
    int maxScoreSightseeingPair(vector<int>& values) {
        int n= values.size();
   
        vector<int> prefixMax(n);
        prefixMax[0]= values[0];

        for(int i=1; i<n; i++)
        {
           prefixMax[i]= max(prefixMax[i-1], values[i]+i);
        }

        int maxi= INT_MIN;
        for(int j=1; j<n; j++)
        {
            maxi= max(maxi, prefixMax[j-1]+ values[j]-j);
        }
    return maxi;
    }
};

*/






//  ------  TLE --------
// Approach 1 -> Brute Force Approach
// TC= O(N^2)

/*

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n= values.size();
        
        int maxi= INT_MIN;
        for(int i=0; i<n; i++)
        {
            int val= values[i]+i;
            for(int j=i+1; j<n; j++)
            {
               maxi= max(maxi, val+ values[j]-j);
            }
        }   
        return maxi;
    }
};

*/