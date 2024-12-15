/*
Brute Force Approach ->>> of assigning students that have smallest ratio at
every step would give wrong answer... Ex- {(1,2),(3,5),(2,2)}    extra= 2

Initial Ratio-> 0.5,  0.6,  1

Now adding extar 1 to class 0 which has smallest ratio
Ratio 1 ->>  0.66667,  0.60000,  1.00000

Now adding 1 left extra to class 1
Ratio2 ->> 0.66667, 0.66667,  1.00000

Avg ratio = 0.7778   which is -<<--incorrect ->>
-----------------------------------------------------------------

Rather we would assign, extra student to each class at every step, and see the
corresponding difference of (new ratio-prev ratio), we would assign extra
student to that class having greater value of difference
*/

// Approach ->> Using max heap to get max diff at top after evrry iteration
// TC= O(k* log N)

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();

        // max heap to get max difference at top after every iteration..
        priority_queue<pair<double,int>> pq;

            for(int i = 0; i < n; i++)
            {
                double ratio= (double)classes[i][0] / classes[i][1];
                double newRatio= (double)(classes[i][0] + 1) / (classes[i][1] + 1);
                double diff= newRatio-ratio;                
                pq.push({diff,i});
            }

                while(extraStudents--)
                {
                    double maxDiff= pq.top().first;
                    int index= pq.top().second;
                    pq.pop();

                    classes[index][0]++;
                    classes[index][1]++;
      
                    double ratio= (double) classes[index][0]/classes[index][1];
                    double newRatio= (double) (classes[index][0]+1)/(classes[index][1]+1);
                    double diff= newRatio-ratio;
                    pq.push({diff,index});
                }
        
        double ans= 0.0;
        for(int i=0; i<n; i++)
        {
            ans+= (double)classes[i][0]/classes[i][1];
        }
    return ans/n;
    }
};




// ----- Giving TLE -------
// Without using priority_queue
// TC= O(N*k)

/*

 class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();

        while(extraStudents--)
        {
            double maxDiff= 0.0;
            int index= -1;

            for(int i = 0; i < n; i++)
            {
                double ratio = (double)classes[i][0] / classes[i][1];
                double newRatio =(double) (classes[i][0] + 1) /
(classes[i][1]+1);

                if(maxDiff < (newRatio-ratio))
                {
                    maxDiff= newRatio-ratio;
                    index= i;
                }
            }

            classes[index][0]++;
            classes[index][1]++;
            maxDiff= 0.0;
        }

        double avgRatio = 0.0;
        for(int i=0; i<n; i++)
        {
            avgRatio+= (double)classes[i][0]/classes[i][1];
        }
    return avgRatio/n;
    }
};

*/
