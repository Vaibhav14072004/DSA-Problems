// Approach 1 -> Using unordered_map
// TC= O(2* N) ->> O(N)
// SC= O(N)

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

        // base case... if only one team can be formed
        if(n == 2)
        {
           return skill[0]*skill[1];
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