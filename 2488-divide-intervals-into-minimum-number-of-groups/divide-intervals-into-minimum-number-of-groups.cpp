// Approach 2 -> 2 Pointers -> Same as Min platforms Needed Ques...
// Whenever we have to find only number, we can use this approach

// TC= O(2*N log N) + O(2*N) ->> O(N log N)

class Solution{
public:
   int minGroups(vector<vector<int>>& intervals) {
        int n= intervals.size();
        
        vector<int> arrival, dept;
        for(auto it: intervals)
        {
            arrival.push_back(it[0]);
            dept.push_back(it[1]);
        }
        
        // Sort arrival and dept vectors..
        sort(arrival.begin(), arrival.end());
        sort(dept.begin(), dept.end());
        
        int i= 1, j= 0;
        int platformNeeded= 1, maxi= 1;

        while(i< n && j < n)
        {
            // in case of overlap..
            if(arrival[i] <= dept[j])
            {
                platformNeeded++;
                i++;
            }
            else
            {
                platformNeeded--;
                j++;
            }
            
            maxi= max(maxi, platformNeeded);
        }
    return maxi;
    }
};







// Approach 1.2 -> Priority_queue to store ending time of each separate group
// TC= O(2* N log N) 

/*

class Solution{
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n= intervals.size();

        sort(intervals.begin(), intervals.end());
        
        // min heap to get minimum out of all ending times of each separate group
        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto it: intervals)
        {
            int arrival= it[0];
            int dept= it[1];
            
            // in case of NOT overlapping
            if(!pq.empty() && pq.top() < arrival)
            {
                pq.pop();
                pq.push(dept);
            }

            // in case of overlapping..
            else
            {
                pq.push(dept);
            }
        }
    return pq.size();
    }
};

*/








// Approach 1.1 -> Brute Force Approach
// Using vec to store ending time of each interval...

// TC= O(N^2) + O(N log N) ->> O(N^2)

/*

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n= intervals.size();
         
        sort(intervals.begin(),intervals.end());
        
        // To store ending times of each separate groups..
        vector<int> vec;
        
        for(auto it: intervals)
        {
            int arrival= it[0];
            int dept= it[1];
            bool flag= false;

            for(int i=0; i<vec.size(); i++)
            {
                // separate group needed...
                if(vec[i] < arrival)
                {
                    vec[i]= dept;
                    flag= true;
                    break;
                }
            }

            if(!flag)
            {
                vec.push_back(dept);
            }
        }
      return vec.size();  
    }
};

*/