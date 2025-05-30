// Approch 4 -> Using vector of size- 100 bcoz dominoes[i] can be max- 9 
//    10* a + b =>> 90+9 ->> 99

// TC= O(N)
// SC= O(100) -> O(1)

class Solution{
 public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes)
    {
        int n= dominoes.size();
        int cnt= 0;
        vector<int> vec(100,0);

        for(int i=0; i<n; i++)
        {
            int a= dominoes[i][0];
            int b= dominoes[i][1];
            if(a > b)
            {
                swap(a,b);
            }

            int num= 10*a+ b;
            cnt+= vec[num];
            vec[num]++;
        }
      return cnt;  
    }
};







// Approach 3 -> Using unordered_map
// TC= O(N)

/*
class Solution{
 public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes)
    {
        int n= dominoes.size();
        int cnt= 0;

        unordered_map<string,int> mp;
        for(int i=0; i<n; i++)
        {
            int a= dominoes[i][0];
            int b= dominoes[i][1];
            if(a > b)
            {
              swap(a,b);
            }

            string temp= to_string(a)+ "_"+ to_string(b);
            cnt+= mp[temp];
            mp[temp]++;
        }
     return cnt;   
    }
};

*/







// Approach 2 -> Using ordered map (map<pair<int,pair<int,int>>> mp) 
// We cannot use pair<int,int> in unordered_map

// TC= O(N* log N)

/*
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

*/






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