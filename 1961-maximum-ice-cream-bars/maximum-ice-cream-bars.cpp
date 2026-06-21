class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());

        int i=0,cnt= 0,no= 0;
        while(i< costs.size())
        {
           cnt+= costs[i];
           if(cnt > coins) break;
           i++;
        }

      return i;  
    }
};