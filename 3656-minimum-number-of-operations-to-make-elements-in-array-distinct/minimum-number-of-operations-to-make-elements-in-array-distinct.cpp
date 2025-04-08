class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
     
       unordered_map<int,int> mp;
        queue<int> q;
        for(int i=0; i<n; i++)
        {
            mp[nums[i]]++; 
            q.push(nums[i]);
        }


        int ans= 0;
        while(!q.empty())
        {
            bool duplicate= false;
            
             for(auto it: mp)
             {
                // if duplicate found...
                if(it.second > 1)
                {
                    duplicate= true;
                    break;
                }
             }

                 if(duplicate== false)
                 {
                     break;
                 }
                
                    int k= 3;
                    while(!q.empty() && k--)
                    {
                      int front= q.front();
                        q.pop();
                        mp[front]--;

                        if(mp[front]== 0)
                        {
                            mp.erase(front);
                        }
                    }
                ans++;
         }
       return ans; 
    }
};