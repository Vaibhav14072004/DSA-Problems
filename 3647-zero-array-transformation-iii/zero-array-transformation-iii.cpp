class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) 
    {
        sort(queries.begin(), queries.end());
        int queriesUsed=0,qi=0,qn=queries.size(),n=nums.size();
        vector<int>prefix(n+1,0);
        priority_queue<int>maxEnd;
        for(int i=0;i<n;i++)
        {
            prefix[i]+=(i>0)?prefix[i-1]:0;
            nums[i]-=prefix[i];
            while(qi<qn && queries[qi][0]<=i)
            {
                maxEnd.push(queries[qi][1]);
                qi++;
            }
            while(nums[i]>0 && !maxEnd.empty())
            {
                if(maxEnd.top()<i)
                   return -1;
                prefix[i]++;
                nums[i]--;
                prefix[maxEnd.top()+1]--;
                maxEnd.pop();
                queriesUsed++;  
            }
            if(nums[i]>0)
               return -1;
        }

        return qn-queriesUsed;
    }
};