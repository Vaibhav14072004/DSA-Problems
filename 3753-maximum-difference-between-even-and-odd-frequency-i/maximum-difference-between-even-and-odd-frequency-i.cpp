class Solution {
public:
    int maxDifference(string str) {
        int n= str.length();
        int maxOdd= 0, minEven= n;

        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            mp[str[i]]++;
        }

        for(auto it: mp)
        {
            if(it.second % 2 == 0 && it.second < minEven)
            {
                minEven= it.second;
            }
            else if(it.second% 2 == 1 && it.second > maxOdd)
            {
                maxOdd= it.second;
            }
        }

      return maxOdd-minEven;  
    }
};