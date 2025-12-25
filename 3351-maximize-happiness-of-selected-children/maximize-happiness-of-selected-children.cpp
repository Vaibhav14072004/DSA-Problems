// Approach 1 -> Sorting
// TC= O(N* log N)+ O(N)

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k)
    {
        int n= happiness.size();
        sort(happiness.rbegin(),happiness.rend());

        int cnt= 0;
        long long ans= 0;
        for(int i=0; i<k; i++)
        {
           int temp= (happiness[i]-cnt);
           if(temp > 0) ans+= temp;
           cnt++;
        }
      return ans;  
    }
};