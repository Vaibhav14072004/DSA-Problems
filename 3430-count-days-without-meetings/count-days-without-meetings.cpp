// Approach ->> Using Sorting
// TC= O(N log N)

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n= meetings.size();
        int cnt= 0;

        // base case
        if(meetings.empty()) return days;
        
        // sort meetings in ascending order...
        sort(meetings.begin(),meetings.end());
        
        int prevEnd= 0;
        for(int i=0; i<n; i++)
        {
            int nextStart= meetings[i][0];
            if(prevEnd < nextStart){
                cnt+= (nextStart-prevEnd-1);
            }
           prevEnd= max(prevEnd, meetings[i][1]);
        }

        // ex- [2,6] [3,4]  days= 10, then we must add (days-maxEnd) in answer
        cnt+= days-prevEnd;
      return cnt;  
    }
};

