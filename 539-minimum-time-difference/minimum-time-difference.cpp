// TC= O(N) + O(N log N) + O(N) ->> O(N log N)

class Solution {
public:
    int findMinDifference(vector<string>& timePoints)
    {
        vector<int> vec;
        for(string str: timePoints)
        {
            int hr= stoi(str.substr(0,2));
            int min= stoi(str.substr(3,2));
            vec.push_back(60*hr + min);
        }

        sort(vec.begin(), vec.end());
        
        int mini= 1e9;
        int n= vec.size();

        for(int i=1; i<n; i++)
        {
           mini= min(mini, vec[i]- vec[i-1]);
        }

        // Circular property...when crossing over midnight, from 23:50 to 00:15 
        // can be calc as 24*60 -> 1440  so 1440 - (23*60 + 50) + (0*60 + 15) -> 25 mins 

        int circular= 24*60- vec[n-1] + vec[0];
        mini= min(mini, circular);

      return mini;  
    }
};