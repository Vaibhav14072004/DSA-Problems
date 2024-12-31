// Approach 1 (DP) =>> TOP DOWN =>> Reursion + Memoization

class Solution{
public:

int solve(vector<int> &days, vector<int> &costs,vector<int> &dp, int index){

int n= days.size();

// base case
if(index >=n){
    return 0;
}

if(dp[index] !=-1){
    return dp[index];
}

int option2,option3;

// for 1 day =>> costs[0]
int option1= costs[0] + solve(days, costs, dp, index+1);

// for 7days =>> costs[1]
for(int i=index; i<n && days[i] < days[index]+ 7; i++){

    option2= costs[1] + solve(days, costs, dp, i+1);
}

// for 30 days=>> costs[2]
for(int i= index; i<n && days[i] < days[index] + 30; i++){

    option3= costs[2] + solve(days,costs,dp, i+1);
}

dp[index]= min(option1, min(option2, option3));
return dp[index];
}

int mincostTickets(vector<int> &days, vector<int> &costs){
int n= days.size();
vector<int> dp(n+1, -1);
return solve(days, costs, dp, 0);
}
};




/*  Recursion =>> Would give TLE(Time Limit Exceeded)

class Solution {
public:

int solve(vector<int> &days, vector<int> &costs, int index){
int n= days.size();

// base case
if(index >= n){
return 0;  
}

// for 1 day pass =>> cost[0]
int option1= costs[0] + solve(days, costs, index+1);

// for 7 days =>> cost[1]
int option2= INT_MAX;
for(int i=index; i<n && days[i] < days[index] + 7; i++){
 
    option2= min(option2, costs[1] + solve(days, costs, index+1));
}

// for 30 days =>> costs[2]
int option3= INT_MAX;
for(int i=index; i<n && days[i] < days[index] + 30; i++){

     option3= min(option3, costs[2] + solve(days, costs, index+1));
}

int ans= min(option1, min(option2, option3));
return ans;
}


 int mincostTickets(vector<int>& days, vector<int>& costs) {
           return solve(days, costs, 0);  
    }
};

*/