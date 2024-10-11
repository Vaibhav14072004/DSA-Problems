// Approach 2 -> Using 2 Priority_queue -> One for storing the occupied chairs, other for storing availChair
// TC= O(N log N)

class Solution{
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n= times.size();
        int targetArrival= times[targetFriend][0];

        sort(times.begin(),times.end());
        
        // {departure, chairNo}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> occupied;

        // {chair No}
        priority_queue<int, vector<int>, greater<int>> availChair;
        
        // chairNo shows the next avaibale chair on which we friend can sit..
        int chairNo= 0;

        for(auto it: times)
        {
            int arrival= it[0];
            int departure= it[1];

            while(!occupied.empty() && occupied.top().first <= arrival)
            {
                 availChair.push(occupied.top().second);
                 occupied.pop();
            }
            
            if(availChair.empty())
            {
                occupied.push({departure,chairNo});

                if(arrival== targetArrival){
                   return chairNo;
                }
                chairNo++;
            }
            
            // if any other smaller chair is available...
            else
            {
               int smallestAvailChair= availChair.top();
               availChair.pop();

               if(arrival== targetArrival){
                 return smallestAvailChair;
               }

               occupied.push({departure,smallestAvailChair});
            }
        }
    return -1;
    }
};






// Approach 1 -> Brute Force Approach
// TC= O(N^2)

//  Take a chair vector and traverse it every time.. store departure time in it,
// if dept <= arrival[i], store the new departure time in that chair

/*

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n= times.size();
        
        // arrival times of all friends are distinct..
        int targetArrival= times[targetFriend][0];

        sort(times.begin(),times.end());
        
        // store the departure time in each chair[i]
        vector<int> chairs(n,-1);

        for(auto it: times)
        {
            int arrival= it[0];
            int departure= it[1];

            for(int i=0; i<n; i++)
            {
                if(chairs[i] <= arrival)
                {
                    chairs[i]= departure;

                    if(arrival== targetArrival)
                    {
                        return i;
                    }
                    // no need to traverse further.. once we have stored the dept in corresponding chair
                    break;   
                }
            }
        }
    return -1;  
    }
};

*/