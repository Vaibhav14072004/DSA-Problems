class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n= apple.size();
        int m= capacity.size();

        int sum= 0;
        for(int i=0; i<n; i++)
        {
            sum+= apple[i];
        }

        sort(capacity.rbegin(),capacity.rend());

        int curr= 0;
        for(int i=0; i<m; i++)
        {
            curr+= capacity[i];
            if(curr >= sum) 
            {
                return i+1;
            }  
        }
      return -1;  
    }
};