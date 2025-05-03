// Approach 2 -> Using map
// TC= O(2*N)

class Solution{
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n= tops.size();

        int maxi= -1, maxFreq= -1;
        unordered_map<int,int> mp;
        
        for(int i=0; i<n; i++)
        {
            mp[tops[i]]++;
            mp[bottoms[i]]++;
            if(mp[tops[i]] > maxFreq)
            {
                maxFreq= mp[tops[i]];
                maxi= tops[i];
            }

            if(mp[bottoms[i]] > maxFreq)
            {
                maxFreq= mp[bottoms[i]];
                maxi= bottoms[i];
            }
        }

        if(maxFreq < n) return -1;

        int cnt1= 0, cnt2= 0;
        for(int i=0; i<n; i++)
        {
            if(tops[i] != maxi && bottoms[i] != maxi)
            {
                return -1;
            }
            else if(tops[i] != maxi){
                cnt1++;
            }
            else if(bottoms[i] != maxi){
                cnt2++;
            }
        }
     return min(cnt1,cnt2);   
    }
};





// Approach 1 -> Brute Force Approach -> Try for all possible values (1 to 6)
// TC= O(6*N)

/*

class Solution{
public:
    int solve(int val,vector<int> &tops, vector<int> &bottoms, int n)
    {
        int cnt1= 0, cnt2= 0;
        for(int i=0; i<n; i++)
        {
            if(tops[i] != val && bottoms[i] != val){
                return -1;
            }
            else if(tops[i] != val){
                cnt1++;
            }
            else if(bottoms[i] != val){
                cnt2++;
            }
        }
     return min(cnt1,cnt2);
    }


   int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n= tops.size();
        int mini= INT_MAX;

        for(int i=1; i<=6; i++)
        {
            int ans= solve(i,tops,bottoms,n);
            if(ans != -1)
            {
                mini= min(mini,ans);
            }
        }

        if(mini== INT_MAX){
            return -1;
        }
    return mini;
   }
};

*/






//  ---- WRONG APPROACH  -----
/*
------------------------------------
tops = [1,2,3,4,6]
bottoms = [6,6,6,6,5]

Wrong Output= -1
Expected = 1
----------------------------------

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n= tops.size();

        if(n < 2){
            return -1;
        }

        int val= -1;
        if(tops[0]== bottoms[1]){
            val= tops[0];
        }

        if(tops[1]== bottoms[0]){
            val= tops[1];
        }

        if(val== -1)
        {
            return -1;
        }
        
        int cnt1= 0, cnt2= 0;
        for(int i=0; i<n; i++)
        {
            if(tops[i]== val){
                cnt1++;
            }
            if(bottoms[i]== val)
            {
                cnt2++;
            }
        }
    
    int ans= -1;
    if(cnt1 <= cnt2)
    {
        ans= min(cnt1, n-cnt2);
    }
    else
    {
        ans= min(cnt2, n-cnt1);
    }
return ans;
    }
};

*/