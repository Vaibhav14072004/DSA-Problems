class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers){

        int n= customers.size();
        double time= customers[0][0];
        double ans= 0;

        for(auto it: customers)
        {
            // to handle the case where there is time lag ... curr time is 14 but order comes on time= 20 
            time= max(time, (double)it[0]);

            time+= it[1];
            ans+= time - it[0];
        }

    return ans/n;
    }
};