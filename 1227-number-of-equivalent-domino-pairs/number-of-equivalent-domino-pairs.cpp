// Approach 2 -> Using ordered map (map<pair<int,pair<int,int>>> mp) 
// We cannot use pair<int,int> in unordered_map

// TC= O(N* log N)

class Solution{
 public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes)
    {
        int n= dominoes.size();
        int cnt= 0;

        // ordered map for storing {{a,b}, freq}
        map<pair<int,int>, int> mp;
        
        for(int i=0; i<n; i++)
        {
            int a= dominoes[i][0];
            int b= dominoes[i][1];
            if(a > b){
              swap(a,b);
            }
            
           cnt+= mp[{a,b}];
           mp[{a,b}]++;

           // or we can also use val   =>> (val)*(val-1)/2 
           //                       C2 

        }
    return cnt;
    }
};




// Approach 1 -> Brute Force Approach
// TC= O(N^2)

/*

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n= dominoes.size();
        int cnt= 0;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(dominoes[i][0]== dominoes[j][0] && dominoes[i][1]== dominoes[j][1] ||
                  dominoes[i][0]== dominoes[j][1] && dominoes[i][1]== dominoes[j][0])
                  {
                     cnt++;
                  }
            }
        }
      return cnt;  
    }
};

*/