// Approach 3 -> Space Optimized
// TC= O(N log N) + O(P log P) + O(N* P)
// SC= O(P)

class Solution{
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(),factory.end());

        vector<int> position;
        for(auto it: factory)
        {
            int pos= it[0];
            int cnt= it[1];
            while(cnt--)
            {
                position.push_back(pos);
            }
        }

        int p= position.size();
        int n= robot.size();

        vector<long long> next(p+1,1e18);

        
        // to handle base case ->> if(i>= robot.size()) return 0
        for(int j=0; j<=p; j++)
        {
            next[j]= 0;
        }

        for(int i= n-1; i>=0; i--)
        {
            vector<long long> curr(p+1,1e18);
            for(int j= p-1; j>=0; j--)
            {
               long long include= abs(robot[i]-position[j]) + next[j+1];
               long long exclude= curr[j+1];
               curr[j]= min(include,exclude);    
            }
            next= curr;
        }
        
    return next[0];
    }
};







// Approach 2 -> Bottom Up (Tabulation)
// TC= O(N log N) + O(P log P) + O(N* P)
// SC= O(N* P)

/*

class Solution{
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(),factory.end());
        
        int n= robot.size();
        vector<int> position;

        for(int i=0; i<factory.size(); i++)
        {
            int pos= factory[i][0];
            int cnt= factory[i][1];
            while(cnt--)
            {
                position.push_back(pos);
            }
        }

        int p= position.size();

        // To handle base case -> if(j >= cposition.size()) return 1e18 ->> Showing invalid case
        vector<vector<long long>> dp(n+1, vector<long long> (p+1, 1e18));

        // To handle base case -> if(i >= robot.size()) return 0;
        for(int j=0; j<=p; j++)
        {
            dp[n][j]= 0;
        }
         
        for(int i=n-1; i>=0; i--)
        {
            for(int j=p-1; j>=0; j--)
            {
               long long include= abs(robot[i]-position[j])+ dp[i+1][j+1];
               long long exclude= dp[i][j+1];

               dp[i][j]= min(include,exclude);
            }
        }
       return dp[0][0]; 
    }
};

*/








// Approach 1 -> Top Down (Recursion+ Memoization)
// Using separate vector to stroe all positions

// TC= O(M log M) + O(P log P) + O(M* P) 

/*

class Solution{
public:
    long long solve(int i, int j, vector<int> &robot, vector<int> &position, vector<vector<long long>> &dp)
    {
        // base case
        if(i >= robot.size()){
            return 0;
        }

        // if No more positions left to repair robot, Invalid case
        if(j >= position.size())
        {
            return 1e18;
        }

        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }

        long long include= abs(robot[i]-position[j]) + solve(i+1, j+1, robot, position,dp);

        // In case of Exclude, Move to next position but robot remains same
        long long exclude= 0 + solve(i, j+1, robot, position,dp);

        return dp[i][j]= min(include,exclude);
    } 
    


    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(),factory.end());

        vector<int> position;
        for(int i=0; i<factory.size(); i++)
        {
            int pos= factory[i][0];
            int cnt= factory[i][1];
            while(cnt--){
              position.push_back(pos);
            }
        }
        
        int n= robot.size();
        int p= position.size();
        vector<vector<long long>> dp(n, vector<long long> (p,-1));

        return solve(0,0,robot,position,dp);
    }
};

*/







/* RECURSIVE APPROACH ->> 
   TC= O[2^ (M+N)]

class Solution {
public:
    long long solve(int i, int j, vector<int> &robot, vector<int> &position)
    {
        // base case
        if(i >= robot.size())
        {
            return 0;
        }
        
        // If no more position left to repair robot, this case CANNOT be considered
        if(j >= position.size())
        {
            return 1e18;
        }

        // include (repair the robot at curr position)
        long long include= abs(position[j]-robot[i]) + solve(i+1, j+1, robot,position);

        long long exclude= 0 + solve(i, j+1, robot,position);
        
        return min(include,exclude);
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(),factory.end());
        
        vector<int> position;
        
        // we have fill all positions of factory, so that to skip traversing factory vec in recursive calls...
        for(int i=0; i<factory.size(); i++)
        {
            int pos= factory[i][0];
            int cnt= factory[i][1];
            while(cnt--)
            {
                position.push_back(pos);
            }
        }
      return solve(0,0,robot,position);
    }
};

*/