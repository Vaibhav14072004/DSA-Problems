// TC= O(N)

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n= answers.size();
        int rabbits= 0;
        unordered_map<int,int> mp;

        for(int i=0; i<n; i++)
        {
            mp[answers[i]]++;
        }

        for(auto it: mp)
        {
            int x= it.first;
            int freq= it.second;

            int temp= 1+x;
            int groups= ceil((double)freq/temp); 

            rabbits+= groups* temp;
        }
      return rabbits;  
    }
};