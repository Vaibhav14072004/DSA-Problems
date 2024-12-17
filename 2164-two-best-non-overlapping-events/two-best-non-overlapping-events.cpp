// Approach 2 ->> DP + Binary Search (Take/ NotTake)

// TC= O(N log N) + O(3* N* log N)  ->> O(N log N)
// SC= O(N)

class Solution {
public:

// func to calculate upper bound (just >=) of endTime
    int binarySearch(vector<vector<int>> &events, int endTime, int n)
    {
        int start= 0;
        int end= n-1;

        // if not a valid next idx is found, index= n will be handled in base case of solve func
        int idx= n; 
        while(start <= end)
        {
            int mid= start+ (end-start)/2;
            if(endTime < events[mid][0])
            {
                idx= mid;
                end= mid-1;  
            }
            else
            {
                start= mid+1;
            }
        }
        return idx;
    }


    int solve(int index,vector<vector<int>> &events, int cnt, int n, vector<vector<int>> &dp)
    {
        if(index >=n || cnt== 0){
            return 0;
        }

        if(dp[index][cnt] != -1){
            return dp[index][cnt];
        }


        // Take =>> If curr index included ->> find next valid index
        // upper bound (just greater, equal >=) of endTime
        int nextIdx= binarySearch(events, events[index][1], n);

        int take= events[index][2]+ solve(nextIdx, events, cnt-1, n, dp);
      
        // NOT Take...
        int notTake= solve(index+1, events, cnt, n, dp);

        return dp[index][cnt]= max(take,notTake);
    }


    int maxTwoEvents(vector<vector<int>>& events){
        int n= events.size();

        // sort events based on starting point...
        sort(events.begin(),events.end());

        vector<vector<int>> dp(n, vector<int> (3,-1));
        
        // cnt variable, to make sure atmost 2 non overlapping intervals..
        int cnt= 2;
        return solve(0,events,cnt,n,dp);
    }
};









// Approach 1 -> Brute Force Approach 
// TC= O(N^2) + O(N log N) =>> O(N^2)

/*

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n= events.size();

        // sort events based on starting point...
        sort(events.begin(),events.end());
        
        int maxi= INT_MIN;
        for(int i=0; i<n; i++)
        {
            int start= events[i][0];
            int end= events[i][1];
            int val= events[i][2];
            maxi= max(maxi, val); // to handle the case, only 1 element alone will be maximum

            for(int j=0; j<n; j++)
            {
                if(i== j || end >= events[j][0]){
                 continue;
                }

                int newVal= val+events[j][2];
                maxi= max(maxi,newVal);
            }
        }
      return maxi;
    }
};

*/