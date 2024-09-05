// TC= O(N+ M)

// N ->> missing values...
// M ->> given values...

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n){
        int m= rolls.size();

        long long sum= 0;
        for(int i=0; i<m; i++)
        {
            sum+= rolls[i];
        }

        int sumN= mean*(m+n) - sum;

        if(sumN < n || sumN > n*6)
        {
            return {};
        }
    
    // initilaize equally... 
        vector<int> ans(n, sumN/n);
    
    // if remainder left.. then put 1 ...
        int rem= sumN % n;
        for(int i=0; i<rem; i++)
        {
           ans[i]++;  
        }
    
    return ans;
    }
};




/*

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {

        int m=rolls.size();
        vector<int> res;

        int sum=0;
        for(int roll: rolls){
            sum+=roll;
        }

        int required = (m+n)*mean-sum;

        if((n*6 < required) || (n>required)){   // No valid answer so return empty vector
            return res;
        }

        while(required > 0){
            n--;
            if(required-6 >= n){
                required-=6;
                res.push_back(6);
            }
            else{
                res.push_back(required-n);
                required=n;
            }
        }
        
        return res;
    }
};

*/