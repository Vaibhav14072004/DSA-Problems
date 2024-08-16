// TC= O(M)

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays)
    {
        int m= arrays.size();
        int mini= arrays[0][0];
        int maxi= arrays[0].back();
        
        int maxDiff= INT_MIN;

        for(int i=1; i<m; i++)
        {
            int temp= max(maxi- arrays[i][0], arrays[i].back()- mini);
            maxDiff= max(maxDiff, temp);
            mini= min(arrays[i][0], mini);
            maxi= max(arrays[i][arrays[i].size()- 1], maxi);
        }

    return maxDiff;
    }
};








/*  ---- Giving Wrong answer -----    

// TC= O[M* log(2*M)] + O[log(2* M)]  ->> bcoz we have atmax 2*m elements inpriority_queue
// Overall TC= O(M* log M)

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int m= arrays.size();
        
    // max heap.... to get max element at top
    // pair of {element, index} bcoz we want min and max element from different arrays 

        priority_queue<pair<int,int>> pq;

        for(int i=0; i<m; i++)
        {
            int start= arrays[i][0];
            int end= arrays[i][arrays[i].size()- 1];

            pq.push({start,i});
            pq.push({end,i});
        }

        int maxi= pq.top().first;
        int idx1= pq.top().second;
        pq.pop();
        

        int mini= INT_MAX;
        while(!pq.empty())
        {
            int minVal= pq.top().first;
            int idx2= pq.top().second;
            pq.pop();

            if(idx2 != idx1)
            {
                mini= min(mini, minVal);
            }
        }

       return maxi-mini; 
    }
};

*/



