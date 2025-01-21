// TC= O(M)

class Solution { 
public:
    long long gridGame(vector<vector<int>>& grid) {
       int m= grid[0].size(); //  columns
       
       long long firstRowSum= 0;
       for(int i=0; i<m; i++)
       {
          firstRowSum+= grid[0][i];
       }

       long long secondRowSum= 0;
       long long miniRobot2Sum= LLONG_MAX;

       for(int i=0; i<m; i++)
       {
           // these points have been taken by robot1, so robot2 will NOT get these points
           firstRowSum-= grid[0][i];

           // robot2 will try to minimize its points..
           long long maxi= max(firstRowSum, secondRowSum);

           miniRobot2Sum= min(miniRobot2Sum, maxi);
           
           // robot2 can collect these points..
           secondRowSum+= grid[1][i];
       }
    return  miniRobot2Sum;
    }
};