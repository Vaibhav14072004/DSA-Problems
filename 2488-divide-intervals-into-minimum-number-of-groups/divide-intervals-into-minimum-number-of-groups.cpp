// Approach 1.2 -> Priority_queue to store ending time of each separate group
// TC= O(2* N log N) 

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