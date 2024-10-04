// Approach 2 ->USing vector -> Best Approach
// TC= O(2*N) ->> O(N)
// SC= O(1)

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n= skill.size();

        vector<int> freq(1001,0);
        long long totalSum= 0;

        for(int i=0; i<n; i++)
        {
            totalSum+= skill[i];
            freq[skill[i]]++;
        }

        // base case
        if(totalSum % (n/2) != 0)
        {
            return -1;
        }
        
        long long chemistry= 0;
        long long teamSize= totalSum/(n/2);

        for(int i=0; i<n; i++)
        {
            int rem= teamSize-skill[i];
            if(freq[rem] <= 0)
            {
               return -1;
            }

            chemistry+= skill[i]* (rem);
            freq[rem]--;
        }

     // bcoz we have taken pairs (3,2) (2,3) twice into consideration..   
     return chemistry/2; 
    }
};







// Approach 1.1 -> Using unordered_map
// TC= O(2* N) ->> O(N)
// SC= O(N)

/*
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n= skill.size();

        unordered_map<int,int> mp;
        long long totalSum= 0;

        for(int i=0; i<n; i++)
        {
            totalSum+= skill[i];
            mp[skill[i]]++;
        }
        
        long long teamSize= totalSum/(n/2);

        // base case... 
        if(totalSum % (n/2) != 0)
        {
           return -1;
        }

        long long chemistry= 0;
        for(auto it: mp)
        {
            int skill= it.first;
            int freq= it.second;

            while(freq >0)
            {
                int rem= teamSize-skill;

                // first handle the case when skill== (teamSize- skill)
                if(rem== skill)
                {
                    if(freq % 2 != 0)
                    {
                       return -1;
                    }

                    mp[rem]-= 2;
                    freq-= 2;
                    chemistry+= rem*rem;
                }
                
                // if skill != (teamSize-skill)
                else 
                {
                    if(mp[rem] <= 0)
                    {
                        return -1;
                    }
                    
                    chemistry+= skill* rem;
                    mp[rem]--;
                    mp[skill]--;
                    freq--;
                }  
            }
        }
     return chemistry;
    }
};

*/







// Approach 2 -> Sorting
// TC= O(N log N) + O(N) ->> O(n log n)

/*

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n= skill.size();

        // base case..
        if(n== 2){
            return skill[0]*skill[1];
        }
        
        // sort in ascending order and map elements from first and last..
        sort(skill.begin(), skill.end());

        long long chemistry= 0;
        int teamSize= skill[0]+ skill[n-1]; 
        
        int i=0, j= n-1;
        while(i <= j)
        {
            int sum= skill[i]+ skill[j];
            if(sum != teamSize){
                return -1;
            }

           chemistry+= skill[i]* skill[j];
           i++;
           j--;
        }
    return chemistry;  
    }
};

*/