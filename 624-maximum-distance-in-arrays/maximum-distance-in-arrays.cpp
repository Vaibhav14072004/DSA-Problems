// Best Approach 
// TC= O(M)

/*

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

*/






// Approach 2 -> Using 2 heaps (1 Max heap and 1 min heap)
// TC= O(2*M log (2*M))

// Overall TC= O(M* log M)

class Solution{
public:
    int maxDistance(vector<vector<int>>& arrays)
    {
        int m= arrays.size();

     // {element, index}
     priority_queue<pair<int,int>> maxHeap;
     priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;

     for(int i=0; i<m; i++)
     {
        minHeap.push({arrays[i][0], i});
        maxHeap.push({arrays[i].back(), i});
     }

     int maxVal= maxHeap.top().first;
     int idx1= maxHeap.top().second;
     maxHeap.pop();

     int minVal= minHeap.top().first;
     int idx2= minHeap.top().second;
     minHeap.pop();

     if(idx1 != idx2)
     {
        return maxVal-minVal;
     }

     int secondMin= minHeap.top().first;
     int secondMax= maxHeap.top().first;

     return max(maxVal- secondMin, secondMax- minVal);
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



